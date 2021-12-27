#include "npuzzle.h"

int list_contents_state(t_env *env, t_state_list *lst, t_state *state)
{
	t_state_list *tmp;

	tmp = lst;
	while (tmp)
	{
		if (equals_state(env, tmp->state, state))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
