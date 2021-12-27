/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	delete_elem_var(t_var **list, char *name)
{
	t_var	*ptr;
	t_var	*head;

	head = *list;
	if (ft_strequ(head->name, name))
	{
		ptr = head->next;
		free(head->name);
		free(head->arg);
		free(head);
		*list = ptr;
		return ;
	}
	while (head && head->next)
	{
		if (ft_strequ((head->next)->name, name))
		{
			ptr = head->next->next;
			free(head->next->name);
			free(head->next->arg);
			free(head->next);
			head->next = ptr;
		}
		head = head->next;
	}
}

int		ft_unset(char **scmd, t_env **env, t_cmd *cmd, t_data *data)
{
	int		ret;

	if (!scmd[1])
	{
		putstr_builtin(cmd, "unset: Too few arguments.\n", 2);
		return (1);
	}
	ret = 1;
	if (isset_arg(*env, scmd[1]))
	{
		delete_elem(env, scmd[1]);
		ret = 0;
	}
	if (isset_var(data->var, scmd[1]))
	{
		delete_elem_var(&(data->var), scmd[1]);
		ret = 0;
	}
	return (ret);
}
