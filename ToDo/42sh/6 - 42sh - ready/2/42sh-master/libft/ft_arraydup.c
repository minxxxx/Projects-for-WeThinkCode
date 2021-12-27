/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:02:22 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:03:12 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraydup(char **env)
{
	char	**dest;
	int		i;

	if (!(env))
		return (NULL);
	dest = NULL;
	i = 0;
	dest = ft_sstrnew(ft_sstrlen(env));
	while (env[i])
	{
		dest[i] = ft_strdup(env[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**ft_arraysdupone(char **src, char *str)
{
	char	**dup;
	int		i;

	i = ft_arraylen(src) + 2;
	dup = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (src[i] != NULL)
	{
		dup[i] = ft_strdup(src[i]);
		i++;
	}
	dup[i] = ft_strdup(str);
	dup[i + 1] = NULL;
	return (dup);
}

char	**ft_arraysdup(char **src)
{
	char	**dup;
	int		i;

	i = ft_arraylen(src) + 1;
	dup = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (src[i] != NULL)
	{
		dup[i] = ft_strdup(src[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
