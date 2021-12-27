/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 09:39:41 by ftait             #+#    #+#             */
/*   Updated: 2017/11/24 02:53:49 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define COPY temp[len]=ft_strdup(b->cmds[i]);len++;i++

/*
 ** Removes globs from the cmds
*/

char		**ft_remove_globs_two(t_exe *b)
{
	char	**temp;
	int		len;
	int		i;

	len = ft_arraylen(b->cmds);
	i = -1;
	while (b->cmds[++i] != NULL)
		if (isglob(b->cmds[i]) > 0)
			len--;
	temp = (char **)malloc(sizeof(char *) * (len + 1));
	i = 0;
	len = 0;
	while (b->cmds[i] != NULL)
	{
		if (isglob(b->cmds[i]) > 0)
			i++;
		else
		{
			COPY;
		}
	}
	temp[len] = NULL;
	ft_delarray(b->cmds);
	return (temp);
}

/*
 ** Finds all the globs to work with
*/

char		**ft_find_globs_two(char **array)
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
 ** Implements the globs into the commands before executing the command
*/

int			implementg_two(t_exe *b)
{
	int		fail;
	int		i;
	int		pos;
	char	**globs;
	int		n;

	i = -1;
	n = 0;
	fail = 0;
	pos = hasglob(&b->cmds[0]);
	globs = ft_find_globs_two(b->cmds);
	while (globs[n])
	{
		fail = globinit_two(globs[n], b);
		n++;
	}
	b->cmds = ft_remove_globs_two(b);
	ft_delarray(globs);
	if (fail == 0)
		return (-1);
	return (1);
}
