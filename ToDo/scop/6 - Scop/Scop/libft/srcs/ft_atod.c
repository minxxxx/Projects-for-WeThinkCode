/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:45:45 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/14 12:45:46 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_floating_value(char *str)
{
	double	divisor;
	double	value;
	size_t	i;

	value = 0;
	i = 0;
	divisor = 10;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			value += (double)(str[i] - '0') / divisor;
		else
			return (value);
		divisor *= 10;
		i++;
	}
	return (value);
}

double			ft_atod(const char *str)
{
	size_t	end;
	size_t	i;
	char	*integer_part;
	int		integer_value;
	double	floating_value;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	end = i;
	integer_part = ft_strsub(str, 0, end);
	integer_value = ft_atoi(integer_part);
	free(integer_part);
	floating_value = get_floating_value(((char *)str) + end + 1);
	return (integer_value +
			(str[0] == '-' ? -floating_value : floating_value));
}
