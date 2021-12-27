/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 15:07:53 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 11:24:18 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <netdb.h>
#include <signal.h>
#include <unistd.h>
#include <sys/param.h>

void	init_env(t_env *env, char *port)
{
	struct protoent		*proto;

	signal(SIGCHLD, SIG_IGN);
	if (!(proto = getprotobyname("tcp")))
		ft_exit("error: cannot get proto by name");
	env->proto_nb = proto->p_proto;
	env->port = port;
	if (!(env->pwd_init = getcwd(NULL, PATH_MAX + 1)))
		ft_exit("error: cannot get current directory path");
	env->pwd_cur = v_strdup("/");
	env->pwd_clnt = v_strdup("");
}
