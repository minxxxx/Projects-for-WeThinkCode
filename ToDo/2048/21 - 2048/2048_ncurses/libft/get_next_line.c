/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:34:29 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/22 08:57:05 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	chk_eol(char *str)
{
	int		index;

	index = -1;
	if (!str)
		return (0);
	while (str[++index] != '\0')
	{
		if (str[index] == '\n')
			return (index + 1);
	}
	return (0);
}

int		read_fd(int fd, char *buf)
{
	int		ret;

	if ((ret = read(fd, buf, BUFF_SIZE)) != -1)
		buf[ret] = '\0';
	return (ret);
}

char	*free_join(char *s1, char *s2, int lib)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (s1 && (lib == 3 || lib == 2))
		ft_memdel((void **)&s1);
	if (s2 && (lib == 3 || lib == 1))
		ft_memdel((void **)&s2);
	return (tmp);
}

t_fd	*get_fd(t_fd *lst_fd, int fd)
{
	t_fd	*l_tmp;

	l_tmp = lst_fd;
	if (l_tmp)
	{
		while (l_tmp->nxt)
		{
			if (l_tmp->fd == fd)
				return (l_tmp);
			l_tmp = l_tmp->nxt;
		}
		if (l_tmp->fd == fd)
			return (l_tmp);
		if (!(l_tmp->nxt = (t_fd *)malloc(sizeof(t_fd))))
			return (NULL);
		l_tmp = l_tmp->nxt;
	}
	else if (!(l_tmp = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	l_tmp->fd = fd;
	l_tmp->lne = ft_strdup("");
	l_tmp->nxt = NULL;
	l_tmp->srt = (!lst_fd) ? l_tmp : lst_fd;
	return (l_tmp);
}

int		get_next_line(int const fd, char **line)
{
	static t_fd		*cur_fd = NULL;
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				len;
	int				ret;

	ret = 0;
	if (fd < 0 || line == NULL)
		return (ERR);
	cur_fd = get_fd(cur_fd, fd);
	while (fd >= 0 && ((len = chk_eol(cur_fd->lne)) ||
				(ret = read_fd(fd, buf)) > 0) && len <= 0)
		cur_fd->lne = free_join(cur_fd->lne, buf, 2);
	if (ret == ERR)
		return (ERR);
	if (len > 0)
		cur_fd->lne[len - 1] = '\0';
	*line = ft_strdup(cur_fd->lne);
	str = cur_fd->lne;
	cur_fd->lne = ((len > 0) ? ft_strdup(cur_fd->lne + len) :
			ft_strdup(""));
	free(str);
	cur_fd = cur_fd->srt;
	return ((len || **line) ? 1 : 0);
}
