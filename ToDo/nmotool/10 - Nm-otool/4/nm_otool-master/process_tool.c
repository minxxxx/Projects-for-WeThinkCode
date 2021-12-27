/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 02:53:54 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:44:11 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	otool_mach_file(t_file *file, t_otool_flags *flags, size_t off)
{
	t_mach_file	mach;

	mach.file_data = file->data + off;
	mach.is_rev = is_reverse_endian(file->file_magic);
	mach.is_64 = is_64_bit(file->file_magic);
	mach.magic = file->file_magic;
	mach.mach_data = file->data + off;
	mach.header = (t_mach_header *)((char *)mach.mach_data);
	off += (mach.is_64) ? 32 : 28;
	mach.cmd_data = file->data + off;
	if (mach.is_rev)
		rev_bytes(&mach.header->ncmds, 4);
	if (mach.is_rev)
		rev_mach_cmds(&mach, file, off);
	print_otool_sec_head(flags);
	if (flags->text_sec && !mach.is_64)
		otool_section_32(&mach, "__text", "__TEXT", 0);
	else if (flags->text_sec && mach.is_64)
		otool_section_64(&mach, "__text", "__TEXT", 0);
	if (flags->data_sec && !mach.is_64)
		otool_section_32(&mach, "__data", "__DATA", 0);
	else if (flags->data_sec && mach.is_64)
		otool_section_64(&mach, "__data", "__DATA", 0);
	if (flags->mach_head)
		my_print_mach_header(mach.header, mach.is_rev);
}

void	otool_fat_file(t_file *file, t_otool_flags *flags, size_t off)
{
	t_fat_header	*header;
	t_fat_arch		*arch;
	uint32_t		i;
	uint32_t		fat_magic;

	fat_magic = file->file_magic;
	header = (t_fat_header *)(file->data + off);
	if (is_reverse_endian(fat_magic))
		rev_bytes(&header->nfat_arch, 4);
	i = 0;
	off += sizeof(t_fat_header);
	if (flags->fat_head)
		my_print_fat_header((unsigned char *)header, 0,
				is_reverse_endian(fat_magic));
	while (i < header->nfat_arch)
	{
		arch = (t_fat_arch *)(file->data + off);
		if (is_reverse_endian(fat_magic) && !flags->fat_head)
			rev_bytes(&arch->offset, 4);
		file->file_magic = *((uint32_t *)(file->data + arch->offset));
		if (is_mach_o_file(*((uint32_t *)(file->data + arch->offset))))
			otool_mach_file(file, flags, arch->offset);
		off += sizeof(t_fat_arch);
		i++;
	}
}

void	process_otool_file(t_file *file, t_otool_flags *flags, uint32_t off)
{
	if (is_mach_o_file(file->file_magic))
		otool_mach_file(file, flags, off);
	else if (file->file_magic == FAT_CIGAM || file->file_magic == FAT_MAGIC)
		otool_fat_file(file, flags, off);
}
