/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:27:13 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 06:27:15 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void print_usage()
{
	fprintf(stderr, "usage:\n");
	fprintf(stderr, "npuzzle <--manhattan | --misplaced | --row_column | --euclidean> [-g | -u] file\n");
	fprintf(stderr, "npuzzle <--manhattan | --misplaced | --row_column | --euclidean> [-g | -u] --random 3\n");
}


int		main(int argc, char **argv)
{
	t_env	env;
	int i = 1;

	//ft_bzero(&env, sizeof(env)); // this is to avoid segfaults
	memset(&env, 0, sizeof(env)); // this is to avoid segfaults 
	srand(timing());
	if (argc < 3)
	{
		//ft_putendl_fd("npuzzle: use:\nnpuzzle <--manhattan | --misplaced | --row_column> file\nnpuzzle <--manhattan | --misplaced | --row_column> --random size", 2);
		print_usage();
		exit(EXIT_FAILURE);
	}
	//if (!ft_strcmp(argv[1], "--manhattan")) // can use this rather. Was testing the out put is the same
	if (!strcmp(argv[i], "--manhattan"))
 		env.algo = 1; //which algo to use
 	//else if (!ft_strcmp(argv[1], "--misplaced"))
 	else if (!strcmp(argv[i], "--misplaced"))
 		env.algo = 2; //picks the algo to use
 	//else if (!ft_strcmp(argv[1], "--row_column"))
 	else if (!strcmp(argv[i], "--row_column"))
 		env.algo = 3; //picks the algo to use
 	//else if (!ft_strcmp(argv[1], "--euclidean"))
 	else if (!strcmp(argv[i], "--euclidean"))
		env.algo = 4;
 	else
 	{
		//ft_putendl_fd("npuzzle: invalid algorithm\nuse:\nnpuzzle <--manhattan | --misplaced | --row_column> file\nnpuzzle <--manhattan | --misplaced | --row_column> --random size>", 2);
  		print_usage();
  		exit(EXIT_FAILURE);
 	}
 	env.start = new_state();
 	++i;
	if (!strcmp(argv[i], "-g"))
	{
		++i;
		env.greedy = 1;
	}
	else if (!strcmp(argv[i], "-u"))
	{
		++i;
		env.uniform = 1;
	}
 	//if (!ft_strcmp(argv[2], "--random")) // see if they give the same result please
 	if (!strcmp(argv[i], "--random"))
 	{
 		if (argc < 3)
 		{
 			//ft_putendl_fd("npuzzle: use:\nnpuzzle <--manhattan | --misplaced | --row_column> --random size", 2);
  			print_usage();
  			exit(EXIT_FAILURE);
 		}
 		//char *tmp = argv[3];
 		++i;
		char *tmp = argv[i];
 		while (*tmp == '0')
 			tmp++;
 		int k = 0;
		while (tmp[k])
			if (!isdigit(tmp[k++])) // can use ft_isdigit here. i got it in my libft
			{
				fprintf(stderr, "npuzzle: invalid size\n");
				print_usage();
				exit(EXIT_FAILURE);
			}
 		//if (ft_strlen(tmp) > 3 || (env.size = ft_atoi(tmp)) > 255 || env.size < 2)
 		if (strlen(tmp) > 3 || (env.size = atoi(tmp)) > 255 || env.size < 2)
 		{
 			//ft_putendl_fd("npuzzle: invalid size, must be integer between 2 and 255");
  			fprintf(stderr, "npuzzle: invalid size, must be integer between 2 and 255\n");
			print_usage();
  			exit(EXIT_FAILURE);
 		}
 		generate_random(&env);
 	}
 	else
	{

 		read_file(&env, argv[++i]);
		if (env.size < 2 || env.size > 255)
		{			
 			//ft_putendl_fd("npuzzle: invalid size, must be integer between 2 and 255");
			fprintf(stderr, "npuzzle: invalid size, must be integer between 2 and 255\n");
			print_usage();
			exit(EXIT_FAILURE);
		}
	}
	if (argv[++i])
	{
		fprintf(stderr, "npuzzle: too much parameters\n");
		print_usage();
		exit(EXIT_FAILURE);
	}
 	//ft_putendl("start:");
 	printf("start:\n");
 	dump_state(&env, env.start);
 	env.end = new_size_state(&env);
 	build_end(&env);
	cal_score_state(&env, env.end);
	cal_score_state(&env, env.start);
 	//ft_putendl("\nend:");
 	printf("\nend\n:");
 	dump_state(&env, env.end);
 	//ft_putchar('\n');
 	printf("\n");
 	if (is_solvable(&env))
	 {
		 long	start = timing();
		 astar(&env);
		 printf("solve time: %ld ms\n", timing() - start);
	 }
 	else
 		printf("This puzzle is not solvable\n");
 		//ft_putendl("This puzzle is not solvable");
  	return (EXIT_SUCCESS);
 	(void)argv;
}
