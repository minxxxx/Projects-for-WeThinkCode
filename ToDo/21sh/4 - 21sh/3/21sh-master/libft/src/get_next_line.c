/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 10:48:23 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/02 18:02:12 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		check_link(int const fd, t_getline **link)
{
	t_getline	*tmp;

	tmp = NULL;
	if (*link == NULL)
		*link = (create_link(fd, NULL));
	else
	{
		tmp = *link;
		while (tmp->fd != fd && tmp->next != *link)
			tmp = tmp->next;
		if (tmp->fd != fd)
		{
			tmp->next = (create_link(fd, *link));
			*link = tmp->next;
		}
		else
			*link = tmp;
	}
}

t_getline	*create_link(int const fd, t_getline *link)
{
	t_getline	*new;

	new = (t_getline *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	if (link == NULL)
		new->next = new;
	else
		new->next = link;
	new->fd = fd;
	new->save = NULL;
	return (new);
}

int			fill_line(t_getline **link, char **line, int i, char *tmp)
{
	if ((i = ft_strchr_index((*link)->buf, '\n')) == -1 && !(*link)->save)
		(*link)->save = ft_strdup((*link)->buf);
	else if ((i = ft_strchr_index((*link)->buf, '\n')) == -1 && (*link)->save)
	{
		tmp = ft_strjoin((*link)->save, (*link)->buf);
		free((*link)->save);
		(*link)->save = tmp;
	}
	else if ((i = ft_strchr_index((*link)->buf, '\n')) >= 0 && !(*link)->save)
	{
		*line = ft_strsub((*link)->buf, 0, i);
		(*link)->save = ft_strdup((*link)->buf + i + 1);
		return (1);
	}
	else if ((i = ft_strchr_index((*link)->buf, '\n')) >= 0 && (*link)->save)
	{
		tmp = ft_strsub((*link)->buf, 0, i);
		*line = ft_strjoin((*link)->save, tmp);
		free((*link)->save);
		free(tmp);
		(*link)->save = ft_strdup((*link)->buf + i + 1);
		return (1);
	}
	return (0);
}

int			read_buf(int const fd, t_getline **link, char **line)
{
	int		bytes;

	bytes = 0;
	while ((bytes = read(fd, (*link)->buf, BUFF_SIZE)) > 0)
	{
		if (fill_line(link, line, 0, NULL) == 1)
			return (1);
		ft_bzero((void *)(*link)->buf, (BUFF_SIZE + 1));
	}
	if ((*link)->save != NULL && (*link)->save[0] != 0)
	{
		*line = ft_strdup((*link)->save);
		free((*link)->save);
		(*link)->save = NULL;
		return (1);
	}
	return (bytes);
}

int			get_next_line(int const fd, char **line)
{
	int					i;
	static t_getline	*link = NULL;
	char				*tmp;

	i = 0;
	tmp = NULL;
	check_link(fd, &link);
	if (!line || fd < 0)
		return (-1);
	ft_bzero((void *)link->buf, (BUFF_SIZE + 1));
	if (link->save != NULL &&
			((i = ft_strchr_index(link->save, '\n'))) >= 0)
	{
		*line = ft_strsub(link->save, 0, i);
		tmp = ft_strdup(link->save + i + 1);
		free(link->save);
		link->save = tmp;
	}
	else
		return (read_buf(fd, &link, line));
	return (1);
}
