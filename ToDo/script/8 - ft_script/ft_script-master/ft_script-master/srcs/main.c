/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:41:51 by jcamhi            #+#    #+#             */
/*   Updated: 2018/07/04 16:41:57 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

int	main(int ac, char **av, char **envp)
{
	int		pid;
	int		pipes[2];
	t_opt	opt;

	if (!parse(ac, av, envp, &opt))
		return (1);
	ft_bzero(&pipes, sizeof(pipes));
	if (pipe(pipes) == -1)
	{
		ft_putstr_fd("Error while piping.\n", 2);
		return (2);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Error while forking.\n", 2);
		return (3);
	}
	if (pid != 0)
		parent(pipes[1], &opt, pid);
	else
		child(pipes[0], &opt);
	return (0);
}
