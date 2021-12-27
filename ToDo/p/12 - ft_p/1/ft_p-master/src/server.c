/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ush.h"
#include "ftp.h"

#include <ft/opts.h>
#include <ft/stdio.h>
#include <ft/stdlib.h>

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <wait.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(int ac, char *av[])
{
	if (ac != 2) {
		ft_fprintf(g_stderr, "Usage %s [port]\n Open a server\n",
		           av[0]);
		return EXIT_FAILURE;
	}

	int const port = ft_atoi(av[1]);
	char root[PATH_MAX];

	if (getcwd(root, PATH_MAX) == NULL)
		goto abort;

	fd_set rfds;
	FD_ZERO(&rfds);

	static struct ftp_usr users[] = {
		{ "lol"  , "lol"   },
		{ "admin", "admin" },
		{ NULL   , NULL    },
	};

	ftp_srv_t srv;

	if (ftp_srv_open(port, root, &rfds, users, &srv))
		goto abort;

	FD_SET(STDIN_FILENO, &rfds);

	while (true) {
		struct timeval to = { };

		fd_set _rfds = rfds;

		int const err = select(FD_SETSIZE, &_rfds, NULL, NULL, NULL);
		if (err < 0 && err != ETIMEDOUT) goto abort;

		if (FD_ISSET(STDIN_FILENO, &_rfds)) {
			char buf[6];
			ssize_t const rd = read(STDIN_FILENO, buf, sizeof buf);
			if (rd < 0) goto abort;

			buf[rd] = '\0';

			if (ft_strcmp("quit\n", buf) == 0) {
				ft_printf("quit !\n");
				break;
			}

			ft_printf("%s: unknown command: %s", av[0], buf);
		}

		if (ftp_srv_start(&srv, &_rfds, &to))
			goto abort;
	}

	return EXIT_SUCCESS;

abort:
	ft_fprintf(g_stderr, "%s: %s\n", av[0], ft_strerror(errno));
	return EXIT_FAILURE;
}
