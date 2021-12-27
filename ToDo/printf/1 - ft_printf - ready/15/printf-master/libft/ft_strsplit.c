/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:14:32 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/30 14:43:10 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_substr(char const *s, char c)
{
	size_t			count;
	char const		*ptr;

	count = 0;
	while (*s)
	{
		ptr = s;
		while (*s != c && *s)
			s++;
		if (ptr < s)
			count++;
		while (*s == c && *s)
			s++;
	}
	return (count);
}

static void		ft_del_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

static char		*ft_append_str(char **tab, char const *s, unsigned int s_len, \
								unsigned int *i)
{
	tab[*i] = (char *)malloc(sizeof(char) * s_len + 1);
	if (!tab[*i])
	{
		ft_del_tab(tab);
		return (NULL);
	}
	ft_strncpy(tab[*i], s - s_len, s_len);
	tab[*i][s_len] = '\0';
	*i += 1;
	return (tab[*i - 1]);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**tab;
	char const		*ptr;
	unsigned int	count;

	if (!s)
		return (NULL);
	count = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count_substr(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		ptr = s;
		while (*s != c && *s)
			++s;
		if (ptr < s)
		{
			if (!(tab[count] = ft_append_str(tab, s, s - ptr, &count)))
				return (NULL);
		}
		while (*s == c && *s)
			s++;
	}
	tab[count] = NULL;
	return (tab);
}
