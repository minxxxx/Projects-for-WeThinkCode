/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:48:41 by thou              #+#    #+#             */
/*   Updated: 2016/11/18 17:19:07 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *a, char c)
{
	int		len;
	char	*s;

	len = 0;
	s = (char*)a;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	*a;
	int		i;
	char	**tab;

	a = (char*)s;
	i = 0;
	if (!a)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * (ft_wordnb(a, c) + 1));
	if (!tab)
		return (NULL);
	while (i < ft_wordnb(s, c))
	{
		while (*a == c)
			a++;
		if (*a != c && *a)
			tab[i++] = ft_strsub(a, 0, ft_wordlen(a, c));
		while (*a != c && *a)
			a++;
	}
	tab[i] = 0;
	return (tab);
}
