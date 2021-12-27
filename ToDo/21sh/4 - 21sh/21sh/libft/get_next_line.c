/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 12:51:25 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/24 17:18:44 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*ft_get_fd_info(int fd)
{
	static t_gnl	*save = NULL;
	t_gnl			*temp;

	temp = save;
	while (temp != NULL)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if ((temp = (t_gnl *)malloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	*temp = (t_gnl){NULL, fd, save};
	save = temp;
	return (temp);
}

static int		ft_read_buf(t_gnl **temp)
{
	int		ret;
	char	*buf;
	char	*hold;

	if ((buf = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	ret = read((*temp)->fd, buf, BUFF_SIZE);
	if (ret <= 0)
		return (ret);
	hold = ft_strjoin((*temp)->buf, buf);
	ft_strdel(&(*temp)->buf);
	(*temp)->buf = hold;
	ft_strdel(&buf);
	return (ret);
}

static int		ft_load_line(char **line, t_gnl **t)
{
	size_t	i;
	int		ret;
	char	*new;

	i = 0;
	ret = 0;
	while ((*t)->buf[i] && (*t)->buf[i] != '\n')
		i++;
	if ((*t)->buf[i] == '\n')
		ret = 1;
	new = ft_strjoin(*line, ft_strsub((*t)->buf, 0, i));
	ft_strdel(&(*line));
	*line = new;
	if (ft_strlen((*t)->buf) == i)
		ft_strdel(&(*t)->buf);
	else
	{
		new = ft_strdup(&(*t)->buf[i + 1]);
		ft_strdel(&(*t)->buf);
		(*t)->buf = new;
	}
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	t_gnl	*temp;
	int		ret;

	ret = 1;
	if (fd >= 0 && line != NULL && (temp = ft_get_fd_info(fd)) != NULL)
	{
		*line = NULL;
		while (ret > 0)
		{
			if (temp->buf != NULL)
				if (ft_load_line(&(*line), &temp) == 1)
					return (1);
			ret = ft_read_buf(&temp);
		}
		return (ret);
	}
	return (-1);
}
