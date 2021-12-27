/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:57:21 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 17:11:08 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_pushswap
{
	int		*pile_a;
	int		length_a;
	int		smallest_a;
	int		pos_smallest_a;
	int		*pile_b;
	int		length_b;
	char	*sequence;
	int		nb_of_moves;
	int		verbose;
	int		fast;
	int		show_moves;
	int		mute;
}				t_pushswap;

void			push_a(t_pushswap *data, int final);
void			push_b(t_pushswap *data, int final);
void			swap_a(t_pushswap *data, int final);
void			swap_b(t_pushswap *data, int final);
void			swap_ab(t_pushswap *data, int final);
void			rotate_a(t_pushswap *data, int final);
void			rotate_b(t_pushswap *data, int final);
void			rotate_ab(t_pushswap *data, int final);
void			reverse_rotate_a(t_pushswap *data, int final);
void			reverse_rotate_b(t_pushswap *data, int final);
void			reverse_rotate_ab(t_pushswap *data, int final);

void			print_move_with_options(t_pushswap *data, int move, int final);

void			sort_pile(t_pushswap *data);

void			print_pile(int *pile, int length);
void			print_state(t_pushswap *data);

int				check_pile(int *pile, int length);
int				check_pile_reverse(int *pile, int length);
int				ft_isnumber(char *value);
int				check_duplicate(int nb, int *pile, int length);

#endif
