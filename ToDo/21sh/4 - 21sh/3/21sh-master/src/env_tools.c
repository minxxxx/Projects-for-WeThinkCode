/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 12:20:59 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/21 15:26:27 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	*get_env_ptr(t_env *env_lst, char *var)
{
	t_env	*tmp;

	if (!env_lst)
		return (NULL);
	tmp = env_lst;
	while (tmp && (ft_strcmp(tmp->var, var) != 0))
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	return (tmp);
}

int		check_env_var(char *env_var, char *cmd)
{
	int		i;

	i = 0;
	if (!env_var[i] || env_var[i] == '=')
	{
		env_var_error(1, cmd, env_var);
		return (-1);
	}
	while (env_var[i] && env_var[i] != '=')
	{
		if (!ft_isalnum(env_var[i]) && env_var[i] != '_')
		{
			env_var_error(1, cmd, env_var);
			return (-1);
		}
		i++;
	}
	return (0);
}

char	*env_var_to_value(char *var)
{
	char	*value;
	t_env	*env_var;
	t_shell	*shell;

	shell = get_struct(0);
	value = NULL;
	if ((env_var = (get_env_ptr(shell->env_lst, var))))
		value = ft_strdup(env_var->val);
	free(var);
	return (value);
}

int		set_new_pwd(t_env *env_lst)
{
	char	*current_path;
	t_env	*pwd;
	t_shell	*shell;

	current_path = NULL;
	shell = get_struct(0);
	if (!(current_path = getcwd(current_path, MAXPATHLEN)))
		return (cd_error(8, ""));
	if (!(pwd = get_env_ptr(env_lst, "PWD")))
		store_env_var(&(shell->env_lst), ft_strdup("OLDPWD"), ft_strdup(""));
	else
		store_env_var(&(shell->env_lst), ft_strdup("OLDPWD"),
		ft_strdup(pwd->val));
	store_env_var(&(shell->env_lst), ft_strdup("PWD"), current_path);
	return (0);
}
