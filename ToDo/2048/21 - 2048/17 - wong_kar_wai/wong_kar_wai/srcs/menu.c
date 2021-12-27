/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:30:41 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/01 20:12:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <ncurses.h>

static void		print_title(void)
{
	printw(" .----------------.  .----------------."
		"  .----------------.  .----------------. \n"
		"| .--------------. || .--------------. || "
		".--------------. || .--------------. |\n"
		"| |    _____     | || |     ____     | || "
		"|   _    _     | || |     ____     | |\n"
		"| |   / ___ `.   | || |   .'    '.   | || "
		"|  | |  | |    | || |   .' __ '.   | |\n"
		"| |  |_/___) |   | || |  |  .--.  |  | || "
		"|  | |__| |_   | || |   | (__) |   | |\n"
		"| |   .'____.'   | || |  | |    | |  | || "
		"|  |____   _|  | || |   .`____'.   | |\n"
		"| |  / /____     | || |  |  `--'  |  | || "
		"|      _| |_   | || |  | (____) |  | |\n"
		"| |  |_______|   | || |   '.____.'   | || "
		"|     |_____|  | || |  `.______.'  | |\n"
		"| |              | || |              | || "
		"|              | || |              | |\n"
		"| '--------------' || '--------------' || "
		"'--------------' || '--------------' |\n"
		" '----------------'  '----------------'  '"
		"----------------'  '----------------' \n\n");
}

static void		refresh_menu(t_env *env, t_menu *menu)
{
	int				i;

	clear();
	print_title();
	if (menu->print != NULL)
		menu->print(env);
	i = -1;
	while (++i < menu->length)
	{
		if (i == menu->pos)
			printw("         ==> %s\n\n", menu->selects[i]);
		else
			printw("             %s\n\n", menu->selects[i]);
	}
	refresh();
}

int				select_menu(t_env *env, t_menu *menu)
{
	int				key;

	while (1)
	{
		refresh_menu(env, menu);
		key = getch();
		if (key == KEY_UP)
			menu->pos = (menu->pos - 1 + menu->length) % menu->length;
		else if (key == KEY_DOWN)
			menu->pos = (menu->pos + 1) % menu->length;
		else if (key == '\n')
			return (menu->pos);
		else if (key == 27)
			return (-1);
	}
}
