/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:04:48 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/07 21:04:50 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int a)
{
	unsigned int	b;

	b = 0;
	if (a < 0)
	{
		ft_putchar('-');
		b = -a;
	}
	else
		b = a;
	if (b >= 10)
	{
		ft_putnbr(b / 10);
		ft_putnbr(b % 10);
	}
	else
		ft_putchar(b + '0');
}
