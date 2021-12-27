/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_difficulty_menu.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:19:48 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/01 20:43:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <ncurses.h>
#include <stdlib.h>

static void		set_difficulty(t_env *env, int nb_rand, int spawn_max)
{
	env->nb_rand = nb_rand;
	env->spawn_max = spawn_max;
}

void			option_difficulty_menu(t_env *env)
{
	t_menu			menu;
	int				select;
	const char		*choices[] = {

	"1 (Easy)        [2]",
	"2 (Normal)      [2] [4]",
	"3 (Hard)        [2] [4] [8]",
	"4 (Extreme)     [2] [4] [8] x2",
	"Cancel"};
	menu = (t_menu){(char**)choices, 0, 5, NULL};
	select = select_menu(env, &menu);
	if (select == -1)
		endwin(), exit(0);
	else if (select == 0)
		set_difficulty(env, 1, 1);
	else if (select == 1)
		set_difficulty(env, 1, 2);
	else if (select == 2)
		set_difficulty(env, 1, 3);
	else if (select == 3)
		set_difficulty(env, 2, 3);
}
