/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:38:28 by jtranchi          #+#    #+#             */
/*   Updated: 2018/05/16 15:38:29 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftp.h"

char	*remove_last_dir(char *wd)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = ft_strlen(wd);
	while (wd[i] != '/')
		i--;
	ret = ft_strnew(i);
	ft_memcpy(ret, wd, i);
	return (ret);
}

char	*parse_wd(char *wd, char *buf)
{
	char	**tabl;
	int		i;

	i = -1;
	tabl = ft_strsplit(buf, '/');
	while (tabl[++i])
	{
		if (ft_strequ(tabl[i], "..") == 1)
			wd = remove_last_dir(wd);
		else
		{
			wd = ft_strjoin(wd, "/");
			wd = ft_strjoin_nf(wd, tabl[i], 1);
		}
	}
	ft_free_tabl(tabl);
	return (wd);
}

void	last_cd(char *wd, char *curwd, char **tabl, int socket)
{
	char	*newwd;

	newwd = NULL;
	newwd = parse_wd(curwd, tabl[1]);
	if (tabl[1][0] == '/')
	{
		if (check_if_contains(wd, tabl[1]))
			ft_chdir(newwd, "cd", socket);
		else
			write_error("cd", "permission denied", socket);
		return ;
	}
	if (check_if_contains(wd, newwd))
		ft_chdir(newwd, "cd", socket);
	else
		write_error("cd", "permission denied", socket);
}

int		exec_cd(t_mem *mem, char *wd, int socket)
{
	char	**tabl;
	char	*curwd;

	tabl = ft_strsplit(mem->data, ' ');
	curwd = NULL;
	curwd = getcwd(curwd, 0);
	if (!tabl[1])
		ft_chdir(wd, "cd", socket);
	else if (tabl[1][0] != '.' && tabl[1][0] != '/')
	{
		curwd = ft_strjoin_nf(curwd, "/", 1);
		curwd = ft_strjoin_nf(curwd, tabl[1], 1);
		ft_chdir(curwd, "cd", socket);
	}
	else
		last_cd(wd, curwd, tabl, socket);
	ft_strdel(&curwd);
	ft_free_tabl(tabl);
	return (0);
}

int		exec_lcd(t_mem *mem, char *wd)
{
	char	**tabl;
	char	*curwd;

	tabl = ft_strsplit(mem->data, ' ');
	curwd = NULL;
	curwd = getcwd(curwd, 0);
	if (!tabl[1])
		ft_chdir(wd, "lcd", 1);
	else if (tabl[1][0] != '.' && tabl[1][0] != '/')
	{
		curwd = ft_strjoin_nf(curwd, "/", 1);
		curwd = ft_strjoin_nf(curwd, tabl[1], 1);
		ft_chdir(curwd, "lcd", 1);
	}
	else if (tabl[1][0] == '.' || tabl[1][0] == '/')
		ft_chdir(tabl[1], "lcd", 1);
	else
		ft_chdir(parse_wd(curwd, tabl[1]), "lcd", 1);
	ft_strdel(&curwd);
	ft_free_tabl(tabl);
	return (0);
}
