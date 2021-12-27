/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 14:35:45 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/14 12:45:46 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_atol(const char *str)
{
	char			is_neg;
	long long int	result;
	size_t			i;

	i = 0;
	is_neg = 0;
	while (str[i] && ((str[i] >= 0 && str[i] < 33) || str[i] == 127))
		i++;
	if (str[i] == '-')
		is_neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	result = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i++] <= '9')
			result = result * 10 + str[i - 1] - '0';
		else
			return (is_neg ? -result : result);
	}
	return (is_neg ? -result : result);
}
