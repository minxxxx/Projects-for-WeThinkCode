/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			ft_env(t_env **env, t_cmd *cmd, t_data *data)
{
	int	i;

	i = 1;
	if (!(cmd->av)[1])
		return (print_env(*env, cmd));
	while ((cmd->av)[i] && (cmd->av)[i][0] == '-')
	{
		if ((cmd->av)[i][1] == '-')
			break ;
		if (ft_strchr((cmd->av)[i], 'i'))
			data->in_env_i = 1;
		i++;
	}
	return (env_tmp_exc(env, data, cmd->av + i, cmd));
}

int			ft_setenv(char **scmd, t_env **env)
{
	if (!scmd[1] || !scmd[2])
		return (1);
	if (isset_arg(*env, scmd[1]))
		change_arg(*env, scmd[1], scmd[2]);
	else
		*env = add_elem_end(*env, scmd[1], scmd[2]);
	return (0);
}

int			ft_unsetenv(char **scmd, t_env **env, t_cmd *cmd)
{
	if (!scmd[1])
	{
		putstr_builtin(cmd, "unsetenv: Too few arguments.\n", 2);
		return (1);
	}
	if (!isset_arg(*env, scmd[1]))
		return (1);
	delete_elem(env, scmd[1]);
	return (0);
}

int			exec_builtin(t_cmd *cmd, t_env **env, t_data *data)
{
	if (ft_strequ((cmd->av)[0], "cd"))
		return (cd((cmd->av), env, data, cmd));
	else if (ft_strequ((cmd->av)[0], "env"))
		return (ft_env(env, cmd, data));
	else if (ft_strequ((cmd->av)[0], "setenv"))
		return (ft_setenv((cmd->av), env));
	else if (ft_strequ((cmd->av)[0], "unsetenv"))
		return (ft_unsetenv((cmd->av), env, cmd));
	else if (ft_strequ((cmd->av)[0], "exit"))
		return (ft_exit_bi((cmd->av), *env, data));
	else if (ft_strequ((cmd->av)[0], "echo"))
		return (ft_echo((cmd->av) + 1, cmd));
	else if (ft_strequ((cmd->av)[0], "history"))
		return (ft_history((cmd->av) + 1, data, cmd));
	else if (ft_strequ((cmd->av)[0], "setvar"))
		return (ft_setvar((cmd->av), data, cmd));
	else if (ft_strequ((cmd->av)[0], "unset"))
		return (ft_unset((cmd->av), env, cmd, data));
	else if (ft_strequ((cmd->av)[0], "export"))
		return (ft_export((cmd->av), env, cmd));
	return (0);
}
