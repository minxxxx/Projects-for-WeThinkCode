/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scripts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 10:02:35 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:47:20 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
 ** This finds the path and adds to it accordingly
*/

char	*ft_add_path_two(char *cmd, char **env)
{
	char	*path;
	char	*file;
	char	**temp1;
	char	**temp2;
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	temp1 = ft_strsplit(env[i], '=');
	temp2 = ft_strsplit(temp1[1], ':');
	ft_delarray(temp1);
	i = 0;
	file = ft_strjoin("/", cmd);
	while (temp2[i] != NULL)
	{
		path = ft_strjoin(temp2[i], file);
		if (access(path, X_OK) == 0)
			break ;
		ft_strdel(&path);
		i++;
	}
	ft_delarray(temp2);
	ft_strdel(&file);
	return (path);
}

/*
 ** Thiis will execute the cmds with the flags if any. if it cant be found then
 ** it will add a path to the command to find it and execute
*/

void	ft_execvp_two(char *cmd, char **env)
{
	char	**cmds;

	cmds = ft_strsplit(cmd, ' ');
	execve(cmds[0], cmds, env);
	cmds[0] = ft_add_path_two(cmds[0], env);
	execve(cmds[0], cmds, env);
	ft_delarray(cmds);
}

/*
 ** While there are cmds to execute it will do so in a child process
*/

void	ft_execute_cmds_argument(char *cmd, char **env)
{
	pid_t	father;

	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		ft_execvp_two(cmd, env);
		exit(1);
	}
}

/*
 ** Checks if the argument exists before opening the script to execute
*/

void	ft_run_script(char *c, char **env)
{
	int		file;
	char	*line;
	int		i;
	char	**cmds;

	cmds = ft_set_heredoc_arr();
	(void)env;
	i = 0;
	if (access(c, F_OK) != -1)
	{
		file = open(c, O_RDONLY);
		while (get_next_line(file, &line) != 0)
		{
			cmds = ft_add_to_array(cmds, line);
			i++;
			ft_strdel(&line);
		}
		close(file);
		i = -1;
		while (cmds[++i])
			ft_execute_cmds_argument(cmds[i], env);
	}
	else
		ft_putendl("could not find file");
}
