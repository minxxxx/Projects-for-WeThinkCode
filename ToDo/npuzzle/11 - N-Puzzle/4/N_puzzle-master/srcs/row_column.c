#include "npuzzle.h"

/*static int row_column_sub(t_env *env, t_state *s1, t_state *s2, int nb)
{
	int stateX = 0;
	int stateY = 0;
	int endX = 0;
	int endY = 0;

	for (stateY = 0; stateY < env->size; ++stateY)
	{
		for (stateX = 0; stateX < env->size; ++stateX)
		{
			if (s1->puzzle[stateY][stateX] == nb)
				goto secondLoop;
		}
	}
secondLoop:
	for (endY = 0; endY < env->size; ++endY)
	{
		for (endX = 0; endX < env->size; ++endX)
		{
			if (s2->puzzle[endY][endX] == nb)
				goto endThing;
		}
	}
endThing:
	return ((stateX != endX ? 1 : 0) + (stateY != endY ? 1 : 0));
}

int row_column(t_env *env, t_state *s1, t_state *s2)
{
	int size = env->size * env->size;
	int total;

	total = 0;
	for (int i = 0; i < size; ++i)
	{
		total += row_column_sub(env, s1, s2, i);
		i++;
	}
	return (total);
}*/

static int get_diff(t_env *env, t_state *state, int ax, int ay, int val)
{
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			if (state->puzzle[y][x] == val)
				return ((x != ax ? 1 : 0) + (y != ay ? 1 : 0));
		}
	}
	return (0);
}

int row_column(t_env *env, t_state *s1, t_state *s2)
{
	int total = 0;

	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			total += get_diff(env, s2, x, y, s1->puzzle[y][x]);
		}
	}
	return (total);
}

