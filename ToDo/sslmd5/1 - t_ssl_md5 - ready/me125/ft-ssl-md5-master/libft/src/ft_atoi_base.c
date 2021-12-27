/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:55:17 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 09:55:17 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_ret(char c)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef\0";
	while (i < 16)
	{
		if (c == hex[i] || c + 32 == hex[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(char *str, int base)
{
	int	p;
	int	i;
	int	ret;

	i = 0;
	p = 0;
	if (str[i] == '0')
		i++;
	if (str[i] == 'x' || str[i] == 'X')
		i++;
	while (ft_isdigit(str[i]) || HEXCHAR || HEXSYMB)
	{
		if ((ret = get_ret(str[i])) == -1)
			return (0);
		p = base * p + ret % base;
		i++;
	}
	return (p);
}
