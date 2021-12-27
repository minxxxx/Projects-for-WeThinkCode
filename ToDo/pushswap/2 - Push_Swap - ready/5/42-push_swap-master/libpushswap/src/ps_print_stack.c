/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 09:24:12 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/24 09:59:12 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "colors.h"
#include "libpushswap.h"

void		ps_print_stack(t_stack *s, int hl, int hl2)
{
	int i;

	i = 0;
	while (i < s->size)
	{
		if (i == hl || i == hl2)
			ft_putstr(C_RED);
		ft_putnbr(ps_get(s, i));
		ft_putchar(' ');
		if (i == hl || i == hl2)
			ft_putstr(C_RESET);
		i++;
	}
	ft_putchar('\n');
}
