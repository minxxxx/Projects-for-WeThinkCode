/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:06:32 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 16:32:04 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/ft_printf.h"

void	ft_putshort(short int nb, t_flag *flag)
{
	unsigned short int	i;

	if (nb < 0)
	{
		ft_putchar('-', flag);
		i = -nb;
	}
	else
		i = nb;
	if (i > 9)
	{
		ft_putshort(i / 10, flag);
		ft_putshort(i % 10, flag);
	}
	else
		ft_putchar(i + '0', flag);
}
