#include "npuzzle.h"

int misplaced(t_env *env, t_state *s1, t_state *s2)
{
	int total;

	total = 0;
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			if (s1->puzzle[y][x] != 0 && s1->puzzle[y][x] != s2->puzzle[y][x])
				++total;
		}
	}
	return (total);
}
