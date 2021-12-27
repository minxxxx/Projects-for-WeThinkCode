/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pasv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:23 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:24 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static int	create_socket_pasv(int port)
{
	struct protoent		*proto;
	int					ret;
	struct sockaddr_in	addr;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-2);
	if ((ret = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		return (-2);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(ret, (struct sockaddr*)(&addr), sizeof(struct sockaddr_in)) == -1)
		return (-1);
	if (listen(ret, 32) == -1)
		return (-2);
	return (ret);
}

static char	*build_commentaire(t_data *data, char *addr, int port)
{
	data->commentaire = " Entering Passive Mode (";
	data->commentaire = ft_strjoinaf2(data->commentaire, addr);
	data->commentaire = ft_strjoinaf1(data->commentaire, ",");
	data->commentaire = ft_strjoinaf1(data->commentaire,
			ft_itoa_base_ll(port / 256, 10));
	data->commentaire = ft_strjoinaf1(data->commentaire, ",");
	data->commentaire = ft_strjoinaf1(data->commentaire,
			ft_itoa_base_ll(port % 256, 10));
	data->commentaire = ft_strjoinaf1(data->commentaire, ").");
	return (data->commentaire);
}

void		func_pasv(t_data *data)
{
	int		port;
	int		sock;
	char	*addr;
	char	*ptr;

	if (!data->logged_in)
		return (setret(data, 530, " Please login with USER and PASS", 1));
	port = 2050;
	while (port < 2100 && (sock = create_socket_pasv(port)) == -1 && sock != -2)
		port++;
	if (port == 2100 || sock == -2)
		return (setret(data, 425, " Can't open data connection.", 1));
	addr = ft_strdup(inet_ntoa(data->local_addr));
	while ((ptr = ft_strchr(addr, '.')))
		*ptr = ',';
	data->serv_data_port = port;
	data->data_connection_socket = sock;
	data->data_connection_on = 1;
	data->return_code = 227;
	data->commentaire = build_commentaire(data, addr, port);
	data->free_commentaire = 1;
}
