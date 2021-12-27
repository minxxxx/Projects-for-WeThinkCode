/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:15:11 by jtranchi          #+#    #+#             */
/*   Updated: 2018/05/23 18:51:02 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftp.h"

void		print_usage(void)
{
	ft_putendl("usage : serveur <port>");
	exit(0);
}

t_mem		*prompt(void)
{
	ft_putstr("$> ");
	return (read_fd(0));
}

int			check_if_data(t_mem *mem)
{
	char	**tabl;
	int		fd;
	int		i;
	int		ret;

	ret = -1;
	tabl = ft_strsplit(mem->data, ' ');
	if (ft_strequ(tabl[0], "data") == 1 && tabl[1])
	{
		if ((fd = open(tabl[1], O_RDWR | O_CREAT, 0666)) < 0)
			write_error("get", "Permission denied", 1);
		i = 4 + 1 + ft_strlen(tabl[1]);
		while (++i < mem->len)
			write(fd, &mem->data[i], 1);
		write_success("get", 1);
		ret = 0;
		close(fd);
	}
	ft_free_tabl(tabl);
	return (ret);
}

void		exec_lls(t_mem **mem, char **tabl)
{
	int	f;

	f = fork();
	if (f == 0)
	{
		write_success("lls", 1);
		execve("/bin/ls", tabl, NULL);
	}
	wait4(f, 0, 0, NULL);
	(*mem)->len = 0;
}

void		exec_lpwd(t_mem **mem)
{
	char *wd;
	char *ret;

	wd = NULL;
	wd = getcwd(wd, 0);
	ret = ft_strjoin_nf(wd, "\n", 1);
	write_success("lpwd", 1);
	write(1, ret, ft_strlen(ret));
	ft_strdel(&ret);
	(*mem)->len = 0;
}
