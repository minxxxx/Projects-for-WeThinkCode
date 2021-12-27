/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:37:54 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/14 15:12:02 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(intmax_t nb)
{
	size_t	size;

	size = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char			*ft_itoa(intmax_t n)
{
	intmax_t	nb;
	char		*str;
	size_t		size;

	nb = n;
	size = ft_size(nb);
	if (n == 0)
		str = ft_strdup("0");
	else
		str = ft_strnew(size);
	if (str == 0)
		return (0);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0 && str)
	{
		str[size - 1] = '0' + (nb % 10);
		size--;
		nb /= 10;
	}
	return (str);
}
