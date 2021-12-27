/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:36:22 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:36:27 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		buf_clean(char *buf)
{
	int i;
	int j;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
	{
		i++;
		j = 0;
		while (buf[i] && i > j)
		{
			buf[j++] = buf[i++];
		}
		buf[j] = '\0';
	}
	else if (buf[i] == '\0')
		ft_bzero(buf, BUFF_SIZE + 1);
}

static	void	copy_to_line(t_line *t, char **line)
{
	char *temp;

	temp = ft_strnjoin(*line, t->buf, t->i + 1);
	ft_strdel(line);
	*line = ft_strdup(temp);
	ft_strdel(&temp);
}

static	int		check_newl(t_line *t, char **line)
{
	char *temp;

	if (t->buf[t->i] == '\n')
	{
		temp = ft_strnjoin(*line, t->buf, t->i);
		ft_strdel(line);
		*line = ft_strdup(temp);
		ft_strdel(&temp);
		buf_clean(t->buf);
		t->i = 0;
		return (1);
	}
	return (0);
}

static	int		check_return(int i, char *line)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
	{
		return (1);
	}
	else if (i == 0 && *line)
	{
		return (1);
	}
	else if (line != NULL)
		ft_strdel(&line);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_line t;

	if (fd < 0 || line == NULL || (*line = ft_strnew(0)) == NULL)
		return (-1);
	if (t.buf[t.i])
	{
		while (t.buf[t.i] && t.buf[t.i] != '\n')
			t.i++;
		if (check_newl(&t, line))
			return (1);
		copy_to_line(&t, line);
	}
	while ((t.ret = read(fd, t.buf, BUFF_SIZE)) > 0)
	{
		t.buf[t.ret] = '\0';
		t.i = 0;
		while (t.buf[t.i] && t.buf[t.i] != '\n')
			t.i++;
		if (check_newl(&t, line))
			return (1);
		copy_to_line(&t, line);
	}
	return (check_return(t.ret, *line));
}
