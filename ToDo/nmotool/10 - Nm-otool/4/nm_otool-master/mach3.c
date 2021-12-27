/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 12:53:09 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:10:12 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mach.h"

int		mach_name_sort(t_sym *a, t_sym *b)
{
	if (ft_strcmp(a->name, b->name) > 0)
		return (1);
	return (0);
}

int		mach_value_sort(t_sym *a, t_sym *b)
{
	if (a->nlist->n_value > b->nlist->n_value)
		return (1);
	if ((N_TYPE & b->nlist->n_type) == 0x0 &&
			(N_TYPE & a->nlist->n_type) != 0x0)
		return (1);
	return (0);
}

void	print_value(uint32_t value, int size)
{
	static char	*str = "0123456789abcdefg";

	if (size > 0)
		print_value(value / 16, size - 1);
	write(1, &str[value % 16], 1);
}

void	print_value_64(uint64_t value, int size)
{
	static char	*str = "0123456789abcdefg";

	if (size > 0)
		print_value(value / 16, size - 1);
	write(1, &str[value % 16], 1);
}

void	mach_reverse_table(t_sym *tab, size_t size)
{
	size_t	i;
	size_t	half;
	t_sym	tmp;

	i = -1;
	half = size / 2;
	while (++i < half)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
	}
}
