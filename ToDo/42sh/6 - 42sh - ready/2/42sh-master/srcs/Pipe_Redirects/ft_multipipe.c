/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multipipe,c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 09:03:47 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/24 03:45:18 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define CLOSE_FD i=2;while(i++!=100)close(i)
#define EXEC_CMD ft_execvp(cmds[i], a);ft_cmd_unknown(cmds[i])

/*
 ** This looks for the path of biniary cmds found in one of the paths in the
 ** enviroment.
*/

char	*ft_add_path(char *cmd, t_all *a)
{
	char	*path;
	char	*file;
	char	**temp1;
	char	**temp2;
	int		i;

	i = 0;
	while (ft_strncmp(a->new[i], "PATH=", 5) != 0)
		i++;
	temp1 = ft_strsplit(a->new[i], '=');
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
 ** This is my version of execvpe that I can call from wherever so that it find
 ** gets the cmds path if not found in the current directory given
*/

void	ft_execvp(char *cmd, t_all *a)
{
	t_exe	b;
	int		i;

	i = 0;
	b.cmds = ft_strsplit(cmd, ' ');
	if (hasglob(b.cmds) > 0)
		i = implementg_two(&b);
	if (i != -1)
	{
		execve(b.cmds[0], b.cmds, a->new);
		b.cmds[0] = ft_add_path(b.cmds[0], a);
		execve(b.cmds[0], b.cmds, a->new);
	}
	else
		ft_putendl("Error: could not find file name");
	ft_delarray(b.cmds);
}

/*
 ** This is to work with the function below it but because of norme I had to
 ** seperate it to a different function
*/

void	ft_loop_norm(t_pipeloop *b)
{
	close(b->p[1]);
	b->fd_in = b->p[0];
}

/*
 ** This is for piping the cmds from one into the other
*/

void	ft_loop_pipe(char **cmds, t_all *a)
{
	t_pipeloop		b;
	int				i;

	i = -1;
	b.fd_in = 0;
	while (cmds[++i] != NULL)
	{
		pipe(b.p);
		signal(SIGINT, fork_signal_handler);
		b.father = fork();
		if (b.father == 0)
		{
			dup2(b.fd_in, 0);
			if ((cmds[i + 1]) != NULL)
				dup2(b.p[1], 1);
			close(b.p[0]);
			EXEC_CMD;
			exit(1);
		}
		else
			ft_loop_norm(&b);
	}
	while (wait(NULL) > 0)
		;
	CLOSE_FD;
}
