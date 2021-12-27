/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:54:40 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/06 18:18:16 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*
** Defining instructions for push_swap
*/
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define NOPE 0

/*
** Coloring stacks (bonus)
*/
# define A 1
# define B 2
# define AB 3

typedef	struct s_op	t_op;

struct				s_op
{
	char			op;
	int				i;
	t_op			*prev;
	t_op			*next;
};

typedef struct		s_display
{
	int				*stack;
	char			stacks;
	char			refresh;
	char			colors;
	char			algo;
	char			is_moves;
	int				moves;
	int				flags;
}					t_display;

/*
** Storing environment - both programs will use a 't_stack' type
*/
typedef struct		s_stack
{
	int				*stack_a;
	int				*stack_b;
	int				*tab_med;
	int				tab_med_i;
	int				param;
	int				len_a;
	int				len_b;
	char			op_ok;
	int				med;
	int				is_med;
	int				med_pushed;
	int				dist;
	int				min;
	int				max;
	char			first_round;
	t_op			**op;
	int				moves;
	char			display_stacks;
	t_display		bonus;
}					t_stack;

typedef struct		s_rm
{
	t_op			*tmp;
	t_op			*tmp2;
	int				doit;
}					t_rm;

/*
** CHECKER
*/
int					get_operations(char *line, t_stack *e);

/*
** PUSH_SWAP
*/
void				push_swap(t_stack *e);

/*
** Get stacks' features
*/
int					get_med(int *st, int len);
int					get_min(int *st, int len);
int					get_max(int *st, int len);
int					get_next_med(t_stack *e, int *st, int size);
int					get_dist_to_med(int *st, int size, int next_med);
int					is_not_ranked(t_stack *e, int *st, int len);
int					is_sorted(int *st, int len, int start, int inc);

/*
** Two sorting algorithms
*/
void				simple_sort(t_stack *e);
void				quick_sort(t_stack *e);

int					next_target(int *st, int len, int target, char comp);
void				do_op(t_stack *e, char op);
void				send_op(t_stack *e, char op, char algo);
void				proceed_op(t_stack *e, char op);
void				store_op(t_stack *e, char op);
void				split_a(t_stack *e, int *st);
void				split_b(t_stack *e, int *st);

/*
** Replacing or removing wrong instructions
*/
void				delete_ops(t_op **op);
void				replace_ops(t_op **op);

int					ft_end(int status);

/*
** Bonus: display
*/
void				parse_display(char **argv, t_display *dsp);
void				display_stacks(t_stack *e, char c, char op);

#endif
