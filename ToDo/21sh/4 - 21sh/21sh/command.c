/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 12:54:05 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:07:57 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "env.h"

char	*ft_upload_simple_command_path(char *exec, char **env, int i)
{
	char	*path;
	char	*final;
	char	**s;

	if (exec == NULL || exec[0] == '/' || ft_strstr(BUILT_IN, exec) != NULL)
		return (ft_strdup(exec));
	s = ft_strsplit(ft_get_line_myenv(env, "PATH"), ':');
	while (s[++i] != NULL)
	{
		path = ft_strjoin(s[i], ft_strjoin("/", exec));
		if (access(path, F_OK) != -1)
			break ;
		free(path);
	}
	if (exec[0] == '.' && exec[1] != '\0' && exec[1] == '/')
		path = ft_strjoin(ft_get_line_myenv(env, "PWD"), &exec[1]);
	if (access(path, F_OK) == -1)
		final = ft_strdup("not found");
	else if (access(path, X_OK) == -1)
		final = ft_strdup("no permission");
	else
		final = ft_strdup(path);
	ft_del_array(s);
	return (final);
}

void	ft_deploy_commands(t_parser **hq, t_cmd **cmds)
{
	int		tmpin;
	int		tmpout;
	t_cmd	*cmd;

	tmpin = dup(0);
	tmpout = dup(1);
	cmd = *cmds;
	while (cmd != NULL)
	{
		if (ft_strcmp("not found", cmd->path) == 0)
			ft_redirection_error(5, cmd->exec_name, 2);
		else if (ft_strcmp("no permission", cmd->path) == 0)
			ft_redirection_error(2, cmd->exec_name, 2);
		else
			ft_deploy_good_command(&(*hq), &cmd, tmpin, tmpout);
		cmd = cmd->next;
	}
}

void	ft_deploy_simple_command(t_cmd **cmd, char **outfile, \
		int tmpout, t_parser **hq)
{
	int		pipeline[2];

	if ((*hq)->done_pipes < (*hq)->nb_pipes && pipe(pipeline) != -1)
	{
		(*hq)->pipe_in = pipeline[0];
		(*cmd)->fds.out = pipeline[1];
		(*hq)->done_pipes++;
	}
	else if ((*cmd)->next == NULL && outfile != NULL)
		(*cmd)->fds.out = open(".out", O_RDWR | \
				O_CREAT | O_TRUNC | O_APPEND, 0666);
	else
		(*cmd)->fds.out = tmpout;
	dup2((*cmd)->fds.in, 0);
	close((*cmd)->fds.in);
	dup2((*cmd)->fds.out, 1);
	close((*cmd)->fds.out);
	if ((*cmd)->fds.out != -1)
		ft_final_deploy(&(*cmd), (*hq)->env, &(*hq));
	if ((*cmd)->next == NULL && outfile != NULL)
		ft_redirect_out(outfile, -1);
}

void	ft_final_deploy(t_cmd **cmd, char **myenv, t_parser **hq)
{
	pid_t	ret;

	if (ft_my_builtins_check(&(*cmd)) == 1)
		return (ft_my_builtins(&(*cmd), myenv, &(*hq)));
	ret = fork();
	if (ret == -1)
		write(2, "error: could not fork program\n", 30);
	else if (ret == 0)
	{
		if ((*cmd)->err == 1)
			close(2);
		(*cmd)->ret = execve((*cmd)->path, &(*cmd)->argv[0], &myenv[0]);
		exit(1);
	}
	else
		waitpid(ret, NULL, 0);
}
