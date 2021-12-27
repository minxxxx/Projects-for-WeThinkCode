/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:39:38 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 19:13:06 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_move_with_options2(t_pushswap *data, int move, int final)
{
	if (data->verbose && data->fast == 0 && data->mute == 0)
	{
		move == 1 ? data->sequence = ft_strjoin(data->sequence, "pa") : NULL;
		move == 2 ? data->sequence = ft_strjoin(data->sequence, "pb") : NULL;
		move == 3 ? data->sequence = ft_strjoin(data->sequence, "rra") : NULL;
		move == 4 ? data->sequence = ft_strjoin(data->sequence, "rrb") : NULL;
		move == 5 ? data->sequence = ft_strjoin(data->sequence, "ra") : NULL;
		move == 6 ? data->sequence = ft_strjoin(data->sequence, "rb") : NULL;
		move == 7 ? data->sequence = ft_strjoin(data->sequence, "sa") : NULL;
		move == 8 ? data->sequence = ft_strjoin(data->sequence, "sb") : NULL;
		if (final == 0)
			data->sequence = ft_strjoin(data->sequence, " ");
	}
}

void	print_move_with_options(t_pushswap *data, int move, int final)
{
	if (data->verbose == 0 && data->mute == 0)
	{
		move == 1 ? ft_putcolor("pa", "yellow") : 1;
		move == 2 ? ft_putcolor("pb", "yellow") : 1;
		move == 3 ? ft_putcolor("rra", "yellow") : 1;
		move == 4 ? ft_putcolor("rrb", "yellow") : 1;
		move == 5 ? ft_putcolor("ra", "yellow") : 1;
		move == 6 ? ft_putcolor("rb", "yellow") : 1;
		move == 7 ? ft_putcolor("sa", "yellow") : 1;
		move == 8 ? ft_putcolor("sb", "yellow") : 1;
		if (final == 0)
			ft_putchar(' ');
		else
			ft_putchar('\n');
	}
	print_move_with_options2(data, move, final);
	if (data->verbose && data->mute == 0)
		print_state(data);
}

int		check_pile(int *pile, int length)
{
	int		i;

	if (length == 1)
		return (1);
	i = 1;
	while (i < length)
	{
		if (pile[i - 1] < pile[i])
			return (0);
		i++;
	}
	return (1);
}

int		check_pile_reverse(int *pile, int length)
{
	int		i;

	if (length == 1)
		return (1);
	i = 1;
	while (i < length)
	{
		if (pile[i - 1] > pile[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_isnumber(char *value)
{
	int		i;

	if ((i = 0) && value[i] == '+' && ft_strlen(value) > 1)
		value++;
	if (value[i] == '-' && ft_strlen(value) > 1)
		i++;
	while (value[i])
	{
		if (!ft_isdigit(value[i]))
			return (0);
		i++;
	}
	if (ft_strlen(value) > 11)
		return (0);
	if (value[0] == '-')
	{
		if (ft_strlen(value) >= 11 && ft_strcmp(value, ft_itoa(INT_MIN)) > 0)
			return (0);
	}
	else
	{
		if (ft_strlen(value) >= 10 && ft_strcmp(value, ft_itoa(INT_MAX)) > 0)
			return (0);
	}
	return (1);
}
