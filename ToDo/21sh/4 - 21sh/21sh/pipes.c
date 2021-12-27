/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 10:15:45 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 13:13:27 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
*** "in" gives a pipe stdin
*** "out" gives a pipe stdout
*** "set" creates a pipe; "close in" && "close out" close the pipe
*/

int		ft_count_pipes(char *line)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (line[++i] != '\0')
		if (line[i] == '|')
			count++;
	return (count);
}

int		ft_pipe_control_tower(char *line, char *rule)
{
	static int	pipes[2] = {0, 0};
	static int	nb_pipe = 0;

	if (ft_strcmp(rule, "count") == 0)
		nb_pipe = ft_count_pipes(line);
	else if (ft_strcmp(rule, "in") == 0)
		return (pipes[0]);
	else if (ft_strcmp(rule, "out") == 0)
		return (pipes[1]);
	else if (ft_strcmp(rule, "set") == 0)
		return (pipe(pipes));
	else if (ft_strcmp(rule, "close in") == 0)
		return (close(pipes[0]));
	else if (ft_strcmp(rule, "close out") == 0)
		return (close(pipes[1]));
	return (10);
}
