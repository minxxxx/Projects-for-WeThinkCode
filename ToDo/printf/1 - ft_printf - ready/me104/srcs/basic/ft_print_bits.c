/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:36:28 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 18:14:15 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void		ft_print_bits(void *buf, t_flag *flag)
{
	char	*ptr;
	int		i;
	int		j;

	i = -1;
	ptr = (char*)buf;
	while (ptr[++i] != '\0' && (j = 8) == 8)
	{
		while (--j >= 0)
		{
			ft_putnbr_base((ptr[i] >> j) & 1, "0123456789ABCEDF", flag);
		}
	}
}

void		ft_print_adress(void *buf, t_flag *flag)
{
	char	*ptr;

	ptr = (char *)buf;
	ft_putnbr_base(ft_atoi(ptr), "0123456789ABCDEF", flag);
}
