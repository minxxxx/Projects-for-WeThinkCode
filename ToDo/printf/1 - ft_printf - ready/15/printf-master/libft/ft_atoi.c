/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:06:34 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/29 18:53:10 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	ret;
	int				sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (*str && ft_isdigit(*str))
	{
		if ((*str - '0') * 10 > 9223372036854775807 - ret)
			return (sign == -1 ? 0 : -1);
		ret = ret * 10 + (*str - '0');
		++str;
	}
	return (sign * (int)ret);
}
