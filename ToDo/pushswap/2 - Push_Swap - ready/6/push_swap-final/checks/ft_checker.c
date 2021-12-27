/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:39:30 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/11 13:52:02 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_errors(t_lst *a, int len, int i)
{
	int		*arr;
	int		k;
	t_lst	*temp;

	temp = a;
	if (!(arr = malloc(sizeof(int) * len)))
		return (-1);
	arr[i] = a->exval;
	(a->next) ? a = a->next : a;
	while (a != temp)
	{
		k = 0;
		i++;
		arr[i] = a->exval;
		while (k < i)
		{
			arr[i] != arr[k] ? k++ : 0;
			if (arr[i] == arr[k] && i != k)
				return (ft_random_4(arr, -1));
		}
		a = a->next;
	}
	return (ft_random_4(arr, 0));
}

int			ft_check_nbr_size(char *s)
{
	int		x;

	x = 0;
	while (s[x])
	{
		if (s[x] == ' ' || x == 0)
		{
			if (ft_atoll(&s[x]) > INT_MAX)
				return (-1);
			if (ft_atoll(&s[x]) < INT_MIN)
				return (-1);
		}
		x++;
	}
	return (0);
}

int			ft_are_int(int ac, char **av)
{
	int		i;
	int		k;

	i = 1;
	while (i < ac)
	{
		k = 0;
		if (av[i][k + 1] && ((av[i][k] == '-' && ft_isdigit(av[i][k + 1])) ||
		(av[i][k] == '+' && ft_isdigit(av[i][k + 1]))))
			k++;
		while (ft_isdigit(av[i][k]) || av[i][k] == ' ' || (av[i][k] == '-' &&
				av[i][k - 1] == ' ' && ft_isdigit(av[i][k + 1])) ||
				(av[i][k] == '+' && av[i][k - 1] == ' ' &&
				ft_isdigit(av[i][k + 1])))
			k++;
		if (av[i][k])
			return (1);
		if (ft_check_nbr_size(av[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int			ft_take_com(char *com, t_all *data, int opt)
{
	char	**tab;
	int		y;

	tab = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	while (get_next_line(0, &com) > 0)
	{
		y = 0;
		while (tab[y])
		{
			if (ft_strequ(tab[y], com) == 1)
				break ;
			y++;
		}
		ft_strdel(&com);
		if (y > 10)
		{
			ft_deltab(tab);
			return (-1);
		}
		data->tab_f[y].f(&data->lst_a, &data->lst_b);
		ft_random_3(data, opt, 0);
	}
	ft_random_3(data, opt, 1);
	ft_deltab(tab);
	return (0);
}

int			ft_checker(t_all *data, int opt)
{
	int		i;
	char	*com;

	i = 0;
	com = NULL;
	if (ft_errors(data->lst_a, ft_lstlen(data->lst_a), 0) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (ft_take_com(com, data, opt) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	ft_color_choices(opt, 2);
	if (data->lst_a && ft_are_sorted_a_exval(data->lst_a) == 0
		&& (data->lst_b == NULL))
		ft_printf("OK\n");
	else
	{
		ft_color_choices(opt, 1);
		ft_printf("KO\n");
	}
	return (1);
}
