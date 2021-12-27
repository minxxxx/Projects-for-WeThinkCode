/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 13:25:31 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:06:43 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		ft_get_redirection_infile(t_parser **hq)
{
	int		i;
	int		size;
	char	**s;

	i = -1;
	size = -1;
	(*hq)->infile = (char **)malloc(sizeof(char *) * 42);
	while ((*hq)->line[++i] != '\0')
	{
		if ((*hq)->line[i] == '<')
		{
			s = ft_strsplit(&(*hq)->line[i + 1], ' ');
			if (s[0] == NULL)
				return (ft_redirection_error(3, NULL, 2));
			if (access(s[0], F_OK) == -1)
				return (ft_redirection_error(1, s[0], 2));
			if (access(s[0], R_OK) == -1)
				return (ft_redirection_error(2, s[0], 2));
			(*hq)->infile[++size] = ft_strdup(s[0]);
			ft_del_array(s);
		}
	}
	(*hq)->infile[++size] = NULL;
	return (0);
}

int		ft_get_redirection_outfile(t_parser **hq)
{
	int		i;
	int		size;
	char	**s;

	i = -1;
	size = -1;
	(*hq)->outfile = (char **)malloc(sizeof(char *) * 42);
	while ((*hq)->line[++i] != '\0')
	{
		if ((*hq)->line[i] == '>')
		{
			s = ft_strsplit(&(*hq)->line[i + 1], ' ');
			if (s[0] == NULL)
				return (ft_redirection_error(3, NULL, 2));
			(*hq)->outfile[++size] = ft_strdup(s[0]);
			ft_del_array(s);
		}
	}
	(*hq)->outfile[++size] = NULL;
	return (0);
}

int		ft_open_infile(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_redirection_error(4, file, 2));
	return (fd);
}

int		ft_deploy_in_redirection(char **file, int i)
{
	char	*buf;
	int		tmp_fd;
	int		fd;

	buf = NULL;
	tmp_fd = open(".temp", O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0666);
	while (file[++i] != NULL)
	{
		fd = ft_open_infile(file[i]);
		while (fd != -1 && get_next_line(fd, &buf) > 0)
			ft_putendl_fd(buf, tmp_fd);
		close(fd);
	}
	close(tmp_fd);
	tmp_fd = open(".temp", O_RDONLY);
	return (tmp_fd);
}
