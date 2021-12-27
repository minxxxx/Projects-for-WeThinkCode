/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:45:30 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/10 16:00:30 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

static t_all	*ft_main(t_all **data, int ac, char **av)
{
	if (ft_are_int(ac, av) != 0)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	if (ft_fill(ac, av, data) == -1)
		return (NULL);
	if (ft_are_sorted_a_exval((*data)->lst_a) == 0)
		return (NULL);
	if (ft_errors((*data)->lst_a, ft_lstlen((*data)->lst_a), 0) != 0)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	change_lst((*data)->lst_a);
	if (ft_are_sorted_a_but((*data)->lst_a) == 0)
	{
		(*data)->tab_f[0].f(&(*data)->lst_a, &(*data)->lst_b);
		(*data)->moves += ft_printf("%s", "sa\n") / 3;
		return (NULL);
	}
	return (*data);
}

int				ft_check_av(int ac, char **av)
{
	int		i;
	int		k;
	size_t	j;

	i = 0;
	k = 1;
	while (i < ac - 1)
	{
		i++;
		if (av[i][0] == '\0' || av[i][0] == ' ')
		{
			j = 0;
			while (av[i][j] == ' ')
				j++;
			if (av[i][0] == '\0' || j == ft_strlen(av[i]))
				k++;
		}
		if (k == ac)
			return (0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_all	*data;
	int		opt;

	opt = 0;
	data = NULL;
	if (ac == 1)
		return (0);
	if ((ft_check_av(ac, av) == 0))
		return (ft_error());
	if (!(av = option_check(av, ac, &opt)))
		return (0);
	if ((ft_main((&data), ac, av)) == NULL)
	{
		opts_cmds(data, opt);
		return (ft_random_2(data, 0));
	}
	if (opt & B)
		opts_cmds(data, opt);
	(ft_lstlen(data->lst_a) < 5) ? ft_bubble_algo(data) : ft_quicksort(data);
	if (opt & V || opt & P || opt & B || opt & C)
		opts_cmds(data, opt);
	ft_lstclean(&data->lst_a);
	free(data);
	return (0);
}
