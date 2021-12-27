/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 15:07:53 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 11:12:48 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <netdb.h>
#include <unistd.h>

void	create_client(t_env *env)
{
	struct addrinfo		hints;
	struct addrinfo		*res;

	ft_bzero(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = env->proto_nb;
	if (getaddrinfo(env->addr, env->port, &hints, &res))
		ft_exit("error: cannot get addrinfo");
	while (res)
	{
		env->sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (env->sock >= 0)
		{
			if (!connect(env->sock, res->ai_addr, res->ai_addrlen))
				break ;
			close(env->sock);
		}
		res = res->ai_next;
	}
	if (env->sock < 0 || !res)
		ft_exit("error: connection impossible");
	freeaddrinfo(res);
}

void	init_env(t_env *env, char **av)
{
	struct protoent		*proto;

	if (!(proto = getprotobyname("tcp")))
		ft_exit("error: cannot get proto by name");
	env->proto_nb = proto->p_proto;
	if (!av[2][0] || !ft_str_isint(av[2]) || ft_strlen(av[2]) > 5)
		ft_exit("error: port is invalid");
	env->addr = av[1];
	env->port = av[2];
}
