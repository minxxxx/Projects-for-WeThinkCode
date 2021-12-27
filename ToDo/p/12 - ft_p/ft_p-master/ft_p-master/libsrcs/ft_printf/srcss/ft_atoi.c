/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:03:32 by jcamhi            #+#    #+#             */
/*   Updated: 2016/01/19 15:26:44 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_atoi(const char *nptr)
{
	int n;
	int signe;
	int result;

	n = 0;
	result = 0;
	signe = 1;
	while (nptr[n] == ' ' || nptr[n] == '\n' || nptr[n] == '\t'
			|| nptr[n] == '\r' || nptr[n] == '\v' || nptr[n] == '\f')
		n++;
	if (nptr[n] == '-')
	{
		signe = -1;
		n++;
	}
	else if (nptr[n] == '+')
		n++;
	while (nptr[n] > 47 && nptr[n] < 58)
	{
		result = result * 10 + (nptr[n] - 48);
		n++;
	}
	return (result * signe);
}
