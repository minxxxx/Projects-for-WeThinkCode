/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:35:56 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 15:35:56 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static int		ft_isspace(char car)
{
	if (car == '\t' || car == ' ')
		return (1);
	else
		return (0);
}

static int		ft_strcount(char const *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (ft_isspace(s[i]) && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			count++;
		while (!ft_isspace(s[i]) && s[i] != '\0')
			i++;
	}
	return (count);
}

static int		poulet(size_t i, size_t j, char const *s)
{
	while (!ft_isspace(s[i + j]) && s[i + j] != '\0')
		j++;
	return (j);
}

static	char	**ft_fln(char const *s, char **res, size_t *x)
{
	size_t	i;
	size_t	j;

	i = 0;
	*x = 0;
	while (s[i] != '\0')
	{
		while (ft_isspace(s[i]) && s[i] != '\0')
			i++;
		j = 0;
		j = poulet(i, j, s);
		if (s[i + j] != '\0' || !ft_isspace(s[i + j - 1]))
		{
			res[*x] = ft_strsub(s, i, j);
			*x = *x + 1;
		}
		i += j;
	}
	return (res);
}

char			**ft_special_split(char const *s)
{
	char	**res;
	size_t	x;

	res = malloc((ft_strcount(s) + 1) * sizeof(char*));
	if (!s || !res)
		return (NULL);
	if (ft_strcount(s) == 0)
	{
		res[0] = NULL;
		return (res);
	}
	res = ft_fln(s, res, &x);
	res[x] = NULL;
	return (res);
}
