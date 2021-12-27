/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 11:13:10 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 22:18:04 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <unistd.h>
#include <sys/param.h>

void	send_pwd(t_env *env, char *pwd)
{
	if (!pwd)
		ft_exit("Cannot get pwd client");
	if (pwd[ft_strlen(pwd) - 1] != '/')
		pwd = v_strjoin_free(pwd, "/", TRUE, FALSE);
	pwd = v_strjoin_free("MYPWDIS ", pwd, FALSE, TRUE);
	ft_putstr_fd(pwd, env->sock);
	ft_free(pwd);
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 3)
		ft_exit("Usage: ./client <address> <port>");
	init_env(&env, av);
	create_client(&env);
	send_pwd(&env, getcwd(NULL, PATH_MAX + 1));
	client_shell(&env);
	close(env.sock);
	return (0);
}
