/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:12:57 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/30 10:43:56 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list_gnl	*init_list_gnl(int fd)
{
	t_list_gnl	*link;
	int			ret;

	if (!(link = (t_list_gnl *)malloc(sizeof(t_list_gnl))))
		return (NULL);
	link->fd = fd;
	if (!(link->temp = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	ret = read(fd, link->temp, BUFF_SIZE);
	if (ret == -1)
		return (NULL);
	link->next = NULL;
	return (link);
}

static t_list_gnl	*return_current_link(t_list_gnl *head, int fd)
{
	t_list_gnl	*link;

	while (head)
	{
		if (head->fd == fd)
			return (head);
		if (!(head->next))
			break ;
		head = head->next;
	}
	if (!(link = init_list_gnl(fd)))
		return (NULL);
	head->next = link;
	return (link);
}

static void			copy_line(t_list_gnl *link, char **line, char *pos)
{
	char	*first;
	char	*sec;
	char	*temp_to_free;

	first = ft_strsub(link->temp, 0, pos - link->temp);
	sec = ft_strsub(link->temp, (pos - link->temp) + 1, ft_strlen(link->temp));
	temp_to_free = *line;
	*line = ft_strjoin(*line, first);
	ft_memdel((void **)&temp_to_free);
	ft_memdel((void **)&first);
	ft_memdel((void **)&(link->temp));
	link->temp = sec;
}

static int			read_line(int fd, t_list_gnl *link, char **line)
{
	char	*pos;
	int		size;
	int		length;
	char	*tmp_to_free;

	size = 1;
	while (size > 0)
	{
		if ((pos = ft_strchr(link->temp, '\n')))
		{
			copy_line(link, line, pos);
			return (1);
		}
		tmp_to_free = *line;
		*line = ft_strjoin(*line, link->temp);
		ft_memdel((void **)&tmp_to_free);
		length = ft_strlen(link->temp);
		ft_memdel((void **)&(link->temp));
		if (!(link->temp = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		size = read(fd, link->temp, BUFF_SIZE);
		if (!length && !size)
			return (0);
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	int					ret;
	static t_list_gnl	*head;
	t_list_gnl			*current_link;

	if (fd < 0 || fd == 1 || fd == 2 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!head)
	{
		if (!(head = init_list_gnl(fd)))
			return (-1);
	}
	*line = ft_strnew(1);
	if (!(current_link = return_current_link(head, fd)))
		return (-1);
	ret = read_line(fd, current_link, line);
	if (ret > 0)
		return (1);
	else if (ret == 0)
		return (0);
	else
		return (-1);
}
