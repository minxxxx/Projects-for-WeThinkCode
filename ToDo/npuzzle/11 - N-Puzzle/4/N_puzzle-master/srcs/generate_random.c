#include "npuzzle.h"

static void swap(int **puzzle, int x1, int y1, int x2, int y2)
{
	int tmp;

	tmp = puzzle[y1][x1];
	puzzle[y1][x1] = puzzle[y2][x2];
	puzzle[y2][x2] = tmp;
}

static void shuffle(t_env *env, int **puzzle)
{
	int x;
	int y;

	y = 0;
	while (y < env->size)
	{
		x = 0;
		while (x < env->size)
		{
			swap(puzzle, x, y, rand() / (float)RAND_MAX * (env->size - 1), rand() / (float)RAND_MAX * (env->size - 1));
			x++;
		}
		y++;
	}
}

void generate_random(t_env *env)
{
	if (env->size < 2 || env->size > 255)
	{
		ft_putendl_fd("npuzzle: size must be between 2 and 255", 2);
		exit(EXIT_FAILURE);
	}
	if (!(env->start->puzzle = malloc(sizeof(*env->start->puzzle) * env->size)))
	{
		ft_putendl_fd("npuzzle: failed to malloc", 2);
		exit(EXIT_FAILURE);
	}
	int i = 0;
	while (i < env->size)
	{
		if (!(env->start->puzzle[i] = malloc(sizeof(*env->start->puzzle[i]) * env->size)))
		{
			ft_putendl_fd("npuzzle: failed to malloc", 2);
			exit(EXIT_FAILURE);
		}
		int j = 0;
		while (j < env->size)
		{
			env->start->puzzle[i][j] = i * env->size + j;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < env->size * (1 + rand() / (float)RAND_MAX * 2))
	{
		shuffle(env, env->start->puzzle);
		i++;
	}
}
