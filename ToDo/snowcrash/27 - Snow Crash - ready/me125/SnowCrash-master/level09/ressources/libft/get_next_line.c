/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 07:13:55 by dgalide           #+#    #+#             */
/*   Updated: 2016/05/31 16:15:15 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int			ft_check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

static int			ft_read(int fd, char **rest)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		tmp = *rest;
		if (*rest)
			*rest = ft_strjoin(*rest, buff);
		else
			*rest = ft_strdup(buff);
		ft_memdel((void *)&tmp);
		if (ft_check_line(*rest) != -1)
			return (1);
	}
	return (0);
}

static int			get_line(char **rest, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!*rest)
		return (0);
	i = ft_check_line(*rest);
	if (i == -1)
	{
		*line = ft_strdup(*rest);
		ft_memdel((void *)rest);
		return (1);
	}
	else
	{
		tmp = *rest;
		if (i == 0)
			*line = ft_strnew(1);
		else
			*line = ft_strsub(*rest, 0, i);
		*rest = ft_strsub(*rest, i + 1, ft_strlen((char *)*rest) - (i + 1));
		ft_memdel((void *)&tmp);
		return (1);
	}
}

int					get_next_line(int fd, char **line)
{
	static char	*rest;
	int			i;

	if (rest)
	{
		if (ft_check_line(rest) != -1)
			get_line(&rest, line);
		else
		{
			i = ft_read(fd, &rest);
			i = get_line(&rest, line);
			return ((i == 0) ? 0 : 1);
		}
	}
	else
	{
		i = ft_read(fd, &rest);
		if (i == -1)
			return (-1);
		i = get_line(&rest, line);
		return ((i == 0) ? 0 : 1);
	}
	return (1);
}
