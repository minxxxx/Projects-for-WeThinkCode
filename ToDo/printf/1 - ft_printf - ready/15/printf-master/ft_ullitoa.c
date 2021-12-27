/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemiy <artemiy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 22:16:58 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/04 00:44:08 by artemiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static size_t	ft_ullnumlen(unsigned long long n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static void		ft_ullitoa_inner(unsigned long long n, size_t len, char *buf)
{
	char	*ptr;

	ptr = buf;
	while (len)
	{
		ptr[len - 1] = n % 10 + '0';
		n /= 10;
		--len;
	}
}

char			*ft_ullitoa(unsigned long long n)
{
	char	*newstr;
	size_t	len;

	len = ft_ullnumlen(n);
	if (n == 0)
		len = 1;
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	ft_ullitoa_inner(n, len, newstr);
	newstr[len] = '\0';
	return (newstr);
}
