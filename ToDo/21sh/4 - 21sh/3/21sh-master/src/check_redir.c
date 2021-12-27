/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 15:21:55 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/25 20:51:29 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	add_redir(char *redir, int type, t_btree *link)
{
	t_redir	*new;
	t_redir	*tmp;

	if (!(new = (t_redir *)malloc(sizeof(*new))))
		quit_error(6);
	new->type = type;
	new->s = redir;
	new->next = NULL;
	if (!link->redir)
		link->redir = new;
	else
	{
		tmp = link->redir;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static int	check_valid_redir_param(char *s, int i)
{
	char	c;

	c = 0;
	if (ft_str_isempty(s + i))
		return (cmd_error(0, s[i - 1], NULL));
	while (s[i] == ' ')
		i++;
	while (s[i] && !ft_isspace(s[i]) && s[i] != '>' && s[i] != '<')
	{
		if (ft_isquote(s[i]) && (c = s[i]))
		{
			i++;
			while (s[i] && s[i] != c)
				i++;
		}
		i++;
	}
	return (i);
}

static int	check_valid_redir(char *s, int start, int i, t_btree *link)
{
	int	type;

	type = 0;
	if (s[i + 1] && s[i + 1] == s[i] && (i += 2))
		type = (s[i - 1] == '>') ? DREDIR : HEREDOC;
	else if (++i)
		type = (s[i - 1] == '>') ? REDIR : BREDIR;
	if (s[i] == '>' || s[i] == '<')
		return (cmd_error(0, s[i - 1], NULL));
	if (s[i] == '&' && ++i)
	{
		if (!s[i] || type == HEREDOC || (type == DREDIR && s[i] == '-'))
			return (cmd_error(0, s[i - 1], NULL));
		if (ft_isdigit(s[i]) && s[i] > '2'
			&& (!s[i + 1] || (s[i + 1] && ft_isspace(s[i + 1]))))
			return (cmd_error(1, 0, s + i));
	}
	i = (check_valid_redir_param(s, i)) - 1;
	if (i > 0)
		add_redir(ft_strsub(s, start, (i - start + 1)), type, link);
	return (0);
}

static int	check_redir_start(t_btree *link, int i)
{
	int	j;

	j = i;
	while (j > 0 && ft_isdigit(link->str[j - 1]))
		j--;
	if (link->str[j] && !ft_isspace(link->str[j]))
		j = i;
	if (ft_atoi(link->str + j) > 2)
		return (cmd_error(1, 0, NULL));
	return (check_valid_redir(link->str, j, i, link));
}

int			strchr_redir(t_btree *link)
{
	int		i;
	char	c;

	i = 0;
	while (link->str[i] && ft_isspace(link->str[i]))
		i++;
	if (link->str[i] && (link->str[i] == '>' || (link->str[i] == '<' &&
		(!link->str[i + 1] || link->str[i + 1] != '<'))))
		return (cmd_error(0, link->str[i], NULL));
	while (link->str[i])
	{
		if (ft_isquote(link->str[i]) && (c = link->str[i++]))
		{
			while (link->str[i] && link->str[i] != c)
				i++;
		}
		else if (link->str[i] == '>' || link->str[i] == '<')
		{
			if (check_redir_start(link, i) == -1)
				return (-1);
			i++;
		}
		link->str[i] ? (i++) : (0);
	}
	return (0);
}
