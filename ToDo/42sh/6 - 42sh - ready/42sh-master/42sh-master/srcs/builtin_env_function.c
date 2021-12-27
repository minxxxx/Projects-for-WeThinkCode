/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/03 17:50:13 by adomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int				print_env(t_env *new, t_cmd *cmd)
{
	while (new)
	{
		putstr_builtin(cmd, new->name, 1);
		putstr_builtin(cmd, "=", 1);
		putendl_builtin(cmd, new->arg, 1);
		new = new->next;
	}
	return (0);
}

t_env			*copy_env(t_env *env)
{
	t_env	*new;

	new = NULL;
	while (env)
	{
		new = add_elem_end(new, env->name, env->arg);
		env = env->next;
	}
	return (new);
}

static void		create_tmp_env_2(t_env **tmp, t_data *data)
{
	if (isset_arg(*tmp, data->new_elem[0]))
		change_arg(*tmp, data->new_elem[0], data->new_elem[1]);
	else
		*tmp = add_elem_end(*tmp, data->new_elem[0], data->new_elem[1]);
}

t_env			*create_tmp_env(t_data *data, t_env *env, char **scmd, int i)
{
	t_env	*tmp;

	tmp = NULL;
	if (data->in_env_i != 1)
		tmp = copy_env(env);
	if (scmd[i] && ft_strchr(scmd[i], '='))
	{
		while (scmd[i] && ft_strchr(scmd[i], '='))
		{
			data->new_elem = ft_strsplit(scmd[i], '=');
			if (!data->new_elem[1])
			{
				data->tmp_var_env = mallocp(3 * sizeof(char*));
				data->tmp_var_env[0] = ft_strdup(data->new_elem[0]);
				data->tmp_var_env[1] = ft_strdup("");
				data->tmp_var_env[2] = NULL;
				free_char_tab(data->new_elem);
				data->new_elem = data->tmp_var_env;
			}
			create_tmp_env_2(&tmp, data);
			i++;
			free_char_tab(data->new_elem);
		}
	}
	return (tmp);
}
