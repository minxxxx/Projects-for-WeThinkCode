/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 21:15:09 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/31 16:25:14 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WKW_H
# define WKW_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <ncurses.h>

enum	e_const
{
	WIN_VALUE = 64
};

typedef struct	s_game_infos
{
	int		**grid;
	WINDOW	**windows;
	int		size;
	int		height;
	int		width;
	time_t	start_time;
	int		moves;
}				t_game_infos;

void			print_grid(t_game_infos *game_infos);
void			free_struct(t_game_infos *game_infos);

void			clear_screen(t_game_infos *game_infos);

int				wk_move_left(int **grid, int size);
int				wk_test_left(int **grid, int size);
int				wk_move_right(int **grid, int size);
int				wk_test_right(int **grid, int size);
int				wk_move_down(int **grid, int size);
int				wk_test_down(int **grid, int size);
int				wk_move_up(int **grid, int size);
int				wk_test_up(int **grid, int size);

int				place_number(t_game_infos *game_infos);

void			print_game_stats(t_game_infos *game_infos);
WINDOW			*create_newwin(int height, int width, int starty, int startx);

int				is_victory(t_game_infos *game_infos, int **grid);

#endif
