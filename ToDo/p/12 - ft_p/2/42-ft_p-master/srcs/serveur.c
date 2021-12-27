/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:57:35 by jtranchi          #+#    #+#             */
/*   Updated: 2018/04/28 13:57:12 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftp.h"

int		ft_create_serveur(int port)
{
	int					sock;
	struct protoent		*p;
	struct sockaddr_in6	sin;

	p = getprotobyname("tcp");
	if (p == 0)
	{
		write_error("connection", "proto error", 1);
		exit(-1);
	}
	sock = socket(AF_INET6, SOCK_STREAM, p->p_proto);
	sin.sin6_family = AF_INET6;
	sin.sin6_port = htons(port);
	sin.sin6_addr = in6addr_any;
	if (bind(sock, (const struct sockaddr*)&sin, sizeof(sin)) == -1)
	{
		write_error("connection", "bind error", 1);
		exit(-1);
	}
	listen(sock, 42);
	return (sock);
}

int		check_builtin(t_mem *mem, int fd, char *wd)
{
	char **tabl;

	tabl = ft_strsplit(mem->data, ' ');
	if (ft_strequ(tabl[0], "ls") == 1)
		return (exec_ls(tabl, fd));
	if (ft_strequ(tabl[0], "pwd") == 1)
		return (exec_pwd(fd));
	if (ft_strequ(tabl[0], "get") == 1)
		return (exec_get(tabl, fd));
	if (ft_strequ(tabl[0], "data") == 1)
		return (check_put_data(mem, fd));
	if (ft_strequ(tabl[0], "cd") == 1)
		return (exec_cd(mem, wd, fd));
	if (ft_strequ(tabl[0], "mkdir") == 1)
		return (exec_mkdir(tabl, fd));
	if (ft_strequ(tabl[0], "rmdir") == 1)
		return (exec_rmdir(tabl, fd));
	if (ft_strequ(tabl[0], "unlink") == 1)
		return (exec_unlink(tabl, fd));
	return (-1);
}

void	create_client(int cs)
{
	t_mem	*mem;
	int		f;
	char	*wd;
	char	**tabl;

	f = fork();
	if (f == 0)
	{
		wd = NULL;
		wd = getcwd(wd, 0);
		while (42)
		{
			mem = read_fd(cs);
			tabl = ft_strsplit(mem->data, ' ');
			if (ft_strequ(tabl[0], "data") != 1)
				remove_back(mem);
			if (check_builtin(mem, cs, wd) == -1)
				write_error("command not found", mem->data, cs);
			ft_free_mem(mem);
			ft_free_tabl(tabl);
		}
		ft_strdel(&wd);
	}
}

int		main(int argc, char **argv)
{
	int						port;
	int						socket;
	int						cs;
	struct sockaddr_in6		sin;
	unsigned int			sizesin;

	if (argc <= 1)
		print_usage();
	port = atoi(argv[1]);
	socket = ft_create_serveur(port);
	while (42)
	{
		cs = accept(socket, (struct sockaddr *)&sin, &sizesin);
		create_client(cs);
	}
	close(socket);
}
