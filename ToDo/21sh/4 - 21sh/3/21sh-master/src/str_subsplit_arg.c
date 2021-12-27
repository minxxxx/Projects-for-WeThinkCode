/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_subsplit_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 15:21:55 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/22 19:09:10 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	count_arg_part(char const *s, int i, int n)
{
	int		save;
	char	c;

	save = 0;
	while (s[i])
	{
		if (ft_isquote(s[i]) && (i == 0 || s[i - 1] != '\\'))
		{
			save = i;
			c = s[i++];
			while (s[i] && ((s[i] != c || (s[i] == c && s[i - 1] == '\\'))))
				i++;
			s[i++] ? n++ : (i = save + 1);
		}
		else
		{
			if (i != (save + 1))
				n++;
			while (s[i] && (!ft_isquote(s[i])
				|| (ft_isquote(s[i]) && s[i - 1] == '\\')))
				i++;
		}
	}
	return (n);
}

static int	arg_part_len(char const *s, int i)
{
	int		save;
	char	c;

	c = 0;
	if (!s[i])
		return (i);
	if (ft_isquote(s[i]) && (i == 0 || s[i - 1] != '\\'))
	{
		c = s[i++];
		save = i;
		while (s[i] && ((s[i] != c || (s[i] == c && s[i - 1] == '\\'))))
			i++;
		i = s[i] ? i + 1 : arg_part_len(s, save);
	}
	else
	{
		while (s[i] && (!ft_isquote(s[i])
			|| (ft_isquote(s[i]) && s[i - 1] == '\\')))
			i++;
	}
	return (i);
}

char		**str_subsplit_arg(char const *s)
{
	int		i;
	int		j;
	int		nb_arg_part;
	int		start;
	char	**ret;

	i = 0;
	j = 0;
	nb_arg_part = count_arg_part(s, 0, 0);
	if (!(ret = (char **)malloc(sizeof(char *) * (nb_arg_part + 1))))
		quit_error(9);
	while (s[i])
	{
		start = i;
		i = arg_part_len(s, start);
		if (start != i)
			ret[j++] = ft_strsub(s, start, (i - start));
	}
	ret[j] = NULL;
	return (ret);
}
