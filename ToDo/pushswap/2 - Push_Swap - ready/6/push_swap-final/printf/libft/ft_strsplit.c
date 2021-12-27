/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:49:40 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/28 11:45:11 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	if (s[0] != '\0')
		j++;
	return (j);
}

static char	*ft_fill_tab(char const *s, char c, int *i)
{
	char	*str;
	int		j;

	j = 0;
	str = (char *)malloc(sizeof(str) * ft_strlen(s));
	if (str == NULL)
		return (0);
	while (s[*i] != c && s[*i])
	{
		str[j] = s[*i];
		j++;
		*i += 1;
	}
	str[j] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_words;
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = NULL;
	if (!s)
		return (0);
	nb_words = ft_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_words + 2));
	if (tab == NULL)
		return (0);
	while (s[i] == c && s[i])
		i++;
	while (j < nb_words && s[i])
	{
		tab[j] = ft_fill_tab(s, c, &i);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
