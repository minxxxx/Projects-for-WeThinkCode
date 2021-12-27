
#include "npuzzle.h"

void	push_closed_tree(t_env *env, t_closed_tree *tree, t_state *state)
{
	t_closed_tree *lst;
	t_closed_tree *new;
	int size = env->size * env->size;
	int i;

	i = 0;
	lst = tree;
	while (i < size)
	{
		int nb = state->puzzle[i / 3][i % 3];
		if (lst->child[nb])
		{
			lst = lst->child[nb];
			++i;
			continue;
		}
		if (!(new = malloc(sizeof(*new))))
		{
			ft_putendl_fd("npuzzle: malloc failed", 2);
			exit(EXIT_FAILURE);
		}
		ft_bzero(new, sizeof(*new));
		if (!(new->child = malloc(sizeof(*new->child) * size)))
		{
			ft_putendl_fd("npuzzle: malloc failed", 2);
			exit(EXIT_FAILURE);
		}
		ft_bzero(new->child, sizeof(*new->child) * size);
		lst->child[nb] = new;
		lst = new;
		++i;
	}
	lst->state = state;
}
