/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:21:28 by ftait             #+#    #+#             */
/*   Updated: 2017/11/24 02:53:02 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
** This is for the execcmds function
*/

char	**ft_add_glob(char *str, t_all *a)
{
	char	**temp;
	int		i;
	int		n;
	int		len;

	i = -1;
	len = ft_arraylen(a->array);
	temp = (char **)malloc(sizeof(char *) * (len + 2));
	i = 0;
	n = 0;
	while (a->array[i] != NULL)
	{
		temp[n] = ft_strdup(a->array[i]);
		i++;
		n++;
	}
	temp[n] = ft_strdup(str);
	temp[n + 1] = NULL;
	ft_delarray(a->array);
	return (temp);
}

int		globinit(char *argv, t_all *a)
{
	t_dir			this;
	char			*temp;
	char			buff[4094];
	int				count;

	count = 0;
	temp = ft_strdup(argv);
	a->yes = 1;
	this.curr_dir = getcwd(buff, 4094);
	if (NULL == this.curr_dir)
		return (-1);
	this.dp = opendir((const char*)this.curr_dir);
	if (NULL == this.dp)
		return (-1);
	while ((this.dptr = readdir(this.dp)) != NULL)
		if ((globfunction(this.dptr->d_name, temp) == 1))
		{
			a->array = ft_add_glob(this.dptr->d_name, a);
			count++;
		}
	ft_strdel(&temp);
	return (count);
}

/*
** This is for the execvp function
*/

char	**ft_add_glob_two(char *str, t_exe *b)
{
	char	**temp;
	int		i;
	int		n;
	int		len;

	i = -1;
	len = ft_arraylen(b->cmds);
	temp = (char **)malloc(sizeof(char *) * (len + 2));
	i = 0;
	n = 0;
	while (b->cmds[i] != NULL)
	{
		temp[n] = ft_strdup(b->cmds[i]);
		i++;
		n++;
	}
	temp[n] = ft_strdup(str);
	temp[n + 1] = NULL;
	ft_delarray(b->cmds);
	return (temp);
}

int		globinit_two(char *argv, t_exe *b)
{
	t_dir			this;
	char			*temp;
	char			buff[4094];
	int				count;

	count = 0;
	temp = ft_strdup(argv);
	this.curr_dir = getcwd(buff, 4094);
	if (NULL == this.curr_dir)
		return (-1);
	this.dp = opendir((const char*)this.curr_dir);
	if (NULL == this.dp)
		return (-1);
	while ((this.dptr = readdir(this.dp)) != NULL)
		if ((globfunction(this.dptr->d_name, temp) == 1))
		{
			b->cmds = ft_add_glob_two(this.dptr->d_name, b);
			count++;
		}
	ft_strdel(&temp);
	return (count);
}
