/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:13:02 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/01 19:42:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <ncurses.h>
#include <stdlib.h>

static void		print_win(t_env *env)
{
	printw("\n          YOU WIN !!\n\n");
	if (env->score == env->best_score)
		printw("          New Best Score: %d\n\n", env->score);
	else
		printw("          Score: %d\n\n", env->score);
}

void			win_menu(t_env *env)
{
	t_menu			menu;
	int				select;
	const char		*choices[] = {"Continue", "Main Menu", "Quit"};

	if (env->score > env->best_score)
	{
		env->best_score = env->score;
		set_best_score(env->best_score);
	}
	menu = (t_menu){(char**)choices, 0, 3, &print_win};
	select = select_menu(env, &menu);
	if (select == 0)
		start_game(env);
	else if (select == -1 || select == 2)
	{
		endwin();
		exit(0);
	}
}
