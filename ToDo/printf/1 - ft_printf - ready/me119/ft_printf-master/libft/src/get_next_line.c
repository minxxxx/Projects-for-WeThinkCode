/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:30:22 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/16 14:01:40 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_set_line(char **line, t_get *lst, int ret)
{
	size_t	len;
	char	*cont;
	char	*new_cont;
	char	*old_cont;

	len = 0;
	if ((cont = ft_strchr(lst->content, '\n')))
	{
		old_cont = lst->content;
		while (old_cont[len] != '\n')
			len++;
		*line = ft_strsub(old_cont, 0, len);
		new_cont = ft_strdup(++cont);
		lst->content = new_cont;
		free(old_cont);
		return (1);
	}
	if (!ret && lst && lst->content)
	{
		*line = ft_strdup(lst->content);
		ft_memdel(&(lst)->content);
		return (1);
	}
	return (0);
}

static	t_get	*ft_set_lst(char *buf, t_get **list, int fd, int ret)
{
	char	*tmp;
	t_get	*lst;

	lst = *list;
	while (lst && fd != lst->fd)
		lst = lst->next;
	if (!lst && ret)
	{
		lst = (t_get *)ft_lstnew(buf, (size_t)(ret + 1));
		lst->fd = fd;
		lst->next = *list;
		*list = lst;
	}
	else if (lst && ret)
	{
		tmp = ft_strjoin(lst->content, buf);
		free(lst->content);
		lst->content = ft_strdup(tmp);
		free(tmp);
	}
	return (lst);
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	static t_get	*list;
	t_get			*lst;
	char			buf[BUFF_SIZE + 1];

	if (fd == -1)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	lst = ft_set_lst(buf, &list, fd, ret);
	if (lst && lst->content && ft_strlen(lst->content))
	{
		if (ft_set_line(line, lst, ret))
			return (1);
		return (get_next_line(fd, line));
	}
	else
		return (0);
}
