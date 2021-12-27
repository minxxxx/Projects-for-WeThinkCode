/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 19:05:07 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	jump_space_and_init_tmp(char **str, size_t *i, size_t *tmp_i)
{
	while (ft_isspace2((*str)[*i]))
		(*i)++;
	*tmp_i = *i;
}

static void	assign_expression_in_cmd(t_cmd *cmd, int *n_av, char *tmp)
{
	cmd->av[*n_av] = tmp;
	(*n_av)++;
}

static int	handle_expression(char **str, int n_av, t_cmd *cmd, t_hc **heredocs)
{
	size_t		tmp_i;
	char		*tmp;
	size_t		i;

	i = 0;
	while ((*str)[i])
	{
		jump_space_and_init_tmp(str, &i, &tmp_i);
		if (handle_aggr(&i, (*str), 1, cmd))
		{
		}
		else if (handle_redir(&i, &(*str), cmd, heredocs))
		{
		}
		else if (is_sep(&i, (*str), 1, cmd))
			return (1);
		else if ((tmp = skip_quotes(&(*str), &i, cmd)) != NULL)
			if (tmp_i != i)
				assign_expression_in_cmd(cmd, &n_av, tmp);
		if (cmd->error)
			return (-1);
	}
	return (1);
}

int			split_cmd(int count, char **str, t_cmd *cmd, t_hc **heredocs)
{
	int		i;

	i = 0;
	cmd->av = (char**)mallocp((count + 2) * sizeof(char*));
	while (i <= count + 1)
	{
		cmd->av[i] = NULL;
		i++;
	}
	return (handle_expression(str, 0, cmd, heredocs));
}
