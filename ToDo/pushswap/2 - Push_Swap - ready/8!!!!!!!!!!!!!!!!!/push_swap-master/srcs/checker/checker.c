/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:19:19 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/04 18:54:28 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_dup(t_stack e)
{
	int			i;
	int			j;

	i = -1;
	while (++i + 1 < e.param)
	{
		j = -1;
		while (++j < e.param)
		{
			if (i == j && j < e.param)
				++j;
			if (e.stack_a[i] == e.stack_a[j] && i != j)
				return (1);
		}
	}
	return (0);
}

static void		get_instructions(t_stack *e)
{
	char		*line;
	int			ret;
	int			i;

	i = 0;
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			exit(ft_end(3));
		e->op_ok = 0;
		if (!get_operations(line, e))
			exit(ft_end(1));
		i = 0;
		free(line);
	}
}

static void		checker(char **arg, int param)
{
	int			i;
	t_stack		e;

	e.param = param;
	if (!(e.stack_a = ft_memalloc(sizeof(int) * e.param)) ||
			!(e.stack_b = ft_memalloc(sizeof(int) * e.param)))
		exit(ft_end(4));
	e.len_a = e.param;
	e.len_b = 0;
	i = -1;
	while (arg[++i])
	{
		e.stack_a[i] = ft_atoi(arg[i]);
		free(arg[i]);
	}
	free(arg);
	if (find_dup(e))
		exit(ft_end(1));
	get_instructions(&e);
	is_sorted(e.stack_a, e.len_a, 0, 1) &&
	e.len_b == 0 ? exit(ft_end(0)) : exit(ft_end(2));
}

static int		get_format(char **arg)
{
	int			i;
	int			j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
			j++;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]))
				return (0);
			j++;
		}
		if (ft_strlen(arg[i]) > 11 || ft_atoss(arg[i]) > INT_MAX
				|| ft_atoss(arg[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (i);
}

int				main(int argc, char **argv)
{
	char		**arg;
	int			i;
	int			param;

	if (argc < 2)
		return (-1);
	if (argc == 2)
		arg = ft_strsplit(argv[1], ' ');
	else
	{
		if (!(arg = (char**)malloc(sizeof(char*) * (argc))))
			exit(ft_end(4));
		i = -1;
		while (++i + 1 < argc)
			arg[i] = ft_strdup(argv[i + 1]);
		arg[i] = NULL;
	}
	if (!(param = get_format(arg)))
		exit(ft_end(1));
	checker(arg, param);
	return (0);
}
