/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:59:05 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/21 12:36:11 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		ft_is_builtin(char *cmd)
{
	if (ft_strequ(cmd, CMD_ECHO) || ft_strequ(cmd, CMD_EXIT)\
			|| ft_strequ(cmd, CMD_ENV) || ft_strequ(cmd, CMD_SETENV)\
			|| ft_strequ(cmd, CMD_UNSETENV) || ft_strequ(cmd, CMD_CD)\
			|| ft_strequ(cmd, CMD_HIST))
		return (1);
	return (0);
}

int		ft_launch_builtin(char **cmd)
{
	if (ft_strequ(*cmd, CMD_ECHO))
		return (ft_builtin_echo(cmd));
	if (ft_strequ(*cmd, CMD_CD))
		return (ft_builtin_cd(cmd));
	if (ft_strequ(*cmd, CMD_ENV))
		return (ft_builtin_env(cmd));
	if (ft_strequ(*cmd, CMD_SETENV))
		return (ft_builtin_setenv(cmd));
	if (ft_strequ(*cmd, CMD_UNSETENV))
		return (ft_builtin_unsetenv(cmd));
	if (ft_strequ(*cmd, CMD_HIST))
		return (ft_builtin_history(cmd));
	if (ft_strequ(*cmd, CMD_EXIT))
		ft_builtin_exit(cmd);
	return (0);
}
