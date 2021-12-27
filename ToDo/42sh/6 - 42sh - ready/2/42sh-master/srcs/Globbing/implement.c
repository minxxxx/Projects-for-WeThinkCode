/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 09:39:41 by ftait             #+#    #+#             */
/*   Updated: 2017/11/24 02:53:39 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define COPY temp[len]=ft_strdup(a->array[i]);len++;i++

/*
 ** Removes globs from the cmds
*/

char		**ft_remove_globs(t_all *a)
{
	char	**temp;
	int		len;
	int		i;

	len = ft_arraylen(a->array);
	i = -1;
	while (a->array[++i] != NULL)
		if (isglob(a->array[i]) > 0)
			len--;
	temp = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	len = 0;
	while (a->array[i] != NULL)
	{
		if (isglob(a->array[i]) > 0)
			i++;
		else
		{
			COPY;
		}
	}
	temp[len] = NULL;
	ft_delarray(a->array);
	return (temp);
}

/*
 ** Finds all the globs to work with
*/

char		**ft_find_globs(char **array)
{
	char	**temp;
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (array[++i] != NULL)
		if (isglob(array[i]) > 0)
			len++;
	temp = (char **)malloc(sizeof(char *) * (len + 1));
	i = -1;
	len = 0;
	while (array[++i] != NULL)
		if (isglob(array[i]) > 0)
		{
			temp[len] = ft_strdup(array[i]);
			len++;
		}
	temp[len] = NULL;
	return (temp);
}

/*
 ** Checks if it has a glob
*/

int			hasglob(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		if (isglob(array[i]) > 0)
			return (i);
		i++;
	}
	return (0);
}

/*
 ** Implements the globs into the commands before executing the command
*/

int			implementg(t_all *a)
{
	int		fail;
	int		i;
	int		pos;
	char	**globs;
	int		n;

	i = -1;
	n = 0;
	fail = 0;
	pos = hasglob(&a->array[0]);
	globs = ft_find_globs(a->array);
	while (globs[n])
	{
		fail = globinit(globs[n], a);
		n++;
	}
	a->array = ft_remove_globs(a);
	ft_delarray(globs);
	if (fail == 0)
		return (-1);
	return (1);
}
