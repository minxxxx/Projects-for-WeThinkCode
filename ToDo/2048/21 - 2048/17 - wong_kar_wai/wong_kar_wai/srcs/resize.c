/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:00:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/28 18:22:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <ncurses.h>

t_bool			update_size(t_env *env)
{
	int				w;
	int				h;

	getmaxyx(stdscr, h, w);
	if (h != env->win_height || w != env->win_width)
	{
		env->win_width = w;
		env->win_height = h;
		return (true);
	}
	return (false);
}
