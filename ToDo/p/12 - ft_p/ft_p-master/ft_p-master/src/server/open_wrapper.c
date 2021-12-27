/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:41 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:09:46 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

char	*get_prec(const char *path)
{
	int		i;
	int		car;
	char	*rez;

	i = ft_strlen(path) - 1;
	car = 0;
	while (i >= 0)
	{
		if (path[i] == '/' && car)
			break ;
		if (path[i] != '/')
			car = 1;
		i--;
	}
	if (i == -1 || i == 0)
	{
		if (path[0] == '/')
			rez = ft_strdup("/");
		else
			rez = ft_strdup(".");
		i = 0;
	}
	else
		rez = ft_strsub(path, 0, i);
	return (rez);
}

char	*get_current_dir(void)
{
	char	*rez;

	rez = getcwd(NULL, 0);
	return (rez);
}

int		free_and_ret(void *a, void *b, void *c, int ret)
{
	if (a)
		free(a);
	if (b)
		free(b);
	if (c)
		free(c);
	return (ret);
}

int		can_be_oppened(const char *path, const char *exec_path)
{
	char	*rez;
	char	*prec;
	char	*next;

	if (!(rez = get_prec(path)))
		return (0);
	if (!(prec = get_current_dir()))
		return (free_and_ret(rez, NULL, NULL, 0));
	if (chdir(rez) == -1)
		return (free_and_ret(rez, prec, NULL, 0));
	if (!(next = get_current_dir()))
	{
		chdir(prec);
		return (free_and_ret(rez, prec, NULL, 0));
	}
	chdir(prec);
	if (ft_strncmp(next, exec_path, ft_strlen(exec_path)) == 0)
		return (free_and_ret(rez, next, prec, 1));
	else
		return (free_and_ret(rez, next, prec, 0));
}

int		open_wrapper(t_data *data, const char *path, int oflag, int mode)
{
	int			fd;
	struct stat	stat;

	if (!path)
		return (-1);
	if (!can_be_oppened(path, data->exec_path))
		return (-1);
	if (mode)
		fd = open(path, oflag, mode);
	else
		fd = open(path, oflag);
	if (fd != -1)
	{
		if ((fstat(fd, &stat) == -1) || ((stat.st_mode & S_IFMT) == S_IFDIR))
		{
			close(fd);
			return (-1);
		}
	}
	return (fd);
}
