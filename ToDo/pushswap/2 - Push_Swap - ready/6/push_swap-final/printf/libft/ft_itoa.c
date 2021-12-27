/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:54:05 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/22 17:15:58 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count++);
}

static void	ft_fill(char *s, int n, int len)
{
	s[len] = '\0';
	len--;
	while (len >= 0)
	{
		s[len] = (n % 10) + '0';
		len--;
		n /= 10;
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		neg;

	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		neg += 1;
	}
	ft_fill(s, n, len);
	if (neg > 0)
		s[0] = '-';
	return (s);
}
