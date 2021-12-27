/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/02 16:46:02 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static int			env_tmp_exec_end_1(t_cmd *cmd, t_env *new, t_env *tmp)
{
	print_env(new, cmd);
	delete_list(new);
	delete_list(tmp);
	return (0);
}

static int			env_tmp_exec_end_2(t_env *new, t_env *tmp, t_data *data)
{
	delete_list(new);
	delete_list(tmp);
	delete_list_command(data->command);
	data->command = data->orig_cmd;
	return (0);
}

static void			env_tmp_ini(t_env **new, t_data *d, t_env **env, char **scd)
{
	d->i = 0;
	d->orig_cmd = d->command;
	*new = create_tmp_env(d, *env, scd + d->i, 0);
}

int					env_tmp_exc(t_env **env, t_data *d, char **scmd, t_cmd *cmd)
{
	t_env	*tmp;
	t_env	*new;
	char	*new_str;

	env_tmp_ini(&new, d, env, scmd);
	tmp = create_tmp_env(d, *env, scmd + d->i, 0);
	while (scmd[d->i] && ft_strchr(scmd[d->i], '='))
		d->i++;
	if (scmd[d->i] && ft_strequ(scmd[d->i], "env") && !scmd[d->i + 1])
		return (env_tmp_exec_end_1(cmd, new, tmp));
	new_str = ft_strdup("");
	while (scmd[d->i])
	{
		new_str = ft_strjoinaf12(new_str, ft_strjoin(" ", scmd[d->i]));
		d->i++;
	}
	if (d->in_env_i == 0)
		exec_cmd(&tmp, parse(new_str, d->heredocs, &tmp, d), d);
	else
	{
		d->in_env_i = 0;
		exec_cmd(&new, parse(new_str, d->heredocs, &new, d), d);
	}
	free(new_str);
	return (env_tmp_exec_end_2(new, tmp, d));
}
