/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	change_arg(t_env *list, char *name, char *new_arg)
{
	if (!list)
		return ;
	while (list)
	{
		if (ft_strequ(list->name, name))
		{
			free(list->arg);
			list->arg = ft_strdup(new_arg);
		}
		list = list->next;
	}
}

void	delete_elem(t_env **list, char *name)
{
	t_env	*ptr;
	t_env	*head;

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

void	delete_list(t_env *list)
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

char	**make_env_char(t_env *list)
{
	char	**ret;
	t_env	*tmp;
	int		nb_elem;

	tmp = list;
	nb_elem = 0;
	while (tmp)
	{
		tmp = tmp->next;
		nb_elem++;
	}
	ret = (char**)mallocp(sizeof(char*) * (nb_elem + 1));
	nb_elem = 0;
	while (list)
	{
		ret[nb_elem] = ft_strdup(list->name);
		ret[nb_elem] = ft_strjoinaf1(ret[nb_elem], "=");
		ret[nb_elem] = ft_strjoinaf1(ret[nb_elem], list->arg);
		list = list->next;
		nb_elem++;
	}
	ret[nb_elem] = NULL;
	return (ret);
}
