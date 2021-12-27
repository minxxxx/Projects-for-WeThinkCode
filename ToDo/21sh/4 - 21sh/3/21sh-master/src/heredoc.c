/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 14:46:45 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/22 19:06:23 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	*form_file_name(void)
{
	char	*file;
	char	*nb_file;
	int		i;

	i = 1000;
	nb_file = ft_itoa(i);
	file = ft_strjoin("/tmp/21sh_heredoc", nb_file);
	while (access(file, F_OK) == 0)
	{
		free(file);
		free(nb_file);
		nb_file = ft_itoa(++i);
		file = ft_strjoin("/tmp/21sh_heredoc", nb_file);
	}
	free(nb_file);
	return (file);
}

static int	handle_heredoc_input(char *line, char *delimiter, int fd)
{
	if (line[0] == 4 || ft_strcmp(line, delimiter) == 0)
	{
		free(line);
		return (1);
	}
	ft_putendl_fd(line, fd);
	free(line);
	return (0);
}

int			fill_heredoc(char *delimiter, int *fd)
{
	int		file_fd;
	int		gnl;
	char	*file_name;
	char	*line;

	line = NULL;
	file_name = form_file_name();
	if ((file_fd = open(file_name, O_WRONLY | O_CREAT, 0600)) == -1)
		return (-1);
	ft_putstr_fd("heredoc> ", fd[3]);
	while ((gnl = get_next_line(0, &line)) == 1)
	{
		if ((handle_heredoc_input(line, delimiter, file_fd)) != 0)
			break ;
		else
			ft_putstr_fd("heredoc> ", fd[3]);
	}
	if (gnl == -1)
		quit_error(7);
	close(file_fd);
	file_fd = open(file_name, O_RDONLY);
	free(file_name);
	return (file_fd);
}

void		sig_handler_heredoc(int signum)
{
	t_shell	*shell;

	shell = get_struct(0);
	if (signum == SIGINT)
	{
		tputs(tgetstr("do", NULL), shell->fd[3], &putchar);
		ft_putstr_fd("heredoc> ", shell->fd[3]);
	}
}
