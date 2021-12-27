/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:09:25 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/07 15:26:51 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lst_del_2(t_grp **lst)
{
	t_grp	*tmp;

	tmp = *lst;
	if (tmp->group == 0)
	{
		free(tmp);
		tmp = tmp->next;
	}
	*lst = tmp;
}

static void	ft_grpadd(t_grp **alst, t_grp *new)
{
	new->next = *alst;
	*alst = new;
}

t_grp		*ft_first_push(t_all **data, int elem_lst_a, t_grp *lst)
{
	int		middle;
	int		elements;
	int		max;
	t_grp	*lst_new;

	while (elem_lst_a > 3)
	{
		elements = 0;
		middle = ft_find_middle((*data)->lst_a, 0, elem_lst_a);
		if (elem_lst_a > 3)
			max = (elem_lst_a / 2);
		else
			max = elem_lst_a;
		elements = ft_move_on_b(*data, middle, max, 0);
		if (!(lst_new = (t_grp*)malloc(sizeof(t_grp))))
			return (NULL);
		ft_grpadd(&lst, lst_new);
		lst->group = elements;
		elem_lst_a = elem_lst_a - elements;
	}
	return (lst);
}

int			ft_quicksort(t_all *data)
{
	t_grp	*lst;
	int		elem_lst_a;
	int		middle;

	if (ft_are_sorted_a_val(data->lst_a) == 0)
		return (0);
	elem_lst_a = ft_lstlen((data)->lst_a);
	lst = ft_first_push(&data, elem_lst_a, NULL);
	data->round = 1;
	ft_solve_a(data);
	elem_lst_a = 0;
	while (data->lst_b)
	{
		middle = (lst->group > 2) ? \
		ft_find_middle((data)->lst_b, 0, lst->group) : INT_MIN;
		elem_lst_a = ft_move_on_a(data, middle, &lst->group, 0);
		(lst->group == 0 && lst->next) ? ft_lst_del_2(&lst) : 0;
		(ft_are_sorted_a_val((data)->lst_a) == 0) ? elem_lst_a = 0 : 0;
		lst = ft_first_push(&data, elem_lst_a, lst);
		elem_lst_a = ft_solve_a(data);
	}
	free(lst);
	return (1);
}
