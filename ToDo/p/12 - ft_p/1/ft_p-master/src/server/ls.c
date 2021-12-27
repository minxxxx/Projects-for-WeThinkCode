/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server/ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ush.h"

#include <ft/string.h>

int server_ls(int sock, int ac, char *av[], void *user)
{
	av[0] = "/bin/ls";

	/* Sanitize client input (only accept options) */
	for (int i = 1; i < ac; ++i) if (*av[i] != '-') av[i] = "";

	return ush_system(sock, ac, av, user);
}
