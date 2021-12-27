/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:03:02 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/10 15:41:16 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../printf/libft/libft.h"
# include "../printf/ft_printf.h"
# define SA data->tab_f[0].f(&data->lst_a, &data->lst_b)
# define SB data->tab_f[1].f(&data->lst_a, &data->lst_b)
# define SS data->tab_f[2].f(&data->lst_a, &data->lst_b)
# define PA data->tab_f[3].f(&data->lst_a, &data->lst_b)
# define PB data->tab_f[4].f(&data->lst_a, &data->lst_b)
# define RA data->tab_f[5].f(&data->lst_a, &data->lst_b)
# define RB data->tab_f[6].f(&data->lst_a, &data->lst_b)
# define RR data->tab_f[7].f(&data->lst_a, &data->lst_b)
# define RRA data->tab_f[8].f(&data->lst_a, &data->lst_b)
# define RRB data->tab_f[9].f(&data->lst_a, &data->lst_b)
# define RRR data->tab_f[10].f(&data->lst_a, &data->lst_b)
# define AA data->lst_a->val
# define AB data->lst_a->next->val
# define AZ data->lst_a->prev->val
# define BA data->lst_b->val
# define BB data->lst_b->next->val
# define BZ data->lst_b->prev->val

enum {B = 1, C = 2, D = 4, P = 8, U = 16, V = 32};

typedef struct		s_lst
{
	int				exval;
	int				val;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_grp
{
	int				group;
	struct s_grp	*next;
}					t_grp;

typedef struct		s_tab
{
	char			*str;
	int				(*f)(t_lst **a, t_lst **b);
}					t_tab;

typedef struct		s_all
{
	t_lst			*lst_a;
	t_lst			*lst_b;
	t_tab			*tab_f;
	int				round;
	int				moves;
}					t_all;

int					ft_check_av(int ac, char **av);
void				ft_color_choices(int opt, int zone);
int					ft_random_4(int *arr, int ch);
void				ft_random_3(t_all *data, int opt, int ch);
int					ft_random_2(t_all *data, int ch);
void				ft_lstclean(t_lst **alst);
void				ft_deltab(char **tab);
void				ft_print_2stack(t_lst *lst_a, t_lst *lst_b);
void				ft_bubble_algo(t_all *data);
int					ft_are_sorted_a_but(t_lst *lst);
void				opts_cmds(t_all *data, int opt);
char				**option_check(char **av, int ac, int *opt);
int					ft_take_com(char *com, t_all *data, int opt);
int					loop_spot(t_lst *a, int sv);
t_lst				*change_lst(t_lst *a);
t_grp				*ft_first_push(t_all **data, int elem_lst_a, t_grp *lst);
int					ft_quicksort(t_all *data);
int					ft_move_on_b(t_all *data, int middle, int max, int back);
int					ft_move_on_a(t_all *data, int middle, int *max, int back);
int					ft_lstlen(t_lst *lst);
int					ft_find_middle(t_lst *lst, int k, int len);
int					ft_are_sorted_a_exval(t_lst *lst);
int					ft_are_sorted_a_val(t_lst *lst);
int					ft_errors(t_lst *a, int len, int i);
int					ft_are_int(int ac, char **av);
int					ft_checker(t_all *data, int opt);
int					ft_solve_a(t_all *data);
int					ft_sort(t_all *data);
int					ft_fill(int ac, char **av, t_all **data);
void				ft_print_stack(t_lst *lst, char c);
int					ft_create_list(t_lst **lst, t_lst *temp);
int					ft_get_list(int ac, char **av, t_lst **lst);
int					ft_s_a(t_lst **a, t_lst **b);
int					ft_s_b(t_lst **a, t_lst **b);
int					ft_s_s(t_lst **a, t_lst **b);
int					ft_p_a(t_lst **a, t_lst **b);
int					ft_p_b(t_lst **a, t_lst **b);
int					ft_r_a(t_lst **a, t_lst **b);
int					ft_r_b(t_lst **a, t_lst **b);
int					ft_r_r(t_lst **a, t_lst **b);
int					ft_rr_a(t_lst **a, t_lst **b);
int					ft_rr_b(t_lst **a, t_lst **b);
int					ft_rr_r(t_lst **a, t_lst **b);
#endif
