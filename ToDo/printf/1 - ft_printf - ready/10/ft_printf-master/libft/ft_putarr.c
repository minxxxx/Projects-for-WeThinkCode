/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:01:50 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/28 17:01:53 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putarr(void const **source, size_t length, t_printer printer)
{
	size_t		i;

	i = 0;
	while (i < length)
	{
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("::");
		printer(source[i]);
		ft_putchar(']');
		i++;
	}
}
