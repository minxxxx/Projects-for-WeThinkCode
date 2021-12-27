/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:20:16 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/24 16:20:17 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_hex(size_t nb, int upper)
{
	char	*tab;

	if (upper == 1)
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_print_hex(nb / 16, upper);
		ft_putchar(tab[nb % 16]);
	}
}
