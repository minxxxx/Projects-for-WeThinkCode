
#include "npuzzle.h"

void	remove_closed_tree(t_env *env, t_closed_tree *tree, t_state *state)
{
	t_closed_tree *lst;
	int size = env->size * env->size;
	int i = 0;

	lst = tree;
	while (i < size)
	{
		lst = lst->child[state->puzzle[i / 3][i % 3]];
		if (!lst)
		{
			ft_putendl("FAILED OMG");
			exit(EXIT_FAILURE);
			return ;
		}
		++i;
	}
	lst->state = NULL;
}
