/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 12:06:16 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/24 12:51:28 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpushswap.h"
#include <stdio.h>

void		ps_debug(t_stack *s)
{
	int i;

	i = 0;
	while (i < s->max)
	{
		ft_putnbr(s->values[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	i = 0;
	while (i < s->start + s->pos)
	{
		ft_putstr("  ");
		i++;
	}
	ft_putchar('|');
	ft_putchar('\n');
	i = 0;
	while (i < s->start)
	{
		ft_putstr("  ");
		i++;
	}
	ft_putchar('I');
	ft_putchar('\n');
	printf("pos: %d\nsize: %d\nstart: %d\n\n", s->pos, s->size, s->start);
}
