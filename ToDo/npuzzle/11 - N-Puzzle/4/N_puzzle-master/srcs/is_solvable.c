#include "npuzzle.h"

static void fill_numbers(t_env *env, int **puzzle, int *numbers)
{
	int y;
	int x;
	int i;

	i = 0;
	y = 0;
	while (y < env->size)
	{
		x = 0;
		while (x < env->size)
		{
			numbers[i++] = puzzle[y][x];
			x++;
		}
		y++;
	}
}

static int get_inversions(t_env *env, int *numbers)
{
	int total;
	int i;
	int j;

	i = 0;
	total = 0;
	while (i < env->size * env->size)
	{
		if (numbers[i] == 0)
		{
			i++;
			continue;
		}
		j = i + 1;
		while (j < env->size * env->size)
		{
			if (numbers[j] != 0 && numbers[j] < numbers[i])
				total++;
			j++;
		}
		i++;
	}
	return (total);
}

static int blank_line(t_env *env, int *tab)
{
	int i;

	i = 0;
	while (i < env->size * env->size)
	{
		if (tab[i] == 0)
		{
			return (i / env->size);
		}
		i++;
	}
	return (0);
}

int is_solvable(t_env *env)
{
	int end_inversions;
	int *end_tab;
	int start_inversions;
	int *start_tab;

	if (!(start_tab = malloc(sizeof(*start_tab) * (env->size * env->size))))
	{
		ft_putendl_fd("npuzzle: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
	fill_numbers(env, env->start->puzzle, start_tab);
	start_inversions = get_inversions(env, start_tab);
	if (!(end_tab = malloc(sizeof(*end_tab) * (env->size * env->size))))
	{
		ft_putendl_fd("npuzzle: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
	fill_numbers(env, env->end->puzzle, end_tab);
	end_inversions = get_inversions(env, end_tab);
	if (env->size % 2 == 0)
	{
		int result = (start_inversions + blank_line(env, start_tab)) % 2 == (end_inversions + blank_line(env, end_tab)) % 2;
		free(start_tab);
		free(end_tab);
		return (result);
	}
	free(start_tab);
	free(end_tab);
	return (start_inversions % 2 == end_inversions % 2);
}
