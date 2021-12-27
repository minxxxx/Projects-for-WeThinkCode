/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:32:42 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/01 20:27:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

/*
** Colors
** Pair		Color	Nb		Hex			R		G		B
** -		17		white	ffffff		1000	1000	1000
** 20		18		0		bbada0		733		678		627
** 1		19		bg		ab9e92		670		619		572
** 2		20		2		eee4da		933		894		854
** 3		21		4		ede0c8		929		878		784
** 4		22		8		f2b179		949		694		474
** 5		23		16		f59563		960		584		388
** 6		24		32		f67c5f		964		486		372
** 7		25		64		f65e3b		964		368		231
** 8		26		128		edcf72		929		811		447
** 9		27		256		edcc61		929		800		380
** 10		28		512		edc850		929		784		313
** 11		29		1024	edc53f		929		772		247
** 12		30		2048	edc22e		929		760		180
** 13		31		+		3c3a32		235		227		196
*/

static void		init_colors(void)
{
	init_color(17, 1000, 1000, 1000);
	init_color(18, 733, 678, 627);
	init_color(19, 670, 619, 572);
	init_color(20, 933, 894, 854);
	init_color(21, 929, 878, 784);
	init_color(22, 949, 694, 474);
	init_color(23, 960, 584, 388);
	init_color(24, 964, 486, 372);
	init_color(25, 964, 368, 231);
	init_color(26, 929, 811, 447);
	init_color(27, 929, 800, 380);
	init_color(28, 929, 784, 313);
	init_color(29, 929, 772, 247);
	init_color(30, 929, 760, 180);
	init_color(31, 235, 227, 196);
}

static void		init_pairs(void)
{
	init_pair(50, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, 18, 18);
	init_pair(2, COLOR_BLACK, 20);
	init_pair(3, COLOR_BLACK, 21);
	init_pair(4, 17, 22);
	init_pair(5, 17, 23);
	init_pair(6, 17, 24);
	init_pair(7, 17, 25);
	init_pair(8, 17, 26);
	init_pair(9, 17, 27);
	init_pair(10, 17, 28);
	init_pair(11, 17, 29);
	init_pair(12, 17, 30);
	init_pair(13, 17, 31);
	init_pair(20, COLOR_BLACK, 19);
}

static void		init_ncurses(void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	init_colors();
	init_pairs();
}

static void		init_game(t_env *env, int size)
{
	int				i;

	env->map = MAL(int*, size);
	i = -1;
	while (++i < size)
		env->map[i] = ft_memalloc(S(int, size));
	env->map_size = size;
	env->best_score = get_best_score();
	env->nb_rand = 1;
	env->spawn_max = 2;
}

int				main(void)
{
	t_env			env;

	ft_bzero(&env, sizeof(t_env));
	if (!is_power(WIN_VALUE, 2) || WIN_VALUE < 2)
		return (ft_putstr_fd("Error: WIN_VALUE is not valid\n", 2), 1);
	srand(time(NULL));
	init_ncurses();
	init_game(&env, 4);
	update_size(&env);
	start_menu(&env);
	clear();
	refresh();
	endwin();
	return (0);
}
