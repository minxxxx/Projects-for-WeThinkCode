/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:09:31 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:09:31 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strsplit_count_word(char *s, char c)
{
	size_t	count;

	count = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static	size_t	ft_strsplit_count_len(char *s, char c)
{
	size_t countc;

	countc = 0;
	while (*s && *s != c)
	{
		countc++;
		s++;
	}
	return (countc);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	countc;
	size_t	count;
	size_t	a;

	countc = 0;
	a = 0;
	if (!s)
		return (NULL);
	count = ft_strsplit_count_word((char*)s, c);
	if (!(new = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	while (a < count)
	{
		countc = 0;
		while (s && *s && *s == c)
			s++;
		countc = ft_strsplit_count_len((char*)s, c);
		new[a] = ft_strsub(s, 0, countc);
		while (s && *s && *s != c)
			s++;
		a++;
	}
	new[a] = NULL;
	return (new);
}
