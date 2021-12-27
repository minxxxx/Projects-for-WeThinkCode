/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 11:13:10 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/12 10:47:37 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <unistd.h>

int			main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		ft_exit("Usage: ./serveur <port>");
	init_env(&env, av[1]);
	create_server(&env);
	manage_client(&env);
	close(env.sock);
	return (0);
}
