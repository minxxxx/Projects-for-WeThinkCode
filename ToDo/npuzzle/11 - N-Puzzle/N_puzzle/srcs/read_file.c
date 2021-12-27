/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:57:47 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/09 11:57:49 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void alloc_puzzle(t_env *env)
{
	int i;

	if (!(env->start->puzzle = malloc(sizeof(*env->start->puzzle) * env->size))) //Checks if the puzzle can allocate memory for it
	{
		ft_putendl_fd("npuzzle: failed to malloc puzzle", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < env->size)
	{
		if (!(env->start->puzzle[i] = malloc(sizeof(**env->start->puzzle) * env->size))) //makes sure that it doesn't go over the size limit
		{
			ft_putendl_fd("npuzzle: failed to malloc puzzle", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static int case_value_exists(t_env *env, int stmp, int i)
{
	int value;
	//int y;
	//int x;

	value = env->start->puzzle[stmp][i];
	//y = 0;
	//will make sure that there are no duplicates in the puzzle
	//uncomment comment to change to while loop.
	for (int y = 0; y < stmp; y++)//while (y < stmp)
	{
		//x = 0;
		for (int x = 0; x < env->size; x++)//while (x < env->size)
		{
			if (env->start->puzzle[y][x] == value)
				return (1);
			//x++;
		}
		//y++;
	}
	//x = 0;
	for (int x = 0; x < i; x++)//while (x < i)
	{
		if (env->start->puzzle[stmp][x] == value)
			return (1);
		//x++;
	}
	return (0);
}

static void fill_line(t_env *env, char *line, int stmp)
{
	char **splitted;
	int i;

	i = 0;
	while (line[i]) //converts all tas to spaces
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	if (!(splitted = ft_strsplit(line, ' '))) //splites all spaces
	{
		ft_putendl_fd("npuzzle: can't split line", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (splitted[i]) //checking the splited string
	{
		if (!valid_int(splitted[i])) //checks if the value is a valid int.
		{
			ft_putendl_fd("npuzzle: invalid case value", 2);
			exit(EXIT_FAILURE);
		}
		env->start->puzzle[stmp][i] = ft_atoi(splitted[i]); // converts to integers
		if (/*env->start->puzzle[stmp][i] < 0 ||*/ env->start->puzzle[stmp][i] > env->size * env->size - 1) //makes sure that it didn't go over the size limit
		{
			ft_putendl_fd("npuzzle: invalid case value", 2);
			exit(EXIT_FAILURE);
		}
		if (case_value_exists(env, stmp, i)) //will make sure that there are no duplicates in the puzzle
		{
			ft_putendl_fd("npuzzle: duplicated case value", 2);
			exit(EXIT_FAILURE);
		}
		free(splitted[i]); //free the momory used 
		i++;
	}
	if (i != env->size) //if they don't match then something went wrong and the puzzles parts do not match.
	{
		ft_putendl_fd("npuzzle: incomplete line", 2);
		exit(EXIT_FAILURE);
	}
	free(splitted); //free the momory used 
}

void read_file(t_env *env, char *file)
{
	char *line;
	char *tmp;
	int stmp;
	int size;
	int fd;

	size = 0;
	stmp = 0;
	// The code below will check that everything is correct. Error checking for days :)
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl_fd("npuzzle: can't open puzzle file", 2);
		exit(EXIT_FAILURE);
	}
	while (ft_strlen((line = get_next_line(fd))) > 0)
	{
		if ((tmp = ft_strchr(line, '#')))
			tmp[0] = '\0';
		tmp = line;
		if (!(line = ft_strtrim(line)))
		{
			ft_putendl_fd("npuzzle: can't trim line", 2);
			exit(EXIT_FAILURE);
		}
		free(tmp);
		if (!line[0])
			continue;
		if (!size)
		{
			tmp = line;
			while (tmp[0] == '0')
				tmp++;
			if (!(ft_strisdigit(tmp)) || ft_strlen(tmp) > 5)
			{
				ft_putendl_fd("npuzzle: invalid puzzle size", 2);
				exit(EXIT_FAILURE);
			}
			stmp = ft_atoi(tmp);
			if (stmp < 2 || stmp > 255)
			{
				ft_putendl_fd("npuzzle: invalid puzzle size (it must be between 2 and 255)", 2);
				exit(EXIT_FAILURE);
			}
			env->size = stmp;
			alloc_puzzle(env); //Will allocate memory for the puzzle size
			size = 1;
			stmp = 0;
		}
		else
		{
			if (stmp > env->size)
			{
				ft_putendl_fd("npuzzle: (given puzzle) size is superior to given (puzzle size)", 2);
				exit(EXIT_FAILURE);
			}
			fill_line(env, line, stmp); //Will read line by line and seperate the numbers. can read if it is tabs or spaces.
			stmp++;
		}
		free(line); //making sure to free the memory allocated
	}
	close(fd);
}
