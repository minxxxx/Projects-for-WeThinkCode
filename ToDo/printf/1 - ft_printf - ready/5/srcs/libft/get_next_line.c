/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:56:53 by thendric          #+#    #+#             */
/*   Updated: 2016/12/17 21:56:56 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** ft_mem reallocates memory for a string
**
** @param lst a list which stores content that may need to be copied
** @param str the string to allocate memory
** @param amount the amount to allocate in string
**
** @return the newly allocated string
*/

char		*ft_mem(t_list *lst, char *str, size_t amount)
{
	char	*new;
	size_t	buff_size;

	buff_size = BUFF_SIZE;
	if (str)
	{
		new = ft_strnew(buff_size * (amount + 1) + ft_strlen(lst->content));
		ft_strncpy(new, str, buff_size * (amount + 1));
		ft_bzero(str, sizeof(str));
	}
	else
	{
		new = ft_strnew(buff_size * (amount + 1) + ft_strlen(lst->content));
		ft_bzero(new, sizeof(new));
	}
	free(str);
	return (new);
}

/*
** iterate_lst_fd searches through list to create or find lst with fd
**
** @param lst a list holding all the file descriptors and content
** @param fd the file descriptor to search for or create
**
** @return list location of correct file descriptor or new list
*/

t_list		*iterate_lst_fd(t_list **lst, int fd)
{
	t_list *node;

	if (!(*lst))
	{
		*lst = ft_lstnew("\0", 1);
		(*lst)->content_size = fd;
	}
	node = *lst;
	while (node)
	{
		if (node->content_size == (size_t)fd)
			return (node);
		if (node->next == NULL)
		{
			node->next = ft_lstnew("\0", 1);
			node->next->content_size = fd;
		}
		node = node->next;
	}
	return (node);
}

/*
** f_norm checks if t_list content has newline and if data was read
**
** @param lst a lst which stores content read
** @param line where to store the line being returned
** @param b_read the amount of bytes read
**
** @return 0 if end of line otherwise 1
*/

ssize_t		f_norm(t_list *lst, char **line, ssize_t b_read)
{
	char	*tmp;

	if (ft_strchr(lst->content, '\n'))
	{
		*line = (ft_strncat(*line, lst->content,
			ft_strchr(lst->content, '\n') - (char *)lst->content));
		tmp = lst->content;
		lst->content = ft_strdup(ft_strchr(lst->content, '\n') + 1);
		free(tmp);
		return (0);
	}
	if (b_read)
	{
		*line = ft_strcat(*line, lst->content);
		if (b_read < BUFF_SIZE)
		{
			lst->content = NULL;
			return (0);
		}
	}
	else
		lst->content = NULL;
	return ((lst->content) ? 1 : 0);
}

/*
** ft_read_line allocated memory to line and checks for end of line
**
** @param lst a lst which stores content that may need to be copied
** @param line where to store the line being returned
**
** @return 0 end of line 1 not end of line -1 error reading -2 \n in content
*/

ssize_t		ft_read_line(t_list *lst, char **line)
{
	ssize_t	i;

	i = 1;
	if (!lst->content &&
		!(i = read(lst->content_size, lst->content, BUFF_SIZE)))
		return (0);
	if (*line && BUFF_SIZE)
		*line = ft_mem(lst, *line, (ft_strlen(*line) / BUFF_SIZE));
	else if (BUFF_SIZE)
		*line = ft_mem(lst, lst->content, ft_strlen(lst->content) / BUFF_SIZE);
	if (!(ft_strchr(lst->content, '\n')) && !(ft_strchr(*line, '\n')))
	{
		lst->content = ft_strnew(BUFF_SIZE);
		i = read(lst->content_size, lst->content, BUFF_SIZE);
		if (i == -1)
			return (-1);
	}
	if (!f_norm(lst, line, i))
		return (0);
	return (ft_strlen(*line));
}

/*
** get_next_line gets the next line of a file and stores it in line
**
** @param fd the file descriptor to read from
** @param line where to store the line being returned
**
** @return 0 end of line 1 not end of line -1 error reading
*/

int			get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*lst;
	char			*tmp;
	int				ret;

	ret = 1;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	lst = iterate_lst_fd(&head, fd);
	if (*line)
		*line = NULL;
	while (ret > 0)
		ret = ft_read_line(lst, line);
	if (*line && ft_strchr(*line, '\n'))
	{
		tmp = lst->content;
		lst->content = ft_strdup(ft_strchr(*line, '\n') + 1);
		free(tmp);
		tmp = *line;
		*line = ft_strndup(*line, ft_strchr(*line, '\n') - *line);
		free(tmp);
	}
	if ((*line) && ((ft_strlen(*line) && ret != -1)))
		return (1);
	return ((lst->content && ret != -1) ? 1 : ret);
}
