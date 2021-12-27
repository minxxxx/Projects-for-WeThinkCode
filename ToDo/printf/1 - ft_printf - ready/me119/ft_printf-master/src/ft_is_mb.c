/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_mb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:59:40 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/06 11:59:41 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks if current character of a given string is a complete
** multibyte character.
** If there's only part of a mb char then it returns false.
** Otherwise returns number of characters read.
** (Works with single-byte characters as well)
** 1b - 0xxx xxxx (0 < s[i])
** 2b - 110x xxxx  10xx xxxx (s[i] < -32)
** 3b - 1110 xxxx  10xx xxxx  10xx xxxx (s[i] < -16)
** 4b - 1111 0xxx  10xx xxxx  10xx xxxx  10xx xxxx (s[i] < -8)
*/

static int	ft_is_n_bytes(char *str, int n)
{
	int		i;

	i = 1;
	while (str[i] && i < n)
	{
		if (str[i] >= -64)
			return (0);
		i++;
	}
	if (i == n)
		return (n);
	return (0);
}

int			ft_is_mb(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] > 0)
		return (1);
	else if (str[i] > -64 && str[i] < -32)
		return (ft_is_n_bytes(str, 2));
	else if (str[i] >= -32 && str[i] < -16)
		return (ft_is_n_bytes(str, 3));
	else if (str[i] >= -16 && str[i] < -8)
		return (ft_is_n_bytes(str, 4));
	else
		return (0);
}
