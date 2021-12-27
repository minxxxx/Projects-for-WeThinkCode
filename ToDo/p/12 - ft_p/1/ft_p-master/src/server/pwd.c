/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server/pwd.c                                       :+:      :+:    :+:   */
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

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>

int server_pwd(int sock, int ac, char *av[], void *user)
{
	(void)av;
	char const *const root = user;

	if (ac != 1) {
		ft_dprintf(sock, "Usage: pwd\n Print current working directory\n");
		return 1;
	}

	char cwd[PATH_MAX];

	if (getcwd(cwd, sizeof cwd) == NULL) return -1;

	size_t const root_len = ft_strlen(root);
	size_t const cwd_len  = ft_strlen(cwd);

	if (cwd_len <= root_len)
		return ft_dprintf(sock, "/\n");

	return ft_dprintf(sock, "%s\n", cwd + root_len);
}
