/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:33:09 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/23 16:01:43 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	size_t		slen;

	slen = ft_strlen(s);
	ch = (char)c;
	while (slen || s[slen] == ch)
	{
		if (s[slen] == ch)
			return ((char *)s + slen);
		--slen;
	}
	return (NULL);
}
