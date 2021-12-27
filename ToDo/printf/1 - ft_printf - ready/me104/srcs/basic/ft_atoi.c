/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 12:47:00 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 16:30:30 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	a;
	int	c;
	int	d;

	a = 0;
	i = -1;
	c = 1;
	d = 0;
	while (str[++i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			a = 1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		d = (d * c) + (str[i++] - 48);
		c = 10;
	}
	if (a == 0)
		return (d);
	else if (a == 1)
		return (-d);
	return (0);
}
