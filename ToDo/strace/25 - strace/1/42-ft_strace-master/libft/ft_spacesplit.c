/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacesplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <jmontija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 22:25:15 by jmontija          #+#    #+#             */
/*   Updated: 2016/11/22 21:11:45 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int				is_space(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

static int		ft_cnt_parts(const char *s)
{
	int		cnt;
	int		synth;
	int		in_substring;

	in_substring = 0;
	cnt = 0;
	synth = 0;
	while (*s != '\0')
	{
		synth = check_parentheses(*s);
		if (synth == 0 && in_substring == 1 && is_space(*s))
			in_substring = 0;
		if (in_substring == 0 && !is_space(*s))
		{
			in_substring = 1;
			cnt++;
		}
		s++;
	}
	check_parentheses(0);
	return (cnt);
}

static int		ft_wlen(const char *s)
{
	int		len;
	int		synth;

	len = 0;
	synth = 0;
	while (*s != '\0')
	{
		synth = check_parentheses(*s);
		if (synth == 0 && is_space(*s))
			break ;
		len++;
		s++;
	}
	check_parentheses(0);
	return (len);
}

char			**ft_spacesplit(char const *s)
{
	char	**t;
	int		nb_word;
	int		index;

	index = 0;
	check_parentheses(0);
	nb_word = ft_cnt_parts((const char *)s);
	t = (char **)malloc(sizeof(*t) * (nb_word + 1));
	if (t == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (is_space(*s) && *s != '\0')
			s++;
		t[index] = ft_strsub((const char *)s, 0, ft_wlen((const char *)s));
		if (t[index] == NULL)
			return (NULL);
		s = s + ft_wlen(s);
		index++;
	}
	t[index] = NULL;
	check_parentheses(0);
	return (t);
}
