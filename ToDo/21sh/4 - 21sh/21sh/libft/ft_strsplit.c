/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 20:14:46 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/04 11:11:56 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	int		start;

	if (s == NULL|| (tab = (char **)malloc(sizeof(*tab) * \
					ft_count_words(s, c) + 1)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			start = i;
			while (s[i] != '\0'&& s[i] != c)
				i++;
			tab[j] = ft_strsub(s, start, i - start);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
