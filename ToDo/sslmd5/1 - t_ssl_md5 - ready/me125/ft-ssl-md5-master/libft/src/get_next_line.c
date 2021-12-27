/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:50:37 by apakhomo          #+#    #+#             */
/*   Updated: 2017/12/26 18:50:38 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*while_gnl(t_gnl *gnl, int fd)
{
	while (gnl->next && gnl->fd != fd)
	{
		gnl = gnl->next;
		if (gnl->fd == fd)
			return (gnl);
	}
	if (gnl->fd != fd)
	{
		NOMEM((gnl->next = (t_gnl*)malloc(sizeof(t_gnl))));
		gnl->next->fd = fd;
		gnl->next->after = NULL;
		gnl->next->next = NULL;
		gnl = gnl->next;
	}
	NOMEM((gnl->str = ft_strnew(0)));
	return (gnl);
}

static int		gnl_core(t_gnl *gnl, char **line)
{
	char			*pointer;

	pointer = ft_strchr(gnl->str, 10);
	if (pointer)
	{
		if (pointer + 1 != 0)
			ERR((gnl->after = ft_strdup(pointer + 1)));
		NIL(*pointer);
		ERR((*line = ft_strdup(gnl->str)));
		free(gnl->str);
		return (1);
	}
	if (!(*gnl->str))
		return (0);
	else
		ERR((*line = ft_strdup(gnl->str)));
	gnl->after = gnl->str;
	NIL(*gnl->after);
	free(gnl->str);
	return (1);
}

static int		gnl_reader(t_gnl *buf)
{
	while ((buf->i = read(buf->fd, buf->tmp, BUFF_SIZE)))
	{
		NIL(buf->tmp[buf->i]);
		ERR((buf->temp = ft_strjoin(buf->str, buf->tmp)));
		free(buf->str);
		buf->str = buf->temp;
		ft_strclr(buf->tmp);
		BRK((ft_strchr(buf->str, 10)));
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	t_gnl			*buf;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	if (!gnl)
	{
		ERR((gnl = (t_gnl*)malloc(sizeof(t_gnl))));
		gnl->fd = fd;
		gnl->after = NULL;
		gnl->next = NULL;
	}
	ERR((buf = while_gnl(gnl, fd)));
	buf->tmp = ft_memalloc(BUFF_SIZE + 1);
	if (buf->after)
		buf->str = buf->after;
	if (gnl_reader(buf) != 0)
		return (-1);
	ft_strdel(&buf->tmp);
	return (buf->i < 0 ? -1 : gnl_core(buf, line));
}
