/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:39:01 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/11 17:13:37 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(int n)
{
	int		count;

	count = 1;
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_do_neg(int n)
{
	int		size;
	char	*str;

	n = n * -1;
	size = ft_count(n) + 1;
	str = ft_strnew(size);
	size--;
	while (n != 0)
	{
		str[size] = '0' + (n % 10);
		size--;
		n = n / 10;
	}
	str[size] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	if (n >= 0)
	{
		size = ft_count(n);
		str = ft_strnew(size);
		size--;
		while (n != 0)
		{
			str[size] = '0' + (n % 10);
			size--;
			n = n / 10;
		}
		return (str);
	}
	else
		str = ft_do_neg(n);
	return (str);
}
