#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_state_list t_state_list;
typedef struct s_state t_state;
typedef struct s_env t_env;
typedef struct s_closed_tree t_closed_tree;

long timing(void);
char *get_next_line(int fd);
void read_file(t_env *env, char *file);
int valid_int(char *str);
void dump_state(t_env *env, t_state *state);
void push_list_state(t_state_list **lst, t_state *state);
void remove_list_state(t_state_list **lst, t_state *state);
t_state_list *get_list_state(t_env *env, t_state_list *lst, t_state *state);
void astar(t_env *env);
t_state *new_state();
void build_end(t_env *env);
t_state *new_size_state(t_env *env);
int equals_state(t_env *env, t_state *s1, t_state *s2);
int list_contents_state(t_env *env, t_state_list *lst, t_state *state);
void free_list_state(t_state_list *lst);
void free_state(t_env *env, t_state *state);
t_state_list *expend_state(t_env *env, t_state *state);
t_state *copy_state(t_env *env, t_state *from);
int manhattan(t_env *env, t_state *s1, t_state *s2);
void generate_random(t_env *env);
int is_solvable(t_env *env);
long timing(void);
void print_solution(t_env *env, t_state *state);
int size_list_state(t_state_list *lst);
int misplaced(t_env *env, t_state *s1, t_state *s2);
int row_column(t_env *env, t_state *s1, t_state *s2);
int get_score(t_env *env, t_state *s1, t_state *s2);
void cal_score_state(t_env *env, t_state *state);
int cost_state(t_state *old, t_state *new);
void push_closed_tree(t_env *env, t_closed_tree *tree, t_state *state);
t_state *get_closed_tree(t_env *env, t_closed_tree *tree, t_state *state);
void remove_closed_tree(t_env *env, t_closed_tree *tree, t_state *state);

# define UNIFORM_COST 0

struct s_closed_tree
{
	t_state *state;
	t_closed_tree **child;
};

struct s_env
{
	t_state *start;
	t_state *end;
	int size;
	int algo;
};

struct s_state_list
{
	t_state *state;
	t_state_list *next;
};

struct s_state
{
	t_state *pred;
	int **puzzle;
	int f;
	int g;
	int h;
};

#endif
