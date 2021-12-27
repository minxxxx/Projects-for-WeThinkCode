/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:43:00 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/14 15:30:03 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(uintmax_t val, int base)
{
	int		size;

	if (val == 0)
		return (1);
	size = 0;
	while (val)
	{
		val /= base;
		size++;
	}
	return (size);
}

char		*ft_uitoa_base(uintmax_t val, int base, char c)
{
	char	*str;
	char	*bs;
	int		size;

	bs = (c <= 'Z') ? "0123456789ABCDEF" : "0123456789abcdef";
	size = ft_size(val, base);
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	if (val == 0)
		str[0] = '0';
	while (val > 0)
	{
		str[--size] = bs[val % base];
		val /= base;
	}
	return (str);
}
