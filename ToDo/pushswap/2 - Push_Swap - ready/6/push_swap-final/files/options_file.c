/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:55:39 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/10 15:14:15 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_prt(t_lst *lst, int *len, char c)
{
	if (lst && --(*len) <= 0)
		ft_printf("|%13d|%c", (lst)->exval, c);
	else
		ft_printf("|%14|%c", c);
}

static void	ft_need_space(t_lst *lst_a, t_lst *lst_b, int len_a, int len_b)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp = (lst_a->prev) ? lst_a->prev : lst_a;
	tmp2 = (lst_b->prev) ? lst_b->prev : lst_b;
	write(1, "\x1B[36m", 5);
	ft_printf("\n|---Stack_A---||---Stack_B---|\n");
	while (lst_a != tmp || lst_b != tmp2)
	{
		lst_a != tmp ? ft_prt(lst_a, &len_a, '\0') : ft_prt(NULL, &len_a, '\0');
		lst_b != tmp ? ft_prt(lst_b, &len_b, '\n') : ft_prt(NULL, &len_b, '\n');
		if (lst_a != tmp && len_a <= 0)
			(lst_a) = (lst_a->next != tmp) ? (lst_a)->next : tmp;
		if (lst_b != tmp2 && len_b <= 0)
			lst_b = (lst_b->next != tmp2) ? (lst_b)->next : tmp2;
	}
	if (lst_a)
		ft_printf("|%13d|", (lst_a)->exval);
	if (lst_b)
		ft_printf("|%13d|\n", (lst_b)->exval);
	ft_printf("|-------------||-------------|\n");
}

void		ft_print_2stack(t_lst *lst_a, t_lst *lst_b)
{
	int		i;
	int		len_a;
	int		len_b;

	i = 0;
	if (!(lst_a) && !(lst_b))
		return ;
	(!lst_a && lst_b) ? ft_print_stack(lst_b, 'B') : i++;
	(lst_a && !lst_b) ? ft_print_stack(lst_a, 'A') : i++;
	if (i != 2)
		return ;
	len_a = ft_lstlen(lst_a);
	len_b = ft_lstlen(lst_b);
	if (len_a > len_b)
	{
		len_b = len_a - len_b + 1;
		len_a = 0;
	}
	else
	{
		len_a = len_b - len_a + 1;
		len_b = 0;
	}
	ft_need_space(lst_a, lst_b, len_a, len_b);
}

static void	nbr_of_cmds(t_all *data, int opt)
{
	if (opt & U)
		ft_printf("Nomber of commands : %d for list size : %d\n", data->moves,
		ft_lstlen(data->lst_a));
	else
		ft_printf("Nomber of commands : %d\n", data->moves);
}

void		opts_cmds(t_all *data, int opt)
{
	if (data)
	{
		if (opt & V)
			nbr_of_cmds(data, opt);
		else if (opt & P || opt & B)
			ft_print_stack(data->lst_a, 'A');
	}
}
