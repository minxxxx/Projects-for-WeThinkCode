/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 12:20:59 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/21 15:44:58 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		dup_env_lst(t_env *env_lst, t_env **env_lst_cpy)
{
	t_env	*tmp;

	tmp = env_lst;
	while (tmp)
	{
		store_env_var(env_lst_cpy, ft_strdup(tmp->var),
				ft_strdup(tmp->val));
		tmp = tmp->next;
	}
	return (0);
}

void	store_environ(t_shell *shell, char **environ)
{
	int		i;
	int		j;
	char	*var;
	char	*val;

	i = 0;
	while (environ[i])
	{
		if ((j = ft_strchr_index(environ[i], '=')) <= 0)
			i++;
		else
		{
			var = ft_strsub(environ[i], 0, j);
			if (!(ft_strcmp(var, "SHLVL")))
				val = ft_itoa(ft_atoi(environ[i] + j + 1) + 1);
			else
				val = ft_strsub(environ[i], j + 1,
						(ft_strlen(environ[i]) - j - 1));
			store_env_var(&(shell->env_lst), var, val);
			i++;
		}
	}
	if (!(get_env_ptr(shell->env_lst, "SHLVL")))
		store_env_var(&(shell->env_lst), ft_strdup("SHLVL"), ft_strdup("1"));
}

int		store_env_var(t_env **env_lst, char *var, char *val)
{
	t_env	*new;
	t_env	*tmp;

	if ((tmp = get_env_ptr(*env_lst, var)))
	{
		free(var);
		free(tmp->val);
		tmp->val = val;
		return (0);
	}
	if (!(new = (t_env *)malloc(sizeof(t_env))))
		quit_error(6);
	new->var = var;
	new->val = val;
	new->next = NULL;
	if (!(*env_lst))
		*env_lst = new;
	else
	{
		tmp = *env_lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}

char	**env_lst_to_array(t_env *env_lst)
{
	int		i;
	char	*tmp;
	t_env	*tmp_env;
	char	**array;

	i = 0;
	if (!env_lst)
		return (NULL);
	tmp_env = env_lst;
	while (tmp_env && ++i)
		tmp_env = tmp_env->next;
	if (!(array = (char **)malloc(sizeof(char *) * (i + 1))))
		quit_error(9);
	tmp_env = env_lst;
	i = 0;
	while (tmp_env)
	{
		tmp = ft_strjoin(tmp_env->var, "=");
		array[i] = ft_strjoin(tmp, tmp_env->val);
		free(tmp);
		tmp_env = tmp_env->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
