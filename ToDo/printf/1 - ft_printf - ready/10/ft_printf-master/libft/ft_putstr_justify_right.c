/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_justify_right.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 17:59:02 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 16:00:33 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putstr_justify_right(char *string
											, size_t total
											, char fill)
{
	size_t			length;
	size_t			i;

	length = ft_strlen(string);
	i = 0;
	while (i + length < total)
	{
		ft_putchar(fill);
		i++;
	}
	ft_putstr(string);
}
