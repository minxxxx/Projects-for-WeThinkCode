/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void		display_not_such(char *who, char *where, t_cmd *cmd, t_data *data)
{
	putstr_builtin(cmd, who, 2);
	putstr_builtin(cmd, ": ", 2);
	putstr_builtin(cmd, where, 2);
	putstr_builtin(cmd, ": No such file or directory\n", 2);
	data->cd_ret = 1;
}

void		display_cd_permission(char *path, t_cmd *cmd, t_data *data)
{
	putstr_builtin(cmd, "cd: ", 2);
	putstr_builtin(cmd, path, 2);
	putstr_builtin(cmd, ": Permission denied\n", 2);
	data->cd_ret = 1;
}

void		display_cd_invalid_option(char *opt, t_cmd *cmd, t_data *data)
{
	putstr_builtin(cmd, "cd: ", 2);
	putstr_builtin(cmd, opt, 2);
	putstr_builtin(cmd, ": invalid option\n", 2);
	putstr_builtin(cmd, "cd: usage: cd [-L OR -P] [dir]\n", 2);
	data->cd_ret = 1;
}
