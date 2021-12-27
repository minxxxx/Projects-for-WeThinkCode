/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:30:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/01 20:19:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <ncurses.h>
#include <stdlib.h>

void			option_menu(t_env *env)
{
	t_menu			menu;
	int				select;
	const char		*choices[] = {"Size", "Difficulty", "Reset score", "Back"};

	menu = (t_menu){(char**)choices, 0, 4, NULL};
	while (1)
	{
		select = select_menu(env, &menu);
		if (select == -1)
			endwin(), exit(0);
		else if (select == 0)
			option_size_menu(env);
		else if (select == 1)
			option_difficulty_menu(env);
		else if (select == 2)
		{
			set_best_score(0);
			env->best_score = 0;
			break ;
		}
		else if (select == 3)
			break ;
	}
}
