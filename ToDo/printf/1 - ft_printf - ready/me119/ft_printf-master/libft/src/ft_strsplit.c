/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:40:20 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/10 12:55:41 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_word_count(const char *s, char c)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	i = 0;
	j = 0;
	if (s)
	{
		if ((str = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1))))
		{
			while (j < ft_word_count(s, c))
			{
				while (s[i] && s[i] == c)
					i++;
				count = i;
				while (s[i] && s[i] != c)
					i++;
				str[j++] = ft_strsub(s, count, i - count);
			}
			str[j] = 0;
		}
		return (str);
	}
	return (0);
}
