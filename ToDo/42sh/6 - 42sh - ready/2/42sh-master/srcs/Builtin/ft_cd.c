/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:49:11 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:49:04 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
 ** CD - command
*/

void	ft_dash(t_all *a)
{
	char	**str;
	int		i;

	i = 0;
	while ((ft_strstr(a->new[i], "OLDPWD=") == NULL))
		i++;
	str = ft_strsplit(a->new[i], '=');
	if (chdir(str[1]) == -1)
		ft_putendl("Error: could not goto old path.");
	else
		chpwd(str[1], a);
	ft_delarray(str);
}

/*
 ** CD .. command
*/

void	ft_dots(t_all *a)
{
	char	*path;
	char	**temp;
	int		i;

	i = 0;
	while (ft_strncmp(a->new[i], "PWD=", 3) != 0)
		i++;
	temp = ft_strsplit(a->new[i], '=');
	i = ft_strlen(temp[1]);
	while (temp[1][i] != '/')
		i--;
	path = ft_strnew(i);
	path = ft_strncpy(path, temp[1], i);
	if (i != 0 && chdir(a->array[1]) != -1 && temp[1][1] != '\0')
		chpwd(path, a);
	else
	{
		if (chdir("/") != -1)
			chpwd("/", a);
		else
			ft_putendl("Error: Could not find working directory.");
	}
	ft_strdel(&path);
	ft_delarray(temp);
}

/*
 ** CD command
*/

void	ft_null(t_all *a)
{
	char	**path;
	int		i;

	i = 0;
	while (ft_strnstr(a->new[i], "HOME=", 6) == NULL)
		i++;
	path = ft_strsplit(a->new[i], '=');
	if (chdir(path[1]) == -1)
		ft_putendl("error");
	else
		chpwd(path[1], a);
	ft_delarray(path);
}

/*
 ** CD ~/PATH command
*/

void	ft_dir(t_all *a)
{
	char	**home;
	char	*s1;
	char	*s2;
	int		j;

	j = 0;
	if (ft_strnstr(a->array[1], "~", 4) != NULL)
		ft_memmove(a->array[1], a->array[1] + 2, ft_strlen(a->array[1]));
	while (ft_strnstr(a->new[j], "HOME=", 5) == NULL)
		j++;
	home = ft_strsplit(a->new[j], '=');
	s1 = ft_strjoin(home[1], "/");
	s2 = ft_strjoin(s1, a->array[1]);
	if (chdir(s2) == -1)
		ft_putendl("Error: invalid file name.");
	else
		chpwd(s2, a);
	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_delarray(home);
}

/*
 ** check the type of CD command
*/

void	ft_cd(t_all *a)
{
	int		i;

	a->yes = 1;
	i = (a->array[1] != NULL) ? ft_strlen(a->array[1]) : 0;
	if (a->array[1] == NULL)
		ft_null(a);
	else if (i == 1 && a->array[1][0] != '-')
	{
		if (a->array[1][0] == '~')
			ft_home(a);
		else if (a->array[1][0] == '/')
			ft_root(a);
	}
	else
	{
		if (ft_strstr(a->array[1], "-") != NULL)
			ft_dash(a);
		else if (ft_strstr(a->array[1], "..") != NULL)
			ft_dots(a);
		else if (ft_strstr(a->array[1], "~/") != NULL)
			ft_dir(a);
		else
			ft_chdir(a);
	}
}
