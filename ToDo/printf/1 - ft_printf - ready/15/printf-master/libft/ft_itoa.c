/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:18:23 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/29 20:55:34 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_numlen(long long int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		++len;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static void		ft_itoa_inner(long long int n, size_t len, char *buf)
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

char			*ft_itoa(int n)
{
	char			*newstr;
	size_t			len;
	int				sign;
	long long int	ln;

	sign = n < 0 ? 1 : 0;
	ln = (long long int)n;
	len = ft_numlen(ln);
	if (ln == 0)
		len = 1;
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	if (sign)
		ln *= -1;
	ft_itoa_inner(ln, len, newstr);
	if (sign)
		newstr[0] = '-';
	newstr[len] = '\0';
	return (newstr);
}
