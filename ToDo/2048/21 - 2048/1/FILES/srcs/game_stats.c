/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:35:10 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/31 16:43:36 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

void	print_game_stats(t_game_infos *game_infos)
{
	WINDOW	*wind;
	int		i;
	int		win_height;

	win_height = LINES - game_infos->height * game_infos->size;
	wind = create_newwin(win_height,
			game_infos->width * game_infos->size,
			game_infos->size * game_infos->height, 0);
	nodelay(wind, TRUE);
	timeout(1000);
	i = 0;
	while (game_infos->windows[i])
		i++;
	game_infos->windows[i] = wind;
	box(wind, 0, 0);
	mvwprintw(wind, 1, 2, "MOVES: %d", game_infos->moves);
	mvwprintw(wind, 2, 2,
			"TIME: %ld", time(NULL) - game_infos->start_time);
	wrefresh(wind);
}
