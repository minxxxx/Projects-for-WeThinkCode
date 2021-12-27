/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:49:36 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/18 10:49:37 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_words(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		while ((*str == ' ' || *str == '\n' || *str == '	') && *str != '\0')
			str++;
		if (*str != '\0')
			count++;
		while (*str > 32 && *str < 127)
			str++;
	}
	return (count);
}

static	int		count_len(char *str)
{
	int a;

	a = 0;
	while (*str > 32 && *str < 127 && str++)
		a++;
	return (a);
}

static	void	str_cp(char *s1, char *s2)
{
	while (*s2 > 32 && *s2 < 127)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

char			**ft_split(char *str)
{
	char	**ret;
	int		c_words;
	int		a;

	ret = NULL;
	c_words = count_words(str);
	a = 0;
	ret = (char**)malloc(sizeof(char*) * c_words + 1);
	ret[c_words] = NULL;
	while (a < c_words)
	{
		while (*str == ' ' || *str == '\n' || *str == '	')
			str++;
		if (*str != '\0')
		{
			ret[a] = (char*)malloc(sizeof(char) * (count_len(str) + 1));
			str_cp(ret[a], str);
		}
		while (*str > 32 && *str < 127)
			str++;
		a++;
	}
	return (ret);
}
