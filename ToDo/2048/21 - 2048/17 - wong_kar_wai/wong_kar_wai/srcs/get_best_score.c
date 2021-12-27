/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_score.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:50:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/01 17:40:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <fcntl.h>
#include <unistd.h>

int				get_best_score(void)
{
	int				fd;
	char			tmp[11];
	int				len;

	fd = open("best_score.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	len = read(fd, tmp, 10);
	close(fd);
	if (len <= 0)
		return (0);
	tmp[len] = '\0';
	return (ft_atoi(tmp));
}
