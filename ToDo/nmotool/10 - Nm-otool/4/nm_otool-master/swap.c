/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:59:08 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:40:37 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	rev_bytes(void *data, size_t size)
{
	unsigned char	*a;
	unsigned char	tmp;
	size_t			half;
	size_t			i;

	i = -1;
	half = size / 2;
	a = (unsigned char *)data;
	while (++i < half)
	{
		tmp = a[i];
		a[i] = a[size - i - 1];
		a[size - i - 1] = tmp;
	}
}

void	rev_mach_cmds(t_mach_file *mach, t_file *file, size_t off)
{
	uint32_t	i;

	i = -1;
	ft_putendl("rev cmds");
	while (++i < mach->header->ncmds)
	{
		my_print_memory(file->data + off + 1, 8);
		rev_bytes(file->data + off, 4);
		rev_bytes(file->data + off + 4, 4);
		off += *((uint32_t *)(file->data + off + 4));
	}
}

void	rev_symtab(t_mach_sym *tab)
{
	rev_bytes(&tab->stroff, 4);
	rev_bytes(&tab->symoff, 4);
	rev_bytes(&tab->nsyms, 4);
	rev_bytes(&tab->strsize, 4);
}
