/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:39:36 by dtedgui           #+#    #+#             */
/*   Updated: 2016/02/01 18:57:31 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base, int uppercase)
{
	char	*str;
	int		i;
	int		length;

	if (base < 2 || base > 16 || (base != 10 && n < 0))
		return (NULL);
	if (base == 10)
		return (ft_itoa(n));
	length = ft_nbrlen(n, base);
	str = (char*)malloc(sizeof(*str) * (length + 1));
	i = 0;
	while (i < length)
	{
		if (base > 10 && (n % base >= 10) && uppercase)
			str[i++] = (n % base) - 10 + 'A';
		else if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + 'a';
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
