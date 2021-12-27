/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:41:10 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/01 19:43:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <ncurses.h>
#include <stdlib.h>

static void		print_end(t_env *env)
{
	printw("\n          YOU LOSE !!\n\n");
	if (env->score == env->best_score)
		printw("          New Best Score: %d\n\n", env->score);
	else
		printw("          Score: %d\n\n", env->score);
}

void			end_menu(t_env *env)
{
	t_menu			menu;
	const char		*choices[] = {"Quit"};

	if (env->score > env->best_score)
	{
		env->best_score = env->score;
		set_best_score(env->best_score);
	}
	menu = (t_menu){(char**)choices, 0, 1, &print_end};
	select_menu(env, &menu);
	endwin();
	exit(0);
}
