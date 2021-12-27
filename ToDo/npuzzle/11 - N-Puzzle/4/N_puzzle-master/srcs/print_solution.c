#include "npuzzle.h"

void print_solution(t_env *env, t_state *state)
{
	if (state != NULL)
	{
		print_solution(env, state->pred);
		dump_state(env, state);
		printf("\n");
	}
}
