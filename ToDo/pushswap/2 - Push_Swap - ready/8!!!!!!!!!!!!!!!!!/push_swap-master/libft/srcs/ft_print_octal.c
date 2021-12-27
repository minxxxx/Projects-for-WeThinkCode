/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:20:24 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/24 16:20:25 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_octal(size_t nb)
{
	char	*tab;

	tab = "01234567";
	if (nb < 8)
		ft_putchar(tab[nb]);
	if (nb >= 8)
	{
		ft_print_octal(nb / 8);
		ft_putchar(tab[nb % 8]);
	}
}
