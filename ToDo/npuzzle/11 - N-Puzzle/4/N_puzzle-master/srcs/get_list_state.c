
#include "npuzzle.h"

t_state_list *get_list_state(t_env *env, t_state_list *lst, t_state *state)
{
	t_state_list *tmp;

	tmp = lst;
	while (tmp)
	{
		if (equals_state(env, tmp->state, state))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

