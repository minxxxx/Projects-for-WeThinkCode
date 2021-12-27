/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 20:56:41 by fkoehler          #+#    #+#             */
/*   Updated: 2016/08/21 14:14:37 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	format_env_var(t_env **env_lst, char *env_var)
{
	int		i;
	char	*var;
	char	*val;
	char	*dup_var;

	val = NULL;
	dup_var = ft_strdup(env_var);
	if (check_env_var(dup_var, "setenv") == -1)
	{
		free(dup_var);
		return (-1);
	}
	if ((i = ft_strchr_index(dup_var, '=')) == -1)
		var = dup_var;
	else
	{
		var = ft_strsub(dup_var, 0, i);
		if (dup_var[i + 1])
			val = ft_strsub(dup_var, i + 1, (ft_strlen(dup_var) - i - 1));
		free(dup_var);
	}
	if (!val)
		val = ft_strdup("");
	store_env_var(env_lst, var, val);
	return (0);
}

int			ft_setenv(char **cmd, t_env **env_lst, int flag)
{
	int		i;

	i = 0;
	if (!cmd[0])
	{
		env_var_error(0, "setenv", "");
		return (-1);
	}
	if (flag == 0)
	{
		while (cmd[i])
		{
			if (format_env_var(env_lst, cmd[i]) == -1)
				return (-1);
			i++;
		}
	}
	else if (flag == 1 && (format_env_var(env_lst, cmd[i]) == -1))
		return (-1);
	return (0);
}
