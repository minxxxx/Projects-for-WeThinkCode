/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 22:30:26 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/17 22:31:56 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

static int	ft_recursive_ai(t_grid *grid, int player, int iter)
{
	int		col;
	int		coup;
	int		maxcoup;

	if (iter < 1 || ft_checkwin(grid, !player))
		return (0);
	col = 0;
	maxcoup = INT_MIN;
	while (col < grid->width)
	{
		if (grid->grid[0][col] == VOIDCASE)
		{
			coup = ft_count(grid, col, player);
			ft_simufill(grid, col, player);
			coup = coup - ft_recursive_ai(grid, !player, iter - 1);
			if (coup > maxcoup)
				maxcoup = coup;
			ft_delcoup(grid, col);
		}
		col++;
	}
	return (maxcoup);
}

static int	*ft_ai_init(t_grid *grid, int *col, int *maxcoup)
{
	int		*tab;

	if (!(tab = (int *)malloc((grid->width + 1) * sizeof(int))))
		return (NULL);
	tab[0] = 0;
	*col = 0;
	*maxcoup = INT_MIN;
	return (tab);
}

static void	ft_ai_best_coup(int *tab, int col, int *maxcoup, int coup)
{
	tab[0] = 0;
	ft_addtab(tab, col + 1);
	*maxcoup = coup;
}

int			ft_ai(t_grid *grid, int player, int iter)
{
	int		*tab;
	int		col;
	int		coup;
	int		maxcoup;

	if (!(tab = ft_ai_init(grid, &col, &maxcoup)))
		return (0);
	while (col < grid->width)
	{
		if (grid->grid[0][col] == VOIDCASE)
		{
			coup = ft_count(grid, col, player);
			ft_simufill(grid, col, player);
			coup = coup - ft_recursive_ai(grid, !player, iter - 1);
			if (coup > maxcoup)
				ft_ai_best_coup(tab, col, &maxcoup, coup);
			else if (coup == maxcoup)
				ft_addtab(tab, col + 1);
			ft_delcoup(grid, col);
		}
		col++;
	}
	coup = tab[random() % ft_tabsize(tab)];
	free(tab);
	return (coup);
}
