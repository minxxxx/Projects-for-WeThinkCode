/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:53:06 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:49:50 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
 ** Pipe all the echo cmds one at a time
*/

void	ft_pipe_echo_cmds(char **cmds, t_all *a)
{
	pid_t	pid;
	int		fd;

	pid = fork();
	if (pid == 0)
	{
		close(1);
		fd = open(".echo", O_CREAT | O_WRONLY | O_APPEND | O_TRUNC, 0777);
		while (*cmds)
		{
			ft_echo_exe_cmd(*cmds, a);
			cmds++;
		}
		exit(1);
	}
	else
		wait(&pid);
}

/*
 ** read from file the results
*/

void	ft_read_from_file(char *file)
{
	int		fd;
	char	**toprint;
	int		i;

	i = 0;
	toprint = (char **)malloc(sizeof(char *) * (200 + 1));
	fd = open(file, O_RDONLY, 0777);
	while (get_next_line(fd, &toprint[i]) != 0)
		i++;
	toprint[i] = NULL;
	close(fd);
	fd = -1;
	while (toprint[++fd])
	{
		ft_putstr(*toprint);
		ft_putstr(" ");
	}
	ft_putendl("");
	ft_delarray(toprint);
}

/*
 ** This will take multiple input for back qoutes
*/

void	ft_bqoute(char *s, t_all *a)
{
	char	*cmd;
	char	**cmds;

	(void)s;
	cmds = ft_set_heredoc_arr();
	while (1)
	{
		ft_putstr(MAGENTA"bqoute> "RESET);
		if (get_next_line(0, &cmd) == 0)
			break ;
		if (ft_strstr(cmd, "`") != NULL)
			break ;
		else
			cmds = ft_add_to_array(cmds, cmd);
		ft_strdel(&cmd);
	}
	ft_strdel(&cmd);
	ft_pipe_echo_cmds(cmds, a);
	ft_read_from_file(".echo");
	ft_delarray(cmds);
}

/*
 ** this will echo the commands from echo back qoutes
*/

void	ft_pipe_echo(char *str, t_all *a)
{
	char	*temp;
	char	*cmd;
	int		i;
	int		len;

	i = 3;
	len = 0;
	while (str[++i])
		len++;
	cmd = (char *)malloc(sizeof(char) * (len + 1));
	i = 3;
	len = 0;
	while (str[++i])
	{
		cmd[len] = str[i];
		len++;
	}
	cmd[len] = '\0';
	ft_memmove(cmd, cmd + 2, ft_strlen(cmd));
	cmd[(ft_strlen(cmd) - 1)] = '\0';
	temp = ft_strjoin(cmd, " | xargs");
	ft_line(temp, a);
	ft_strdel(&temp);
	ft_strdel(&cmd);
}

/*
 ** Check for open or close backward qoutes
*/

void	ft_echo_cmds(char *str, t_all *a)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '`')
			count++;
	if (ft_is_even(count) == 1)
		ft_pipe_echo(str, a);
	else
		ft_bqoute(str, a);
}
