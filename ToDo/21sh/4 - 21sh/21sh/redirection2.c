/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:22:06 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:09:31 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_redirect_out(char **s, int i)
{
	char	*line;
	int		fd;
	int		out;

	line = NULL;
	while (s[++i] != NULL)
	{
		fd = open(s[i], O_RDWR | O_CREAT | O_APPEND, 0766);
		out = open(".out", O_RDONLY);
		while (fd != -1 && out != -1 && get_next_line(out, &line) > 0)
			ft_putendl_fd(line, fd);
		close(fd);
		close(out);
	}
}
