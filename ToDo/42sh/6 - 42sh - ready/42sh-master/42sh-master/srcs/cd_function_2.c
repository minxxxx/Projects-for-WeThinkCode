/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_function_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static char	*str_range_dup(char *str, int n)
{
	char	*new_str;
	int		i;

	i = 0;
	if ((new_str = (char *)mallocp(sizeof(char) * (n + 1))))
	{
		while (i < n)
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}

static char	*move_into_substring(char *str, char c, int match)
{
	if (match)
	{
		while (*str == c)
			str++;
	}
	else
	{
		while (*str && *str != c)
			str++;
	}
	return (str);
}

static int	get_next_sep(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char		**ft_lz_strsplit(char *str, char c)
{
	char	**split;
	int		nb_str;
	int		i;
	int		range;

	nb_str = ft_count_string(str, c);
	i = 0;
	if ((split = (char **)mallocp(sizeof(char *) * (nb_str + 1))))
	{
		while (i < nb_str)
		{
			if (i != 0)
				str = move_into_substring(str, c, 1);
			range = get_next_sep(str, c);
			split[i] = str_range_dup(str, range);
			str = move_into_substring(str, c, 0);
			i++;
		}
		split[nb_str] = NULL;
	}
	return (split);
}

size_t		ft_nstrlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s && s[i])
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}
