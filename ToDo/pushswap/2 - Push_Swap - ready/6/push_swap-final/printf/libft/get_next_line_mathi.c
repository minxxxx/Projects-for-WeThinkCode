/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:19:15 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/30 14:28:42 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		line_cpy(char **line, char **s)
{
	int			x;
	int			len;
	char		*tmp;

	x = 0;
	len = ft_strlen(*line);
	while (line[0][x] && line[0][x] != '\n')
		x++;
	tmp = *s;
	if (line[0][x + 1])
		tmp = ft_strncpy(*s, &(line[0][x + 1]), len - x);
	else
		ft_bzero(*s, BUFF_SIZE + 1);
	line[0][x] = '\0';
	return (1);
}

static int		get_line(char **s, char **line, int fd)
{
	char		*tmp;
	int			eof;

	tmp = NULL;
	while ((ft_strchr(line[0], '\n')) == NULL &&
			(eof = read(fd, s[fd], BUFF_SIZE)) > 0)
	{
		s[fd][eof] = '\0';
		if (eof > 0)
		{
			tmp = line[0];
			if (!(line[0] = ft_strjoin_free(tmp, s[fd], 1)))
				return (-1);
			ft_bzero(s[fd], BUFF_SIZE + 1);
		}
	}
	return (eof);
}

int				get_next_line_mathi(int fd, char **line)
{
	static char	**s = NULL;
	int			eof;

	if (fd < 0 || fd > OPEN_MAX || BUFF_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	if (!s)
		if (!(s = (char**)malloc(sizeof(char*) * OPEN_MAX + 1)))
			return (-1);
	if (!s[fd])
		if (!(s[fd] = (char*)ft_memalloc(BUFF_SIZE + 1)))
			return (-1);
	if (s[fd])
		if (!(*line = ft_strjoin(*line, s[fd])))
			return (-1);
	eof = get_line(s, &line[0], fd);
	if (*line && line[0][0] && eof >= 0)
		return (line_cpy(&line[0], &s[fd]));
	ft_strdel(&s[fd]);
	ft_strdel(s);
	return (eof);
}
