/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			is_aggr(size_t *i, char *str, int jump)
{
	size_t tmp;

	tmp = *i;
	if ((str[*i] == '>' || str[*i] == '<') && str[*i + 1] == '&' &&
		(ft_isdigit(str[*i + 2]) || str[*i + 2] == '-'))
	{
		(*i) += 2;
		while (ft_isdigit(str[*i]) || str[*i] == '-')
			(*i)++;
		if (!jump)
			*i = tmp;
		return (1);
	}
	else if (ft_isdigit(str[*i]) && (str[*i + 1] == '>' || str[*i + 1] == '<')
		&& str[*i + 2] == '&' && (ft_isdigit(str[*i + 3])
		|| str[*i + 3] == '-'))
	{
		(*i) += 3;
		while (ft_isdigit(str[*i]) || str[*i] == '-')
			(*i)++;
		if (!jump)
			*i = tmp;
		return (1);
	}
	return (0);
}

static void	find_if_is_redir_is_redir(size_t *tmp, char *str, size_t *i)
{
	if ((str[*tmp] == '<' && str[*tmp + 1] == '<')
		|| (str[*tmp] == '>' && str[*tmp + 1] == '>'))
		(*tmp) += 2;
	else if (str[*tmp] == '<' || str[*tmp] == '>')
		(*tmp)++;
	else if (ft_isdigit(str[*i]))
	{
		if ((str[*tmp + 1] == '>' && str[*tmp + 2] == '>'))
			(*tmp) += 3;
		else if (str[*tmp + 1] == '>')
			(*tmp) += 2;
	}
}

char		*is_redir(size_t *i, char *str, int jump, t_cmd *cmd)
{
	size_t	tmp;

	tmp = *i;
	find_if_is_redir_is_redir(&tmp, str, i);
	if (tmp != *i)
	{
		while (ft_isspace2(str[tmp]))
			tmp++;
		if (is_empty(str, &tmp))
		{
			if (cmd)
				cmd->p_error = 1;
			return (NULL);
		}
		skip_quotes_nb_arg(str, &tmp, cmd);
		if (jump)
			*i = tmp;
		return ("KAKA");
	}
	return (NULL);
}

int			is_sep(size_t *i, char *str, int jump, t_cmd *cmd)
{
	size_t	ret;

	ret = *i;
	if (ft_strnequ(str + *i, "||", 2))
		ret += 2;
	else if (ft_strnequ(str + *i, "&&", 2))
		ret += 2;
	else if (str[*i] == ';')
		ret++;
	else if (str[*i] == '|')
		ret++;
	else
		return (0);
	if (is_escaped_char(str, *i))
		return (0);
	if (cmd)
		cmd->sep = def_sep(str + *i);
	if (jump)
		*i = ret;
	return (1);
}
