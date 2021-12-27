/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 23:03:48 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/26 09:14:07 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	int_len(unsigned long long int n)
{
	size_t		len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void		ft_reverse(char *s)
{
	char		*start;
	char		*end;
	char		*cpy;
	char		tmp;

	cpy = s;
	start = cpy;
	while (*cpy)
		cpy++;
	end = cpy - 1;
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

static char		*zero_case(char *s)
{
	char		*cpy;

	cpy = s;
	*cpy++ = '0';
	*cpy = '\0';
	return (s);
}

char			*ft_itoa_unsigned(unsigned long long int n)
{
	char		*s;
	char		*cpy;

	s = (char*)malloc((sizeof(char) * int_len(n)) + 2);
	if (n == 0 || n == -0)
		return (zero_case(s));
	if (s == NULL)
		return (NULL);
	cpy = s;
	while (n)
	{
		*cpy++ = (n % 10) + '0';
		n /= 10;
	}
	*cpy = '\0';
	ft_reverse(s);
	return (s);
}
