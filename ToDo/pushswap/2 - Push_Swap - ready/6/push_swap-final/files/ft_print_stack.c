/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:13:24 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/10 15:42:56 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_print_stack(t_lst *lst, char c)
{
	t_lst	*tmp;

	if (!(lst))
		return ;
	tmp = lst->prev;
	(c == 'A') ? write(1, "\x1B[35m", 5) : write(1, "\x1B[32m", 5);
	ft_printf("\n|---Stack_%c---|\n", c);
	while (lst != tmp)
	{
		ft_printf("|%13d|\n", (lst)->exval);
		(lst) = (lst)->next;
	}
	if (tmp)
		ft_printf("|%13d|\n", (lst)->exval);
	ft_printf("|-------------|\n");
}

void		ft_lstclean(t_lst **alst)
{
	t_lst *temp;

	if (alst == NULL)
		return ;
	temp = *alst;
	while (temp->next != *alst)
	{
		free(temp);
		temp = temp->next;
	}
	free(temp);
	*alst = NULL;
}

int			loop_spot(t_lst *a, int sv)
{
	t_lst	*tmp;
	int		x;

	x = 0;
	tmp = a;
	while (tmp->next != a)
	{
		if (sv > tmp->exval)
			x++;
		tmp = tmp->next;
	}
	if (sv > tmp->exval)
		x++;
	return (x);
}

t_lst		*change_lst(t_lst *a)
{
	t_lst	*tmp2;
	int		sv;
	int		x;

	if (!a)
		return (NULL);
	tmp2 = a;
	x = 0;
	while (tmp2->next != a)
	{
		sv = tmp2->exval;
		x = loop_spot(a, sv);
		tmp2->val = x;
		tmp2 = tmp2->next;
	}
	sv = tmp2->exval;
	x = loop_spot(a, sv);
	tmp2->val = x;
	return (tmp2);
}

int			ft_are_sorted_a_but(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst->prev;
	lst = lst->next->next;
	while (lst != tmp)
	{
		if (lst->val == (lst->next->val - 1))
			lst = lst->next;
		else
			return (1);
	}
	if (tmp->next->val == 1 && tmp->next->next->val == 0)
		return (0);
	return (1);
}
