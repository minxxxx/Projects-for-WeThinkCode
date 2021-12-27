/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:06:32 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 16:31:53 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/ft_printf.h"

void	ft_putint(intmax_t nb, t_flag *flag)
{
	intmax_t	i;

	if (flag->comma != 0 && flag->cpy == 0 && flag->nbr == 0)
		return ;
	if (nb < 0)
	{
		ft_putchar('-', flag);
		i = -nb;
	}
	else
		i = nb;
	if (i > 9)
	{
		ft_putint(i / 10, flag);
		ft_putint(i % 10, flag);
	}
	else
		ft_putchar(i + '0', flag);
}
