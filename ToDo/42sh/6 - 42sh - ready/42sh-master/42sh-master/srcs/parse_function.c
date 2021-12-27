/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:20 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int				verif_empty_quote(char *str, size_t *i)
{
	size_t tmp;

	tmp = *i + 1;
	if (!str[tmp] || ft_isspace2(str[tmp]))
	{
		return (1);
	}
	while ((!is_quote_close(str[*i], str[tmp]) && str[tmp]) ||
	is_escaped_char(str, tmp))
	{
		if ((!is_quote(str[tmp]) && !ft_isspace2(str[tmp])) ||
		is_escaped_char(str, tmp))
			return (1);
		tmp++;
	}
	if (str[tmp])
		*i = tmp + 1;
	return (0);
}

void			get_pos_after_quote(size_t *i, char *str)
{
	char open;

	open = str[*i];
	while (!(is_quote_close(open, str[*i + 1]) &&
	!is_escaped_char(str, *i + 1)) && str[*i + 1])
		(*i)++;
	if (str[*i])
		(*i)++;
}

char			*skip_quotes_nb_arg(char *str, size_t *i, t_cmd *cmd)
{
	size_t		start;

	if (!verif_empty_quote(str, i))
	{
		return (NULL);
	}
	start = *i;
	while (str[*i] && !ft_isspace2(str[*i]) && !is_sep(i, str, 0, cmd))
	{
		if (is_redir(i, str, 0, cmd) && ft_isdigit(str[*i]))
		{
			break ;
		}
		if (!is_escaped_char(str, *i) && is_quote_open(str[*i]))
		{
			get_pos_after_quote(i, str);
		}
		(*i)++;
	}
	if (start != *i)
		return ((void*)1);
	return (NULL);
}

static void		skip_quotes_replace_string(t_cmd *cmd, char **str, size_t *i)
{
	while ((*str)[*i] && !ft_isspace2((*str)[*i]) && !is_sep(i, *str, 0, cmd))
	{
		if ((*str)[*i] == '\\')
		{
			if ((*str)[*i + 1])
				*str = delete_char(*str, *i + 1);
		}
		else
		{
			if ((is_redir(i, *str, 0, cmd) || is_aggr(i, *str, 0)) &&
			ft_isdigit((*str)[*i]))
			{
				(*i)++;
				break ;
			}
			if (is_quote_open((*str)[*i]) && !is_escaped_char(*str, *i))
				join_inside_quote(i, str);
		}
		if ((*str)[*i])
			(*i)++;
	}
}

char			*skip_quotes(char **str, size_t *i, t_cmd *cmd)
{
	size_t		start;

	if (is_quote_open((*str)[*i]) && !is_escaped_char(*str, *i) &&
	!verif_empty_quote(*str, i))
		return (NULL);
	start = *i;
	skip_quotes_replace_string(cmd, str, i);
	if (start != *i)
	{
		return (ft_strsub(*str, start, *i - start));
	}
	return (NULL);
}
