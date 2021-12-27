/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 20:20:37 by jfrancho          #+#    #+#             */
/*   Updated: 2016/02/02 14:07:44 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <ncurses.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "../libft/libft.h"

enum				e_const
{
	WIN_VALUE = 2048
};

typedef	struct		s_map
{
	int				tab[4][4];
	int				save[4][4];
}					t_map;

int					test_errors(void);
void				init_map(t_map *map);
void				ft_save(t_map *map);
int					ft_diff_save(t_map *map);
int					ft_check_finish(t_map *map);
int					fill_with_rand(t_map *map, int len);

void				right_command(t_map *map);
void				left_command(t_map *map);
void				up_command(t_map *map);
void				down_command(t_map *map);

void				print_map(t_map *map);

#endif
