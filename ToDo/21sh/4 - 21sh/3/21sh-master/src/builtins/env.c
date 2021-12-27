/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 20:56:41 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/21 15:30:13 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	put_env(t_env *env_lst)
{
	t_env	*tmp;

	if (env_lst)
	{
		tmp = env_lst;
		while (tmp)
		{
			ft_putstr(tmp->var);
			ft_putchar('=');
			ft_putendl(tmp->val);
			tmp = tmp->next;
		}
	}
	return (0);
}

static int	parse_env_flags(char **cmd, t_env **env_lst)
{
	if (!((*cmd)[1]))
		return (env_error(2, '\0'));
	if ((*cmd)[1] == 'i')
	{
		if ((*cmd)[2])
			return (env_error(0, (*cmd)[2]));
		free_env_lst(env_lst);
	}
	else if ((*cmd)[1] == 'u' && (*cmd)[2])
	{
		del_env_var(env_lst, ft_strdup(*cmd + 2));
		return (1);
	}
	else if ((*cmd)[1] == 'u' && *(cmd + 1))
	{
		del_env_var(env_lst, ft_strdup(*(cmd + 1)));
		return (2);
	}
	else if ((*cmd)[1] == 'u' && !(*(cmd + 1)))
		return (env_error(1, 'u'));
	else
		return (env_error(0, (*cmd)[1]));
	return (1);
}

static int	exec_cmd(char **cmd, t_env *env_lst_cpy)
{
	char	**env_array;

	env_array = NULL;
	if (!(ft_strcmp(cmd[0], "setenv")) || !(ft_strcmp(cmd[0], "unsetenv")))
		env_var_error(2, "env", cmd[0]);
	else if (is_builtin(cmd[0]))
		builtins_cmd(cmd, env_lst_cpy);
	else
	{
		env_array = env_lst_to_array(env_lst_cpy);
		exec_fork(cmd, env_array, env_lst_cpy);
		free_tab(env_array);
	}
	free_env_lst(&env_lst_cpy);
	return (0);
}

int			ft_env(char **cmd, t_env *env_lst, int i)
{
	int		j;
	t_env	*env_lst_cpy;

	env_lst_cpy = NULL;
	dup_env_lst(env_lst, &(env_lst_cpy));
	while (cmd[i])
	{
		j = 0;
		if (cmd[i][0] == '-')
		{
			if ((j = parse_env_flags(cmd + i, &env_lst_cpy)) == -1)
			{
				free_env_lst(&env_lst_cpy);
				return (0);
			}
		}
		else if (ft_strchr(cmd[i], '=') != NULL && ++j)
			ft_setenv(&cmd[i], &env_lst_cpy, 1);
		else
			return (exec_cmd(cmd + i, env_lst_cpy));
		i += j;
	}
	env_lst_cpy != NULL ? put_env(env_lst_cpy) : (0);
	free_env_lst(&env_lst_cpy);
	return (0);
}
