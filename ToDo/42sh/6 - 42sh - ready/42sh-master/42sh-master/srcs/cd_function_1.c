/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_function_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

char		*strdup_skip(char *str)
{
	size_t	len;
	int		i;
	int		t;
	char	*dup;

	i = 0;
	t = 0;
	len = ft_strlen(str);
	if ((dup = (char *)mallocp(sizeof(char) * (len + 1))))
	{
		while (str[i])
		{
			if (ft_strncmp("//", &str[i], 2))
			{
				dup[t] = str[i];
				t++;
			}
			i++;
		}
		dup[t] = '\0';
	}
	return (dup);
}

void		ft_str2del(char **array)
{
	int i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

char		*triple_join(char *s1, char *s2, char *s3)
{
	char	*final;
	int		i;

	i = 0;
	if ((final = (char *)mallocp(sizeof(char) * ft_nstrlen(s1) +
								ft_nstrlen(s2) + ft_nstrlen(s3) + 1)))
	{
		while (*s1)
		{
			final[i++] = *s1;
			s1++;
		}
		while (*s2)
		{
			final[i++] = *s2;
			s2++;
		}
		while (s3 && *s3)
		{
			final[i++] = *s3;
			s3++;
		}
		final[i] = '\0';
	}
	return (final);
}

char		*join_slash(char **s)
{
	int		i;
	char	*tmp;
	char	*str;

	str = ft_strjoin("/", s[0]);
	i = 1;
	while (s[i])
	{
		tmp = str;
		str = triple_join(tmp, "/", s[i]);
		ft_strdel(&tmp);
		i++;
	}
	ft_str2del(s);
	return (str);
}

int			ft_count_string(char *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			n++;
		i++;
	}
	return (++n);
}
