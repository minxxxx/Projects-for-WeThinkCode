/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 14:36:30 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/23 15:13:46 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_nbr(char c)
{
	static char		*base1 = "0123456789abcdef";
	static char		*base2 = "0123456789ABCDEF";
	size_t			i;

	i = 0;
	while (base1[i] && base2[i])
	{
		if (base1[i] == c)
			return (i);
		if (base2[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, int base)
{
	long int	nbr;
	size_t		i;
	int			sign;
	int			t;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' && base == 10)
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((t = ft_find_nbr(str[i])) == -1)
			return (sign * nbr);
		nbr = nbr * base + t;
		i++;
	}
	return (sign * nbr);
}
