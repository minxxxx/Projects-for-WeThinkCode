/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 15:37:16 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/11 20:41:24 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <netdb.h>
#include <unistd.h>

void	create_server(t_env *env)
{
	struct addrinfo		hints;
	struct addrinfo		*res;

	ft_bzero(&hints, sizeof(hints));
	hints.ai_family = AF_INET6;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	hints.ai_protocol = env->proto_nb;
	if (getaddrinfo(NULL, env->port, &hints, &res))
		ft_exit("error: cannot get addrinfo");
	while (res)
	{
		env->sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (env->sock >= 0)
		{
			if (!bind(env->sock, res->ai_addr, res->ai_addrlen)
				&& !listen(env->sock, 42))
				break ;
			close(env->sock);
		}
		res = res->ai_next;
	}
	if (env->sock < 0 || !res)
		ft_exit("error: cannot open socket");
	freeaddrinfo(res);
}
