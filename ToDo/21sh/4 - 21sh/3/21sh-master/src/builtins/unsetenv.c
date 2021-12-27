/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 20:56:41 by fkoehler          #+#    #+#             */
/*   Updated: 2016/08/26 03:41:44 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		del_env_var(t_env **env_lst, char *var)
{
	t_env	*tmp1;
	t_env	*tmp2;

	if (!(tmp1 = *env_lst))
	{
		free(var);
		return (-1);
	}
	if (ft_strcmp(tmp1->var, var) == 0)
	{
		*env_lst = tmp1->next;
		free_env_var(tmp1);
		free(var);
		return (0);
	}
	while (tmp1->next && ft_strcmp(tmp1->next->var, var) != 0)
		tmp1 = tmp1->next;
	if (tmp1->next)
	{
		tmp2 = tmp1->next->next;
		free_env_var(tmp1->next);
		tmp1->next = tmp2;
	}
	free(var);
	return (0);
}

int		ft_unsetenv(char **cmd, t_env **env_lst)
{
	int		i;
	char	*dup_var;

	i = 1;
	if (!cmd[1])
	{
		env_var_error(0, cmd[0], "");
		return (-1);
	}
	while (cmd[i])
	{
		dup_var = ft_strdup(cmd[i]);
		if (check_env_var(dup_var, cmd[0]) == -1)
		{
			free(dup_var);
			return (-1);
		}
		del_env_var(env_lst, dup_var);
		i++;
	}
	return (0);
}
