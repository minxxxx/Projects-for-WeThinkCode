/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 05:29:57 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/09 06:33:50 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(uintmax_t val, int base)
{
	unsigned int	size;

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

char		*ft_ftoa_base(uintmax_t val, int base, char c, int digits)
{
	char	*str;
	char	*bs;
	int		size;
	int		i;

	bs = (c <= 'Z') ? "0123456789ABCDEF" : "0123456789abcdef";
	size = ft_size(val, base);
	str = (char *)malloc(sizeof(char) * (MAX(size, digits) + 1));
	i = 0;
	while (val != 0 || (i == 0 && digits != 0) || i < digits)
	{
		str[i++] = bs[val % base];
		val /= base;
	}
	str[i] = 0;
	ft_strrev(str);
	return (str);
}
