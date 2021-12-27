/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:55:17 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 09:55:17 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_check_hex(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
			i++;
		else if ((str[i] >= 'a') && (str[i] <= 'f'))
			i++;
		else if ((str[i] >= 'A') && (str[i] <= 'F'))
			i++;
		else
			return (0);
	}
	return (1);
}

int				ft_check_hex_char(char c)
{
	if (((c >= '0') && (c <= '9')) ||
		((c >= 'a') && (c <= 'f')) ||
		((c >= 'A') && (c <= 'F')) ||
		(c == 'x') || (c == 'X'))
		return (1);
	return (0);
}
