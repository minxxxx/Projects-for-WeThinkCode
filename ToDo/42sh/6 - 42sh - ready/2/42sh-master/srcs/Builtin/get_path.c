/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 08:42:21 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:51:17 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

char	*ft_splitname(t_all *a)
{
	char	**tmp;
	int		i;

	tmp = ft_strsplit(a->array[0], '/');
	i = ft_arraylen(tmp) - 1;
	return (tmp[i]);
}

int		ft_ptsplit(t_bin *bin)
{
	bin->check = ft_strjoin(bin->path[bin->n], bin->file);
	if (access(bin->check, X_OK) == 0)
		return (1);
	bin->n++;
	bin->arraylen--;
	ft_strdel(&bin->check);
	return (0);
}

void	path_part_two(t_all *a, t_bin *bin, struct termios *term)
{
	if (ft_strchr(a->array[0], '/') != NULL
			|| ft_strnstr(".", a->array[0], 2) != NULL)
	{
		free(a->array[0]);
		a->array[0] = NULL;
		a->array[0] = ft_splitname(a);
	}
	bin->find = ft_strsplit(a->new[bin->i], '=');
	bin->path = ft_strsplit(bin->find[1], ':');
	ft_delarray(bin->find);
	bin->find = NULL;
	bin->arraylen = ft_arraylen(bin->path);
	bin->n = 0;
	bin->file = ft_strjoin("/", a->array[0]);
	bin->on = 0;
	while (bin->on != 1 && bin->arraylen >= 0 && bin->arraylen != bin->i)
		bin->on = ft_ptsplit(bin);
	if (bin->arraylen == -1)
		ft_execcurr(a, term);
	else
		ft_execpath(bin->check, a);
	ft_delarray(bin->path);
	bin->path = NULL;
}

void	path(t_all *a, struct termios *term)
{
	t_bin		bin;

	bin.i = 0;
	bin.n = ft_arraylen(a->new);
	while (a->new[bin.i] && ft_strstr(a->new[bin.i], "PATH=") == NULL)
		bin.i++;
	if (bin.i != bin.n && ft_strchr(a->array[0], '/') == 0)
	{
		path_part_two(a, &bin, term);
		ft_strdel(&bin.check);
		ft_strdel(&bin.file);
		bin.check = NULL;
		bin.file = NULL;
	}
	else
		ft_execcurr(a, term);
}
