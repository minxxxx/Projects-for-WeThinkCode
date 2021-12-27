/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:12:46 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/17 22:58:41 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"
#include "ft_player.h"

char			**ft_init_grid(t_grid *grid)
{
	int	i;
	int	j;

	if (!(grid->grid = (char **)malloc(grid->height * sizeof(char *))))
		return (NULL);
	j = 0;
	while (j < grid->height && (grid->grid[j] = (char *)malloc(grid->width)))
	{
		i = 0;
		while (i < grid->width)
			grid->grid[j][i++] = VOIDCASE;
		j++;
	}
	return (j == grid->height ? grid->grid : NULL);
}

static void		ft_printwin(int fin, int player)
{
	if (fin == 1 && player == 0)
		ft_putendl("player 1 is the winner!");
	else if (fin == 1 && player == 1)
		ft_putendl("player 2 is the winner!");
	else
		ft_putendl(FULL);
}

void			ft_freegrid(t_grid *grid)
{
	int			i;

	i = 0;
	while (i < grid->height)
	{
		free(grid->grid[i]);
		i++;
	}
	free(grid->grid);
}

void			ft_puissance4(t_grid *grid)
{
	t_player	players[2];
	int			ans;
	int			fin;
	int			player;

	if (!(grid->grid = ft_init_grid(grid)))
		return ;
	players[0] = g_playertab[0];
	if ((ans = ft_getplayer()) < 0)
		return ;
	players[1] = g_playertab[ans];
	player = ft_playerbegin();
	ft_printgrid(grid);
	fin = 0;
	while (!(fin = ft_checkwin(grid, player)))
	{
		player = !player;
		if (!(ans = players[player].f(grid, player)))
			return ;
		ft_fillgrid(player, ans, grid);
	}
	grid->graphique == 1 ? ft_printwing(fin, player) : ft_printwin(fin, player);
	ft_freegrid(grid);
}

int				main(int argc, char **argv)
{
	t_grid		grid;

	grid.graphique = 0;
	if (argc == 3 && argv[1] && argv[2])
	{
		grid.height = ft_atoi(argv[1]);
		grid.width = ft_atoi(argv[2]);
		if (grid.height >= 6 && grid.width >= 7)
			ft_puissance4(&grid);
		else
			ft_error_size(argv[1], argv[2]);
	}
	else
		ft_error_args(argv[0]);
	return (0);
}
