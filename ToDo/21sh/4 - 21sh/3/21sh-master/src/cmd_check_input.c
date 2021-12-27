/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 16:11:42 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/21 15:23:34 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	is_quote_closed(t_input *tmp, char c)
{
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->c == c && tmp->prev->c != '\\')
			return (0);
		tmp = tmp->next;
	}
	return (c);
}

static char	is_bracket_closed(t_input *tmp, char c)
{
	size_t	count;
	char	d;

	count = 1;
	d = (c == '(') ? c + 1 : c + 2;
	while ((tmp = tmp->next))
	{
		if (ft_isquote(tmp->c) && tmp->prev->c != '\\')
		{
			if ((d = is_quote_closed(tmp, tmp->c)) != 0)
				return (d);
			d = tmp->c;
			tmp = tmp->next;
			while (tmp && (tmp->c != d ||
				(tmp->c == d && tmp->prev->c == '\\')))
				tmp = tmp->next;
			d = (c == '(') ? c + 1 : c + 2;
		}
		else if (tmp->c == c && tmp->prev->c != '\\')
			count++;
		else if (tmp->c == d && tmp->prev->c != '\\' && (--count == 0))
			return (0);
	}
	return (d);
}

static char	check_quotes(t_input **input, char c, t_input *tmp)
{
	if (ft_isquote(tmp->c) && (!tmp->prev || tmp->prev->c != '\\'))
	{
		if ((c = is_quote_closed(tmp, tmp->c)) != 0)
			return (c);
		c = tmp->c;
		tmp = tmp->next;
		while (tmp && (tmp->c != c || (tmp->c == c && tmp->prev->c == '\\')))
			tmp = tmp->next;
	}
	else if ((tmp->c == '[' || tmp->c == '{' || tmp->c == '(')
			&& (!tmp->prev || tmp->prev->c != '\\'))
	{
		if ((c = is_bracket_closed(tmp, tmp->c)) != 0)
			return (c);
		c = (tmp->c == '(') ? tmp->c + 1 : tmp->c + 2;
		while ((tmp = tmp->next) &&
				(tmp->c != c || (tmp->c == c && tmp->prev->c == '\\')))
		{
			if (ft_isquote(tmp->c) && tmp->prev->c != '\\')
				c = tmp->c;
		}
	}
	*input = tmp;
	return (0);
}

char		valid_input(t_input *input, char c)
{
	int		pipe_ret;
	t_input	*tmp;
	t_input	*sub_tmp;

	tmp = input;
	if ((pipe_ret = check_pipes(input, 0)) == -1)
		return ('|');
	if (pipe_ret == 1)
		return (cmd_error(0, '|', NULL));
	while (tmp)
	{
		sub_tmp = tmp;
		if ((c = check_quotes(&tmp, tmp->c, sub_tmp)) != 0)
			return (c);
		if (tmp)
			tmp = tmp->next;
	}
	tmp = get_last_elem(input);
	if ((tmp->c == '\\' && (!tmp->prev || tmp->prev->c != '\\'))
			|| ((tmp->c == '"' || tmp->c == '`') && tmp->prev->c == '\\'
				&& tmp->prev->prev->c != '\\'))
		return ('\\');
	return (0);
}
