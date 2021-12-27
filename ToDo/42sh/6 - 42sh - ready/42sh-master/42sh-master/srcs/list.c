/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static t_env	*create_elem(char *name, char *arg)
{
	t_env	*ret;

	ret = mallocp(sizeof(t_list));
	ret->name = ft_strdup(name);
	ret->arg = ft_strdup(arg);
	ret->next = NULL;
	return (ret);
}

t_env			*add_elem_end(t_env *list, char *name, char *arg)
{
	t_env	*tmp;

	tmp = list;
	if (!list)
		return (create_elem(name, arg));
	while (list->next)
		list = list->next;
	list->next = create_elem(name, arg);
	return (tmp);
}

int				isset_arg(t_env *list, char *name)
{
	while (list)
	{
		if (ft_strequ(name, list->name))
			return (1);
		list = list->next;
	}
	return (0);
}

char			*find_var_env(t_data *data, char *name, t_env *env)
{
	t_var	*list_var;
	t_env	*list_env;

	list_var = data->var;
	list_env = env;
	if (!list_var && !list_env)
		return (ft_strdup(""));
	while (list_env)
	{
		if (ft_strequ(list_env->name, name))
			return (ft_strdup(list_env->arg));
		list_env = list_env->next;
	}
	while (list_var)
	{
		if (ft_strequ(list_var->name, name))
			return (ft_strdup(list_var->arg));
		list_var = list_var->next;
	}
	return (ft_strdup(""));
}

char			*find_arg(t_env *list, char *name)
{
	if (!list)
		return (ft_strdup(""));
	while (list)
	{
		if (ft_strequ(list->name, name))
			return (ft_strdup(list->arg));
		list = list->next;
	}
	return (ft_strdup(""));
}
