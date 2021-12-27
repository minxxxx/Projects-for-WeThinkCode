/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:20 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			is_wrong_pipe(char *str, int index)
{
	while (str[index] && ft_isspace2(str[index]))
		index++;
	if (str[index] == '|' || str[index] == '&')
		return (1);
	return (0);
}

static int	is_logical_operator_or_pipe(char *str, int i)
{
	return (!is_escaped_char(str, i) && ((str[i] == '&'
					&& str[i + 1] != '&') || ft_strnequ(str + i, "&&", 2)
				|| str[i] == '|' || ft_strnequ(str + i, "||", 2)));
}

static void	do_normal_char(size_t *i, int *first_char, int *pipe_last)
{
	{
		(*i)++;
		*first_char = 0;
		*pipe_last = 0;
	}
}

static int	check_for_parse_error(char *str, size_t i, int first_char,
		int *pipe_last)
{
	while (str[i])
	{
		while (ft_isspace2(str[i]))
			i++;
		if (!str[i])
			continue ;
		if (!is_escaped_char(str, i) && is_quote_open(str[i]))
			get_pos_after_quote(&i, str);
		else if (is_aggr(&i, str, 1))
			continue ;
		else if (str[i] != '|' && str[i + 1] != '&' && is_sep(&i, str, 1, NULL))
		{
			if (!verif_wrong_sep(pipe_last, &first_char))
				return (print_pipe_error());
		}
		else if (is_logical_operator_or_pipe(str, i))
		{
			if (!verif_first_pipe_error(str, &i, pipe_last, first_char))
				return (print_pipe_error());
		}
		else
			do_normal_char(&i, &first_char, pipe_last);
	}
	return (0);
}

int			is_pipe_error(char *str)
{
	size_t		i;
	int			first_char;
	int			pipe_last;

	i = 0;
	first_char = 1;
	pipe_last = 0;
	if (check_for_parse_error(str, i, first_char, &pipe_last))
		return (1);
	if (pipe_last)
		return (print_pipe_error());
	return (0);
}
