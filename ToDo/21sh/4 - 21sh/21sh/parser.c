/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 09:52:48 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:08:00 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "env.h"

t_parser	*ft_init_parser_hq(char *line)
{
	t_parser		*hq;
	char			**tmp;

	tmp = NULL;
	if ((hq = (t_parser *)malloc(sizeof(t_parser))) == NULL)
		return (NULL);
	hq->cmds = NULL;
	ft_pipe_control_tower(line, "count");
	hq->nb_pipes = ft_count_pipes(line);
	hq->done_pipes = 0;
	hq->line = NULL;
	hq->infile = NULL;
	hq->outfile = NULL;
	tmp = myenv_control_tower(tmp, NULL, NULL, "myenv");
	hq->env = ft_load_myenv(tmp);
	return (hq);
}

int			ft_upload_simple_command(t_cmd **cmds, char *line, int pos, \
		char **env)
{
	int		i;

	if (*cmds != NULL)
		return (ft_upload_simple_command(&(*cmds)->next, line, pos, env));
	if ((*cmds = (t_cmd *)malloc(sizeof(t_cmd))) == NULL)
		return (write(2, "error: failed to malloc cmds\n", 28));
	(*cmds)->pos = pos;
	i = 0;
	(*cmds)->err = 0;
	if (ft_strstr(line, ERROR_CLOSE) != NULL)
		(*cmds)->err = 1;
	while (line[i] != '\0' && line[i] != '<' && line[i] != '>')
		i++;
	(*cmds)->line = ft_strsub(line, 0, i);
	(*cmds)->ret = 1;
	i = 0;
	while ((*cmds)->line[i] != '\0' && (*cmds)->line[i] != ' ')
		i++;
	(*cmds)->exec_name = ft_strsub((*cmds)->line, 0, i);
	(*cmds)->argv = ft_load_argv((*cmds)->line, 0, 0, 0);
	(*cmds)->path = ft_upload_simple_command_path((*cmds)->exec_name, env, -1);
	(*cmds)->next = NULL;
	return (1);
}

int			ft_upload_commands(t_parser **hq)
{
	t_cmd	*cmds;
	int		j;
	int		pos;
	char	*line;

	cmds = NULL;
	pos = 0;
	line = NULL;
	while (ft_get_command_line((*hq)->line, &line) != -1)
	{
		j = 0;
		while (line[j] == ' ')
			j++;
		if (ft_upload_simple_command(&cmds, &line[j], ++pos, (*hq)->env) != 1)
			return (-1);
		line = NULL;
	}
	(*hq)->cmds = cmds;
	return (0);
}

void		ft_deploy_parser(t_parser **hq)
{
	int		in;
	int		out;

	in = dup(0);
	out = dup(1);
	if (ft_upload_commands(&(*hq)) == -1)
		return ;
	if (ft_strchr((*hq)->line, '<') != NULL)
		if (ft_get_redirection_infile(&(*hq)) == -1)
			return ;
	if (ft_strchr((*hq)->line, '>') != NULL)
		if (ft_get_redirection_outfile(&(*hq)) == -1)
			return ;
	ft_deploy_commands(&(*hq), &(*hq)->cmds);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

void		ft_parser_control_tower(char *line)
{
	t_parser	*hq;
	int			i;
	char		**s;

	i = -1;
	s = ft_strsplit(line, ';');
	hq = NULL;
	while (s[++i] != NULL)
	{
		hq = ft_init_parser_hq(s[i]);
		hq->line = ft_strdup(s[i]);
		if (hq != NULL)
		{
			ft_deploy_parser(&hq);
			myenv_control_tower(hq->env, NULL, NULL, "load");
		}
	}
	ft_del_array(s);
}
