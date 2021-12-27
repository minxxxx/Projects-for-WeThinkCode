/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_fat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:05:12 by jtranchi          #+#    #+#             */
/*   Updated: 2018/02/26 22:53:09 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void		find_fat_32(void *ptr)
{
	int					i;
	int					narch;
	struct fat_header	*fat;
	struct fat_arch		*arch;

	i = -1;
	fat = (struct fat_header*)ptr;
	narch = reverse_endian(fat->nfat_arch);
	arch = (struct fat_arch*)(fat + 1);
	while (++i < (int)narch)
	{
		if (reverse_endian(arch->cputype) == CPU_TYPE_X86_64 ||
		reverse_endian(arch->cputype) == CPU_TYPE_X86)
		{
			nm(ptr + reverse_endian(arch->offset));
			return ;
		}
		arch = arch + 1;
	}
}

void		find_fat_64(void *ptr)
{
	int					i;
	int					narch;
	struct fat_header	*fat;
	struct fat_arch_64	*arch;

	i = -1;
	fat = (struct fat_header*)ptr;
	narch = reverse_endian(fat->nfat_arch);
	arch = (struct fat_arch_64*)(fat + 1);
	while (++i < (int)narch)
	{
		if (reverse_endian(arch->cputype) == CPU_TYPE_X86_64 ||
		reverse_endian(arch->cputype) == CPU_TYPE_X86)
		{
			nm(ptr + reverse_endian(arch->offset));
			return ;
		}
		arch = arch + 1;
	}
}
