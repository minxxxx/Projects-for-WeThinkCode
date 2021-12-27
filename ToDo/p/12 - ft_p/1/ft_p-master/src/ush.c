/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ush.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ush.h"

#include <ft/string.h>
#include <ft/stdio.h>
#include <ft/stdlib.h>

#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <wait.h>

#include <sys/socket.h>
#include <sys/resource.h>

int ush_system(int sock, int ac, char *av[], void *user)
{
	(void)ac;
	(void)user;
	pid_t const pid = fork();
	if (pid < 0) return pid;

	int status;
	struct rusage usage;

	if (pid != 0) {
		wait4(pid, &status, 0, &usage);
		send(sock, "\0", 1, 0);
		return status;
	}

	dup2(sock, STDIN_FILENO);
	dup2(sock, STDOUT_FILENO);
	dup2(sock, STDERR_FILENO);

	execv(av[0], av);
	ft_fprintf(g_stderr, "execv: %s\n", ft_strerror(errno));
	exit(1);
}

int ush_eval(int sock, char *cmd, struct ush_bi const *bi, void *user)
{
	int ac = 0;
	char *av[USH_ARGS_MAX] = { };

	/* Split command line into av array */
	for (char *part = cmd; ac < USH_ARGS_MAX + 1; ++ac) {
		av[ac] = part;
		part = ft_strmchr(part, " \t");

		if (part == NULL) {
			part = ft_strchr(av[ac++], '\n');
			if (part) *part = '\0';
			break;
		}

		do *part++ = '\0'; while (ft_strchr(" \t", *part));
	}

	/* Got an empty command you fucking bastard */
	if (ac == 0) return 0;

	/* av is a NULL terminated array */
	av[ac] = NULL;

	assert(bi);
	for (; bi->name && ft_strcmp(bi->name, av[0]) != 0; ++bi);

	if (bi->eval == NULL)
		return ft_dprintf(sock, "%s: unknown command\n", av[0]), 0;

	return bi->eval(sock, ac, av, user);
}
