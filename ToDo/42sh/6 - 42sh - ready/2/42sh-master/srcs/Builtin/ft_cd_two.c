/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:15:15 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:51:17 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	ft_root(t_all *a)
{
	if (chdir("/") == -1)
		ft_putendl("could not find root");
	else
		chpwd("/", a);
}

void	ft_home(t_all *a)
{
	int		i;
	char	**path;

	i = 0;
	while (ft_strnstr(a->new[i], "HOME=", 6) == NULL)
		i++;
	path = ft_strsplit(a->new[i], '=');
	if (chdir(path[1]) == -1)
		ft_putendl("path: error: home now found.");
	else
		chpwd(path[1], a);
	ft_delarray(path);
}

void	ft_chdir(t_all *a)
{
	int		i;
	char	**path;
	char	*temp;

	i = 0;
	while (ft_strnstr(a->new[i], "HOME=", 6) == NULL)
		i++;
	path = ft_strsplit(a->new[i], '=');
	temp = ft_strjoin(path[1], a->array[1]);
	if (chdir(a->array[1]) == -1)
		ft_putendl("path: error: home now found.");
	else
		chpwd(temp, a);
	ft_delarray(path);
	ft_strdel(&temp);
}
