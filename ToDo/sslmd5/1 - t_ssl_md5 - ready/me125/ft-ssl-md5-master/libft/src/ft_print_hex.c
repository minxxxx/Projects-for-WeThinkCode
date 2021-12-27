/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:16:11 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/18 11:16:11 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex(int dc)
{
	if (dc < 0)
	{
		ft_putchar('\n');
		return ;
	}
	else if (dc > 15)
	{
		ft_print_hex(dc / 16);
		ft_print_hex(dc % 16);
	}
	else
	{
		if (dc > 9)
			ft_putchar(dc + 87);
		else
			ft_putchar(dc + 48);
	}
}
