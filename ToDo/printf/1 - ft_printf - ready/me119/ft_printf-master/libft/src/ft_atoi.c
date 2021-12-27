/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:51:20 by opodolia          #+#    #+#             */
/*   Updated: 2017/02/02 19:00:13 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		rt;
	int		neg;

	rt = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\f' || *str == '\r' ||
			*str == '\n' || *str == '\v')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	if (*str == '+' && neg == -1)
		return (0);
	if (*str == '+')
		str++;
	while (str != '\0' && *str >= '0' && *str <= '9')
	{
		rt *= 10;
		rt += *str - '0';
		str++;
	}
	return (rt * neg);
}
