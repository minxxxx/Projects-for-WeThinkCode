/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_best_score.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:58:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/01 17:42:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void			set_best_score(int score)
{
	int				fd;

	fd = open("best_score.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	ft_putnbr_fd(score, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
}
