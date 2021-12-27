/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:57:45 by pmartine          #+#    #+#             */
/*   Updated: 2016/02/02 11:04:23 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*join;

	if (!(join = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	s1 = NULL;
	return (join);
}

static	int		ft_stockfile(int const fd, char *tmp[fd])
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	while (!(ft_strchr(tmp[fd], '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp[fd] = ft_free_strjoin(tmp[fd], buf);
	}
	return (ret);
}

static	int		ft_end_of_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static	int		ft_line(int const fd, char *tmp[fd], char **line)
{
	int		eol;
	char	*temp;

	eol = ft_end_of_line(tmp[fd]);
	*line = ft_strsub(tmp[fd], 0, eol);
	if (!(temp = (char *)malloc(sizeof(temp) * (ft_strlen(tmp[fd]) + 1))))
		return (-1);
	ft_strcpy(temp, &tmp[fd][eol + 1]);
	ft_strclr(tmp[fd]);
	tmp[fd] = ft_strcpy(tmp[fd], temp);
	free(temp);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static	char	*tmp[2560];

	if (fd < 0 || fd == 1 || fd == 2 || !line || BUFF_SIZE < 0 || fd > 2560)
		return (-1);
	if (!tmp[fd] && (!(tmp[fd] = ft_strnew(2))))
		return (-1);
	if (ft_stockfile(fd, &(*tmp)) < 0)
		return (-1);
	if (tmp[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (ft_line(fd, tmp, line) < 0)
		return (-1);
	return (1);
}
