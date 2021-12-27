/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	delete_list_env(t_env *list)
{
	t_env *tmp;

	while (list)
	{
		tmp = list->next;
		free(list->name);
		free(list->arg);
		free(list);
		list = tmp;
	}
}

void	delete_list_var(t_var *list)
{
	t_var *tmp;

	while (list)
	{
		tmp = list->next;
		free(list->name);
		free(list->arg);
		free(list);
		list = tmp;
	}
}

void	delete_list_env_and_var(t_data *data)
{
	delete_list_env(data->env);
	delete_list_var(data->var);
}

void	reinit_list_auto(t_data *data)
{
	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
}
