/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:50:20 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/08 19:53:00 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;
	int		index;

	i = 0;
	index = 0;
	if (s1 != NULL && s2 != NULL)
	{
		fresh = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2));
		if (!fresh)
			return (NULL);
		while (s1[i] != '\0')
			fresh[index++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			fresh[index++] = s2[i++];
		fresh[index] = '\0';
		return (fresh);
	}
	return (NULL);
}
