
#include "npuzzle.h"

int	get_score(t_env *env, t_state *s1, t_state *s2)
{
	if (env->algo == 1)
		return (manhattan(env, s1, s2));
	else if (env->algo == 2)
		return (misplaced(env, s1, s2));
	return (row_column(env, s1, s2));
}
