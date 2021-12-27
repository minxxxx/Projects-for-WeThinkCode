/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nb_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:20 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static int	jump_depending_on_type(size_t *i, char *str, t_cmd *cmd, int *count)
{
	size_t tmp_i;

	tmp_i = *i;
	if (is_aggr(i, str, 1))
	{
	}
	else if (is_redir(i, str, 1, cmd))
	{
	}
	else if (is_sep(i, str, 1, cmd))
		return (0);
	else if (str[*i] && skip_quotes_nb_arg(str, i, cmd) != NULL)
		if (tmp_i != *i)
			(*count)++;
	return (1);
}

int			nb_arg(size_t *i, char *str, t_cmd *cmd)
{
	int			count;

	count = 0;
	while (ft_isspace2(str[*i]))
		(*i)++;
	while (str[*i])
	{
		while (ft_isspace2(str[*i]))
			(*i)++;
		if (!jump_depending_on_type(i, str, cmd, &count))
			return (count);
		if (cmd->p_error)
		{
			ft_putstr_fd("42sh: parse error\n", 2);
			return (-1);
		}
	}
	return (count);
}
