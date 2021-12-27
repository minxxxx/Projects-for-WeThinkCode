/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_size_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:49:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/01 20:16:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <ncurses.h>
#include <stdlib.h>

static void		resize_map(t_env *env, int size)
{
	int				i;

	i = -1;
	while (++i < env->map_size)
		free(env->map[i]);
	free(env->map);
	env->map = MAL(int*, size);
	i = -1;
	while (++i < size)
		env->map[i] = ft_memalloc(S(int, size));
	env->map_size = size;
}

void			option_size_menu(t_env *env)
{
	t_menu			menu;
	int				select;
	const char		*choices[] = {"3x3", "4x4 (Normal)", "5x5", "6x6", "7x7",

	"8x8", "9x9", "10x10", "11x11", "12x12", "13x13", "14x14", "Cancel"};
	menu = (t_menu){(char**)choices, 0, 13, NULL};
	select = select_menu(env, &menu);
	if (select == -1)
		endwin(), exit(0);
	else if (select >= 0 && select <= 11)
		resize_map(env, select + 3);
}
