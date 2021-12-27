/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:03:40 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/31 15:04:02 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

void		clear_screen(t_game_infos *game_infos)
{
	int		i;

	i = 0;
	while (game_infos->windows[i])
	{
		delwin(game_infos->windows[i]);
		game_infos->windows[i] = 0;
		i++;
	}
	endwin();
}
