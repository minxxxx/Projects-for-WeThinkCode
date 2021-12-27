/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:44:09 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/31 16:16:01 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int		is_victory(t_game_infos *game_infos, int **grid)
{
	int		n;
	int		row;
	int		col;

	n = WIN_VALUE;
	while (n > 2)
	{
		if (n % 2 != 0)
		{
			free_struct(game_infos);
			ft_putendl("WIN_VALUE NOT VALID !");
			exit(0);
		}
		n /= 2;
	}
	row = -1;
	while (++row < game_infos->size && (col = -1))
		while (++col < game_infos->size)
			if (grid[row][col] == WIN_VALUE)
			{
				free_struct(game_infos);
				ft_putendl("YOU WIN !");
				exit(0);
			}
	return (1);
}
