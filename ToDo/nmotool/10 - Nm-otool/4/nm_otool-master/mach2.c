/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:12:17 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:08:42 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mach.h"

void	mach_sort_symbols(t_sym *syms, size_t size, int (*f)(t_sym *, t_sym *))
{
	int		j;
	t_sym	tmp;

	if (size < 2)
		return ;
	mach_sort_symbols(syms, size - 1, f);
	tmp = syms[size];
	j = size - 1;
	while (j >= 0 && f(&syms[j], &tmp))
	{
		syms[j + 1] = syms[j];
		j -= 1;
	}
	syms[j + 1] = tmp;
}

void	check_sorts(t_flags *flags, t_sym *syms, size_t size)
{
	if (flags->no_sort)
		return ;
	if (flags->addr_sort)
		mach_sort_symbols(syms, size - 1, &mach_value_sort);
	else
		mach_sort_symbols(syms, size - 1, &mach_name_sort);
	if (flags->rev_sort)
		mach_reverse_table(syms, size);
}

void	print_value_type(t_sym *sym, uint8_t is_64)
{
	if ((N_TYPE & sym->nlist->n_type) == 0xe)
		print_value(sym->nlist->n_value, (is_64) ? 15 : 7);
	else if (is_64)
		ft_putstr("                ");
	else
		ft_putstr("        ");
	ft_putstr(" ");
	ft_putchar(sym->type);
	ft_putstr(" ");
}

void	process_syms(t_mach_file *mach, t_sym *syms, size_t size)
{
	size_t	i;

	i = -1;
	check_sorts(mach->flags, syms, size);
	while (++i < size)
	{
		if (mach->flags->global_only && !(N_EXT & syms[i].nlist->n_type))
			continue ;
		if (mach->flags->undef_only && (N_TYPE & syms[i].nlist->n_type) == 0xe)
			continue ;
		if (mach->flags->print_file_name)
		{
			ft_putstr(mach->flags->file_name);
			ft_putstr(": ");
		}
		if (!mach->flags->undef_only)
			print_value_type(&syms[i], mach->is_64);
		ft_putendl(syms[i].name);
	}
}
