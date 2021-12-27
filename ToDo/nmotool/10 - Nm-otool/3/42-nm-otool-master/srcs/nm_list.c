/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:50:55 by jtranchi          #+#    #+#             */
/*   Updated: 2018/02/26 22:53:16 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

static void		push_list_next(t_lt *tmp, t_lt *new)
{
	while (tmp)
	{
		if (!tmp->next)
		{
			tmp->next = new;
			break ;
		}
		if (ft_strcmp(tmp->next->str, new->str) > 0)
		{
			new->next = tmp->next;
			tmp->next = new;
			break ;
		}
		if (ft_strcmp(tmp->next->str, new->str) == 0)
		{
			if (tmp->next->value > new->value)
			{
				new->next = tmp->next;
				tmp->next = new;
				break ;
			}
		}
		tmp = tmp->next;
	}
}

static void		push_list(t_lt **lt, t_lt *tmp, t_lt *new)
{
	if (ft_strcmp(tmp->str, new->str) > 0)
	{
		new->next = tmp;
		*lt = new;
		return ;
	}
	if (ft_strcmp(tmp->str, new->str) == 0)
	{
		if (tmp->value > new->value)
		{
			new->next = tmp;
			*lt = new;
			return ;
		}
	}
	push_list_next(tmp, new);
}

void			add_list_64(t_lt **lt, char *str, struct nlist_64 array)
{
	t_lt *new;
	t_lt *tmp;

	tmp = *lt;
	new = (t_lt*)malloc(sizeof(t_lt));
	new->value = array.n_value;
	new->type = array.n_type;
	new->sect = array.n_sect;
	new->str = str;
	new->next = NULL;
	if (!*lt)
		*lt = new;
	else
		push_list(lt, tmp, new);
}

void			add_list_32(t_lt **lt, char *str, struct nlist array)
{
	t_lt *new;
	t_lt *tmp;

	tmp = *lt;
	new = (t_lt*)malloc(sizeof(t_lt));
	new->value = array.n_value;
	new->type = array.n_type;
	new->sect = array.n_sect;
	new->str = str;
	new->next = NULL;
	if (!*lt)
		*lt = new;
	else
		push_list(lt, tmp, new);
}
