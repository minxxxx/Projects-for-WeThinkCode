/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:39 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:40 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static int	create_socket(int port, char *av)
{
	struct protoent		*proto;
	int					ret;
	struct sockaddr_in	addr;

	proto = getprotobyname("tcp");
	if (!proto)
		return (pemr(av, "Error while trying to get the protocol\n"));
	if ((ret = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		return (pemr(av, "Error while trying to create a socket\n"));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(ret, (struct sockaddr*)(&addr), sizeof(struct sockaddr_in)) == -1)
		return (pemr(av, "Error while trying to bind the socket.\n"));
	if (listen(ret, 32) == -1)
		return (pemr(av, "Error while trying to listen with the socket.\n"));
	return (ret);
}

static int	print_usage(char *av)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd(" <port>\n", 2);
	return (-1);
}

static int	accept_socket(int socket)
{
	int					cs;
	struct sockaddr_in	csin;
	unsigned int		cslen;

	cslen = sizeof(struct sockaddr_in);
	if ((cs = accept(socket, (struct sockaddr *)&csin, &cslen)) == -1)
	{
		ft_putstr_fd("Error while trying to accept a socket.\n", 2);
		return (0);
	}
	return (cs);
}

static void	do_fork(t_data *data, int socket, int cs)
{
	int	pi;

	pi = fork();
	if (pi == 0)
	{
		close(socket);
		handle_connection(cs, data);
		close(cs);
		exit(0);
	}
	close(cs);
}

int			main(int ac, char **av)
{
	int		socket;
	t_data	data;
	int		cs;

	if (ac != 2 || ft_atoi(av[1]) == 0)
		return (print_usage(av[0]));
	data.pi_port = ft_atoi(av[1]);
	if (!(socket = create_socket(data.pi_port, av[0])))
		return (-1);
	data.exec_path = get_current_dir();
	data.av = av[0];
	if ((data.pass_fd = open(".pass", O_RDONLY)) == -1)
		ft_printf(WARNING_NO_PASS_FILE);
	signal(SIGCHLD, handle_sigchld);
	while (1)
	{
		if ((cs = accept_socket(socket)) == 0)
			return (0);
		do_fork(&data, socket, cs);
	}
	close(socket);
	return (0);
}
