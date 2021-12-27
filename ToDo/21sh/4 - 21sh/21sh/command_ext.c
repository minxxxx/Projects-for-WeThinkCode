/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 13:23:12 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:08:02 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "env.h"

int		ft_get_command_line(char *str, char **line)
{
	static int		i = 0;
	static int		kill = 0;
	int				j;

	j = i;
	while (str[i] != '\0')
	{
		if ((str[i] == 34 || str[i] == 39))
		{
			if (kill == 0)
				kill = 1;
			else
				kill = 0;
		}
		if (str[i] == '|' && kill == 0 && i++ > 0)
			return (0);
		*line = ft_strjoin(*line, ft_strsub(str, i, 1));
		i++;
	}
	*line = ft_strjoin(*line, ft_strsub(str, i, 1));
	if (j < i)
		return (0);
	i = 0;
	kill = 0;
	return (-1);
}

void	ft_deploy_good_command(t_parser **hq, t_cmd **cmd, \
		int tmpin, int tmpout)
{
	if ((*cmd)->pos == 1 && (*hq)->infile != NULL)
		(*cmd)->fds.in = ft_deploy_in_redirection((*hq)->infile, -1);
	else if ((*cmd)->pos == 1 && (*hq)->infile == NULL)
		(*cmd)->fds.in = tmpin;
	else
		(*cmd)->fds.in = (*hq)->pipe_in;
	if ((*cmd)->fds.in != -1)
		ft_deploy_simple_command(&(*cmd), (*hq)->outfile, tmpout, &(*hq));
}

char	**ft_load_argv(char *line, int i, int j, int kill)
{
	char	**s;

	s = (char **)malloc(sizeof(char *) * 10);
	while (line[i] != '\0')
	{
		if (line[i] == 34 || line[i] == 39)
		{
			if (kill == 0)
				kill = 1;
			else
				kill = 0;
			i++;
			continue ;
		}
		if (kill == 0 && line[i] == 32)
		{
			j++;
			i++;
			continue ;
		}
		s[j] = ft_strjoin(s[j], ft_strsub(line, i, 1));
		i++;
	}
	s[++j] = NULL;
	return (s);
}
