/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 07:00:04 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:43:42 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	process_mach_file(t_file *file, t_flags *flags, size_t off)
{
	t_mach_file		mach;
	uint32_t		i;

	mach.file_data = file->data + off;
	mach.is_rev = is_reverse_endian(file->file_magic);
	mach.is_64 = is_64_bit(file->file_magic);
	mach.magic = file->file_magic;
	mach.mach_data = file->data + off;
	mach.flags = flags;
	mach.header = (t_mach_header *)((char *)mach.mach_data);
	off += (mach.is_64) ? 32 : 28;
	mach.cmd_data = file->data + off;
	if (mach.is_rev)
		rev_bytes(&mach.header->ncmds, 4);
	i = -1;
	if (mach.is_rev)
		rev_mach_cmds(&mach, file, off);
	while (++i < mach.header->ncmds)
	{
		mach.sym_tab = (t_mach_sym *)(file->data + off);
		if (mach.sym_tab->cmdtype == MH_SYMTAB)
			break ;
		off += mach.sym_tab->cmdsize;
	}
	mach_symbol_table(&mach);
}

void	process_fat_file(t_file *file, t_flags *flags, size_t off)
{
	t_fat_header	*header;
	t_fat_arch		*arch;
	uint32_t		i;
	uint32_t		fat_magic;

	fat_magic = file->file_magic;
	header = (t_fat_header *)(file->data + off);
	if (is_reverse_endian(fat_magic))
		rev_bytes(&header->nfat_arch, 4);
	i = -1;
	off += sizeof(t_fat_header);
	while (++i < header->nfat_arch)
	{
		arch = (t_fat_arch *)(file->data + off);
		if (is_reverse_endian(fat_magic))
			rev_bytes(&arch->offset, 4);
		file->file_magic = *((uint32_t *)(file->data + arch->offset));
		if (is_mach_o_file(*((uint32_t *)(file->data + arch->offset))))
			process_mach_file(file, flags, arch->offset);
		off += sizeof(t_fat_arch);
	}
}

void	process_arch_file(t_file *file, t_flags *flags, size_t namelen,
		size_t off)
{
	t_arch_header	*h;
	char			*filename;
	char			*libname;

	off = 8;
	libname = flags->file_name;
	filename = ft_strjoin(flags->file_name, ":");
	while (off < file->size)
	{
		h = (t_arch_header *)(file->data + off);
		off += sizeof(t_arch_header);
		namelen = ft_atoi(&h->file_iden[3]);
		flags->file_name = ft_strjoin(filename, file->data + off);
		file->file_magic = *((uint32_t *)(file->data + off + namelen));
		if (is_mach_o_file(file->file_magic) || file->file_magic == FAT_MAGIC
				|| file->file_magic == FAT_CIGAM)
		{
			file->is_archive = 0;
			printf("\n%s(%s):\n", libname, file->data + off);
			process_file(file, flags, off, 0);
		}
		ft_strdel(&flags->file_name);
		off += ft_atoi(h->file_size);
	}
	flags->file_name = filename;
}

void	process_file(t_file *file, t_flags *flags, uint32_t off,
		int multiple)
{
	if (multiple)
	{
		ft_putstr(flags->file_name);
		ft_putendl(":");
	}
	if (file->is_archive)
		process_arch_file(file, flags, 0, off);
	else if (is_mach_o_file(file->file_magic))
		process_mach_file(file, flags, off);
	else if (file->file_magic == FAT_CIGAM || file->file_magic == FAT_MAGIC)
		process_fat_file(file, flags, off);
}
