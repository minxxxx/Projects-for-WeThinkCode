/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server/cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ush.h"

#include <ft/stdio.h>
#include <ft/stdlib.h>
#include <ft/string.h>

#include <errno.h>
#include <limits.h>
#include <unistd.h>

int server_cd(int sock, int ac, char *av[], void *user)
{
	char const *const root = user;

	if (ac == 1)
		return chdir(root);

	if (ac != 2) {
		ft_dprintf(sock, "Usage: cd [path]\n Change working directory\n");
		return 1;
	}

	char cwd[PATH_MAX], dest[PATH_MAX];

	if (getcwd(cwd, sizeof cwd) == NULL) return -1;

	if (ft_realpath(av[1], dest, cwd) == NULL) {
		ft_dprintf(sock, "cd: %s: %s\n", av[1], ft_strerror(ENOTDIR));
		return 1;
	}

	size_t const root_len = ft_strlen(root);

	if (ft_strncmp(root, dest, root_len) != 0) {
		ft_dprintf(sock, "cd: %s: %s\n", av[1], ft_strerror(EPERM));
		return 1;
	}

	return chdir(dest);
}
