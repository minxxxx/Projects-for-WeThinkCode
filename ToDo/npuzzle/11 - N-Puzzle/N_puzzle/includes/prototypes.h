/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       ::      ::    ::   */
/*                                                    : :         :     */
/*   By: ggroener <marvin@42.fr>                    #  :       #        */
/*                                                #####   #           */
/*   Created: 2016/11/09 11:15:09 by ggroener          ##    ##             */
/*   Updated: 2016/11/09 11:58:18 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

char			*get_next_line(int fd);
void			read_file(t_env *env, char *file);
int				valid_int(char *str);
void			dump_puzzle(t_env *env, int **puzzle);
void			dump_state(t_env *env, t_state *state);
void			push_list_state(t_state_list **lst, t_state *state);
void			remove_list_state(t_state_list **lst, t_state *state);
void			astar(t_env *env);
t_state			*new_state();
void 			build_end(t_env *env);
t_state			*new_size_state(t_env *env);
int				equals_state(t_env *env, t_state *s1, t_state *s2);
int				list_contents_state(t_env *env, t_state_list *lst, t_state *state);
void			free_list_state(t_state_list *lst);
void			free_state(t_env *env, t_state *state);
t_state_list	*expend_state(t_env *env, t_state *state);
t_state 		*copy_state(t_env *env, t_state *from);
int				manhattan(t_env *env, t_state *s1, t_state *s2);
void			generate_random(t_env *env);
int				is_solvable(t_env *env);
long			timing(void);
void			print_solution(t_env *env, t_state *state);
int				size_list_state(t_state_list *lst);
int				misplaced(t_env *env, t_state *s1, t_state *s2); // changed to improve
int				row_column(t_env *env, t_state *s1, t_state *s2); // changed to improve
void			cal_score_state(t_env *env, t_state *state);
int				cost_state(t_state *old, t_state *new);
int				get_score(t_env *env, t_state *s1, t_state *s2); // added to get score
t_state_list	*get_list_state(t_env *env, t_state_list *lst, t_state *state);
void            push_tree_state(t_env *env, t_tree_state *tree, t_state *state, int opened); //tree calls
t_state         *get_tree_state(t_env *env, t_tree_state *tree, t_state *state, int *is_closed); //tree calls
void            set_tree_state(t_env *env, t_tree_state *tree, t_state *state, int opened); //tree calls
void            free_tree_state(t_env *env, t_tree_state *node);
int				euclidean(t_env *env, t_state *s1, t_state *s2);

#endif
