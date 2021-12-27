/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 09:01:38 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/20 19:04:03 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

#define SEARCHLF ft_memchr(cur->s + cur->start, '\n', cur->read - cur->start)

t_flgnl		*get_fd_struct(t_flgnl *current, int const fd)
{
	t_flgnl	*new;

	while (current && current->next && current->fd != fd)
		current = current->next;
	if (current && current->fd == fd)
		return (current);
	new = (t_flgnl*)malloc(sizeof(t_flgnl));
	if (!new || !(new->firstcall = (t_rdgnl**)malloc(sizeof(t_rdgnl*))))
		return (NULL);
	*(new->firstcall) = NULL;
	new->next = NULL;
	new->fd = (int)fd;
	if (current)
		current->next = new;
	return (new);
}

static int	read_fd(t_flgnl *fd)
{
	t_rdgnl	*cur;

	if (!*(fd->firstcall))
	{
		cur = (t_rdgnl*)malloc(sizeof(t_rdgnl));
		if (!(*(fd->firstcall) = cur))
			return (-1);
		ft_bzero(cur, sizeof(t_rdgnl));
		cur->read = read(fd->fd, cur->s, GNL_BSIZE);
	}
	cur = *(fd->firstcall);
	while (cur->read > 0 &&
		(cur->end = SEARCHLF ? (char*)SEARCHLF - cur->s : -1) < 0)
	{
		cur->next = (t_rdgnl*)malloc(sizeof(t_rdgnl));
		cur = cur->next;
		if (!cur)
			return (-1);
		ft_bzero(cur, sizeof(t_rdgnl));
		cur->read = read(fd->fd, cur->s, GNL_BSIZE);
	}
	return (cur->read);
}

static int	concat_buffers(t_flgnl *fd, char **line, int *w)
{
	t_rdgnl	*cur;
	char	*s;

	cur = *fd->firstcall;
	if ((cur->end >= 0 ? cur->end : cur->read) >= cur->start)
		cur->end = (cur->end >= 0 ? cur->end : cur->read) - cur->start;
	*w = cur->end;
	while ((cur = cur->next))
		*w += (cur->end = (cur->end >= 0 ? cur->end : cur->read) - cur->start);
	s = (char*)ft_memalloc(sizeof(char) * (*w + 1));
	if (!(*line = s))
		return (-1);
	cur = *fd->firstcall;
	while (1)
	{
		ft_memcpy((void*)s, cur->s + cur->start, cur->end);
		s += cur->end;
		cur->start += cur->end + 1;
		cur->end = 0;
		if (cur->next)
			cur = cur->next;
		else
			return (cur->read);
	}
	return (0);
}

static void	clean_mess(t_flgnl **first, t_flgnl *cur, int delfd)
{
	t_flgnl		*curfd;
	t_rdgnl		*prev;

	while ((*(cur->firstcall))->next)
	{
		prev = *(cur->firstcall);
		*(cur->firstcall) = prev->next;
		free(prev);
	}
	if (delfd)
	{
		if (*first == cur)
			*first = cur->next;
		else
		{
			curfd = *first;
			while (curfd->next != cur)
				curfd = curfd->next;
			curfd->next = cur->next;
		}
		free(*(cur->firstcall));
		free(cur->firstcall);
		free(cur);
	}
}

int			get_next_line(int const fd, char **line)
{
	static t_flgnl		*first[1] = {NULL};
	t_flgnl				*current;
	int					rets;
	int					written;
	char				*tmp;

	current = get_fd_struct(*first, fd);
	*first = *first ? *first : current;
	if (!current)
		return (-1);
	rets = read_fd(current);
	if (rets < 0)
		return (-1);
	rets = concat_buffers(current, line ? line : &tmp, &written);
	clean_mess(first, current, !rets);
	if (!line)
		free(tmp);
	if (rets == 0 && written > 0)
		return (written);
	return (rets != 0);
}
