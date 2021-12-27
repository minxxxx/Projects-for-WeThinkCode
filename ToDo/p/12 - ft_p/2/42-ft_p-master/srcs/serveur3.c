/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:11:42 by jtranchi          #+#    #+#             */
/*   Updated: 2018/05/21 13:11:42 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftp.h"

t_mem	*exec_get2(char **tabl, int fd)
{
	int				file;
	struct stat		buf;
	t_mem			*tmp;

	tmp = (t_mem*)malloc(sizeof(t_mem));
	if (stat(tabl[1], &buf) == -1)
	{
		write_error("get", "file doesnt exists", fd);
		return (NULL);
	}
	if ((file = open(tabl[1], O_RDONLY)) < 0)
	{
		write_error("get", "permission denied", fd);
		return (NULL);
	}
	tmp->data = ft_strjoin("data ", tabl[1]);
	tmp->data = ft_strjoin_nf(tmp->data, " ", 1);
	tmp->len = ft_strlen(tmp->data);
	if (buf.st_size > 0)
		tmp = ft_memjoin(tmp, read_fd(file));
	close(file);
	return (tmp);
}

int		exec_get(char **tabl, int fd)
{
	t_mem	*mem;

	if (!tabl[1])
		write_error("get", "please specify a file", fd);
	else
	{
		mem = exec_get2(tabl, fd);
		if (mem)
			write_fd(fd, mem);
	}
	return (0);
}

int		exec_ls(char **tabl, int fd)
{
	int f;

	f = fork();
	if (f == 0)
	{
		dup2(fd, 1);
		dup2(fd, 2);
		execve("/bin/ls", tabl, NULL);
	}
	wait4(f, 0, 0, NULL);
	return (0);
}

int		exec_pwd(int fd)
{
	char *wd;
	char *ret;

	wd = NULL;
	wd = getcwd(wd, 0);
	ret = ft_strjoin_nf(wd, "\n", 1);
	ret = ft_strjoin_nf("\033[92mSUCCESS: pwd: \033[0m\n", ret, 2);
	write(fd, ret, ft_strlen(ret));
	ft_strdel(&ret);
	return (0);
}
