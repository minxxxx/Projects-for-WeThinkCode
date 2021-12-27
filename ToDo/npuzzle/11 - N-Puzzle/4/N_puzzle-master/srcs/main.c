#include "npuzzle.h"

int main(int argc, char **argv)
{
	t_env env;

	ft_bzero(&env, sizeof(env));
	srand(timing());
	if (argc < 3)
	{
		ft_putendl_fd("npuzzle: use:\nnpuzzle <--manhattan | --misplaced | --row_column> file\nnpuzzle <--manhattan | --misplaced | --row_column> --random size", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_strcmp(argv[1], "--manhattan"))
		env.algo = 1;
	else if (!ft_strcmp(argv[1], "--misplaced"))
		env.algo = 2;
	else if (!ft_strcmp(argv[1], "--row_column"))
		env.algo = 3;
	else
	{
		ft_putendl_fd("npuzzle: invalid algorithm\nuse:\nnpuzzle <--manhattan | --misplaced | --row_column> file\nnpuzzle <--manhattan | --misplaced | --row_column> --random size>", 2);
		exit(EXIT_FAILURE);
	}
	env.start = new_state();
	if (!ft_strcmp(argv[2], "--random"))
	{
		if (argc < 3)
		{
			ft_putendl_fd("npuzzle: use:\nnpuzzle <--manhattan | --misplaced | --row_column> --random size", 2);
			exit(EXIT_FAILURE);
		}
		char *tmp = argv[3];
		while (*tmp == '0')
			tmp++;
		if (!ft_strisdigit(argv[3]) || ft_strlen(tmp) > 3 || (env.size = ft_atoi(tmp)) > 255 || env.size < 2)
		{
			ft_putendl_fd("npuzzle: invalid size, must be integer between 2 and 255\nuse:\nnpuzzle <--manhattan | --misplaced | --row_column> --random size", 2);
			exit(EXIT_FAILURE);
		}
		generate_random(&env);
	}
	else
	{
		read_file(&env, argv[2]);
		if (env.size < 2 || env.size > 255)
		{
			ft_putendl_fd("npuzzle: invalid size, must be integer between 2 and 255\nuse:\nnpuzzle <--manhattan | --misplaced | --row_column> --random size", 2);
			exit(EXIT_FAILURE);
		}
	}
	ft_putendl("start:");
	dump_state(&env, env.start);
	env.end = new_size_state(&env);
	build_end(&env);
	cal_score_state(&env, env.end);
	cal_score_state(&env, env.start);
	ft_putendl("\nend:");
	dump_state(&env, env.end);
	ft_putchar('\n');
	if (is_solvable(&env))
	{
		long start = timing();
		astar(&env);
		printf("solve time: %ld ms\n", timing() - start);
	}
	else
	{
		ft_putendl("This puzzle is not solvable");
	}
	return (1);
	(void)argv;
}
