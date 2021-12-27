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

/**
 * @file ush.h
 * @brief
 * Micro-shell command line interpreter for remote (thought socket)
 * execution
 */
#ifndef __USH_H
# define __USH_H

#define USH_ARG_MAX   (1024) /**< Maximum size of a full argument */
#define USH_ARGS_MAX  ( 128) /**< Maximum number of argumnets     */

struct ush_bi
{
	char const *name;
	int (*eval)(int sock, int ac, char *av[], void *user);
};

int ush_system(int sock, int ac, char *av[], void *user);
int ush_eval(int sock, char *cmd, struct ush_bi const *builtins, void *user);

#endif /* !__USH_H */
