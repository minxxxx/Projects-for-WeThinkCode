/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:31:59 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:32:01 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count_words(char const *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		i++;
	}
	if (str[0] != '\0')
		count++;
	return (count);
}

static char			*get_word(char const *str, char c, int *i)
{
	int		k;
	char	*s;

	k = 0;
	while (str[*i + k] != c && str[*i + k])
		k++;
	s = (char *)malloc(sizeof(char) * (k + 1));
	if (!s)
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	word = count_words(s, c);
	str = (char **)malloc(sizeof(str) * (word + 2));
	if (!str)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < word && s[i])
	{
		str[j] = get_word(s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
