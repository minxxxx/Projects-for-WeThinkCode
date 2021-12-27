/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:10:50 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/25 18:09:32 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		dup_std_fd(int *fd)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (fd[i] == -1)
			close(i);
		else if (fd[i] != i)
		{
			if (dup2(fd[i], i) == -1)
				return (exec_error(6, "dup2"));
		}
		i++;
	}
	return (0);
}

void	close_and_reset_fd(int *fd)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((fd[i] != -1) && (fd[i] != i) && (fd[i] > 2))
			close(fd[i]);
		fd[i] = i;
		i++;
	}
}
