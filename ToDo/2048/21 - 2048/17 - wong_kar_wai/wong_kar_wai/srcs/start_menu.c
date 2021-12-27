/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:44:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/01 19:41:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <ncurses.h>

static void		print_score(t_env *env)
{
	printw("          Best score: %d\n\n", env->best_score);
}

void			start_menu(t_env *env)
{
	t_menu			menu;
	int				select;
	const char		*choices[] = {"Play", "Options", "Quit"};

	menu = (t_menu){(char**)choices, 0, 3, &print_score};
	while (1)
	{
		select = select_menu(env, &menu);
		if (select == 0)
			reset_game(env);
		else if (select == 1)
			option_menu(env);
		else if (select == -1 || select == 2)
			break ;
	}
}
