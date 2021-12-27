/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:16:18 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/11 13:29:11 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					ft_create_list(t_lst **lst, t_lst *temp)
{
	if (!(*lst))
		*lst = temp;
	else if (!((*lst)->next))
	{
		temp->prev = *lst;
		(*lst)->prev = temp;
		(*lst)->next = temp;
	}
	else
	{
		temp->prev = (*lst)->prev;
		(*lst)->prev->next = temp;
		(*lst)->prev = temp;
	}
	return (1);
}

int					ft_fill(int ac, char **av, t_all **data)
{
	static t_tab	f[] = {{"sa", ft_s_a}, {"sb", ft_s_b}, {"ss", ft_s_s},
		{"pa", ft_p_a}, {"pb", ft_p_b}, {"ra", ft_r_a}, {"rb", ft_r_b},
		{"rr", ft_r_r}, {"rra", ft_rr_a}, {"rrb", ft_rr_b}, {"rrr", ft_rr_r},
		{NULL, NULL}};

	if (!(*data = (t_all*)malloc(sizeof(t_all))))
		return (-1);
	(*data)->lst_a = NULL;
	(*data)->lst_b = NULL;
	(*data)->round = 0;
	(*data)->tab_f = f;
	(*data)->moves = 0;
	if ((ft_get_list(ac, av, &((*data)->lst_a))) == -1)
		return (-1);
	return (1);
}

static int			ft_list(t_lst **lst, int nb)
{
	t_lst			*temp;

	if (!(lst))
		return (-1);
	if (!(temp = (t_lst*)malloc(sizeof(t_lst))))
		return (-1);
	temp->exval = nb;
	temp->val = 0;
	temp->prev = NULL;
	temp->next = !(*lst) ? NULL : *lst;
	ft_create_list(lst, temp);
	return (1);
}

void				ft_deltab(char **tab)
{
	int				y;

	y = 0;
	if (tab)
	{
		while (tab[y])
		{
			free(tab[y]);
			tab[y] = NULL;
			y++;
		}
		free(tab);
		tab = NULL;
	}
}

int					ft_get_list(int ac, char **av, t_lst **lst_a)
{
	int				i;
	int				j;
	char			**tab;

	i = 1;
	while (i < ac)
	{
		tab = ft_strsplit(av[i], ' ');
		j = 0;
		while (tab[j])
		{
			if (ft_strlen(tab[j]) > 11)
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			if (!(ft_list(lst_a, ft_atoi(tab[j++]))))
				return (-1);
		}
		ft_deltab(tab);
		i++;
	}
	return (1);
}
