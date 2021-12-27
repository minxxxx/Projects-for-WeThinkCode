/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:28:13 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/07 11:35:57 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_newline(t_line *lst, char **file)
{
	char		*tmp;

	*file = ft_strjoin_and_free(*file, lst->tab, '\n', 0);
	if (ft_memchr(lst->tab, '\n', ft_strlen(lst->tab)))
	{
		tmp = ft_strdup(ft_memchr(lst->tab, '\n', ft_strlen(lst->tab)) + 1);
		free(lst->tab);
		lst->tab = tmp;
	}
	else
		ft_bzero(lst->tab, ft_strlen(lst->tab) + 1);
}

static int		ft_store(t_line *lst, char **file)
{
	char		*buf;
	int			ret;

	buf = ft_strnew(BUFF_SIZE);
	while (!ft_memchr(lst->tab, '\n', ft_strlen(lst->tab)) &&
			(ret = read(lst->fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
		{
			free(buf);
			return (ret);
		}
		buf[ret] = '\0';
		lst->tab = ft_strjoin_and_free(lst->tab, buf, '\0', 1);
	}
	free(buf);
	if (!*lst->tab)
	{
		free(lst->tab);
		free(lst);
		return (0);
	}
	ft_newline(lst, file);
	return (1);
}

static void		ft_add(t_line **begin_list, t_line *end)
{
	t_line	*tmp;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = end;
	}
	else
		*begin_list = end;
}

static t_line	*ft_new_list(const int fd)
{
	t_line	*new;

	if (!(new = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	new->tab = ft_strnew(0);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*first;
	t_line			*last;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!first)
		first = ft_new_list(fd);
	last = first;
	while (last && last->fd != fd)
		last = last->next;
	if (!last)
	{
		last = ft_new_list(fd);
		ft_add(&first, last);
	}
	*line = "";
	return (ft_store(last, line));
}
