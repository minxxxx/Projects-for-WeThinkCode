/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 12:58:07 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/21 13:04:25 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putstrarr(char const **source, size_t length)
{
	size_t		i;

	i = 0;
	while (i < length)
	{
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("::");
		ft_putstr(source[i]);
		ft_putchar(']');
		i++;
	}
}
