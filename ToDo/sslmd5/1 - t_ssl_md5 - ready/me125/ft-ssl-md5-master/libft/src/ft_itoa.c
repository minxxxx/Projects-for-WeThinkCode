/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:11:01 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:11:02 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 10)
	{
		n /= 10;
		i++;
	}
	if (n < 10)
		i++;
	return (i);
}

static void	ft_itoa_record(char *str, int n, int *i)
{
	unsigned int m;

	m = n;
	if (n < 0)
	{
		str[*i] = '-';
		*i = (*i) + 1;
		m = -n;
	}
	if (m >= 10)
	{
		ft_itoa_record(str, m / 10, i);
		ft_itoa_record(str, m % 10, i);
	}
	if (m < 10)
	{
		str[*i] = m + '0';
		*i = (*i) + 1;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		a;
	int		*i;

	i = &a;
	a = 0;
	str = (char*)malloc(sizeof(char) * (ft_itoa_count(n) + 1));
	if (str)
	{
		ft_itoa_record(str, n, i);
		str[a] = '\0';
	}
	return (str);
}
