/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 07:30:53 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:41:42 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

uint8_t		is_reverse_endian(uint32_t magic_num)
{
	if (magic_num == MH_CIGAM_64 || magic_num == MH_CIGAM ||
			magic_num == ELF_CIGAM || magic_num == FAT_CIGAM)
		return (1);
	return (0);
}

uint8_t		is_64_bit(uint32_t magic_num)
{
	if (magic_num == MH_CIGAM_64 || magic_num == MH_MAGIC_64)
		return (1);
	return (0);
}

uint8_t		is_mach_o_file(uint32_t magic_num)
{
	if (magic_num == MH_MAGIC_64 || magic_num == MH_CIGAM_64 ||
			magic_num == MH_MAGIC || magic_num == MH_CIGAM)
		return (1);
	return (0);
}

char		ft_get_type(char *segname, char *sectname, uint8_t is_global)
{
	if (!ft_strcmp(segname, "__TEXT") && !ft_strcmp(sectname, "__text"))
		return ((is_global) ? 'T' : 't');
	if (!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__data"))
		return ((is_global) ? 'D' : 'd');
	if (!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__bss"))
		return ((is_global) ? 'B' : 'b');
	if (!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__"))
		return ((is_global) ? 'T' : 't');
	return ((is_global) ? 'N' : 'n');
}
