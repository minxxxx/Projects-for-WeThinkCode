/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:56:32 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/09 11:56:36 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

char *get_next_line(int fd)
{
	ssize_t readed;
	char *result;
	char *buff;
	// will read file line by line
	if (!(buff = malloc(sizeof(*buff) * 2)))
	{
		//ft_putendl_fd("npuzzle: can't malloc", 2);
		fprintf(stderr, "npuzzle: can't malloc");
		exit(EXIT_FAILURE);
	}
	memset(buff, 0, 2);
	if (!(result = malloc(sizeof(*result))))
	{
		//ft_putendl_fd("npuzzle: can't malloc", 2);
		fprintf(stderr, "npuzzle: can't malloc");
		exit(EXIT_FAILURE);
	}
	memset(result, 0, 1);
	while ((readed = read(fd, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
			return (result);
		if (!(result = ft_strjoin_free1(result, buff)))
		{
			//ft_putendl_fd("npuzzle: can't malloc", 2);
			fprintf(stderr, "npuzzle: can't malloc");
			exit(EXIT_FAILURE);
		}
	}
	if (readed == -1)
	{
		//ft_putendl_fd("npuzzle: error while reading puzzle file", 2);
		fprintf(stderr, "npuzzle: error while reading puzzle file");
		exit(EXIT_FAILURE);
	}
	return (result);
}
