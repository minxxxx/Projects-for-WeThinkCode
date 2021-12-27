/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void		join_inside_quote(size_t *i, char **str)
{
	size_t	tmp;
	char	open;

	open = (*str)[*i];
	while (!is_quote_close(open, (*str)[*i + 1]) && (*str)[*i + 1])
	{
		if ((*str)[*i + 1] == '\\' && ((*str)[*i + 2] == '\"'
			|| (*str)[*i + 2] == '$' || (*str)[*i + 2] == '!'
			|| (*str)[*i + 2] == '\\' || (*str)[*i + 2] == '`') && open != '\'')
			*str = delete_char(*str, *i + 1);
		(*str)[*i] = (*str)[*i + 1];
		(*i)++;
	}
	tmp = *i;
	while ((*str)[tmp + 1] && (*str)[tmp + 2])
	{
		(*str)[tmp] = (*str)[tmp + 2];
		tmp++;
	}
	(*str)[tmp] = '\0';
	if (*i == 0 || is_quote_open((*str)[0]))
		return ;
	(*i)--;
}

static int	is_weird_heredoc(char *str, size_t i)
{
	while (str[i])
	{
		if (is_quote_open(str[i]))
			get_pos_after_quote(&i, str);
		else
		{
			if (ft_strnequ(str + i, ">>", 2) || ft_strnequ(str + i, "<<", 2)
					|| str[i] == '<' || str[i] == '>')
			{
				i += (str[i + 1] == '<' || str[i + 1] == '>') ? 2 : 1;
				while (ft_isspace2(str[i]))
					i++;
				if (!str[i] || is_sep(&i, str, 0, NULL)
					|| is_redir(&i, str, 0, NULL)
					|| is_aggr(&i, str, 0) || ft_strnequ(str + i, ">>", 2)
	|| ft_strnequ(str + i, "<<", 2) || str[i] == '<' || str[i] == '>')
					return (0);
				else
					jump_all_quote_for_arg(str, &i);
			}
		}
		if (str[i])
			i++;
	}
	return (1);
}

static int	init_things_heredoc(t_data *data, char *boucle_cmd, size_t *i)
{
	data->old_index = data->index;
	(*i) += 2;
	data->c = '<';
	while (ft_isspace2(boucle_cmd[*i]))
		(*i)++;
	if (!boucle_cmd[*i])
	{
		free(boucle_cmd);
		ft_putstr_fd("42sh: parse error near '\\n'\n", 2);
		return (-1);
	}
	data->key_here = skip_quotes(&boucle_cmd, i, NULL);
	if (data->key_here == NULL)
	{
		free(boucle_cmd);
		return (0);
	}
	data->end_hd = *i;
	if (data->cmd_tmp)
		free(data->cmd_tmp);
	data->cmd_tmp = data->cmd;
	data->cmd = ft_strdup("");
	data->index = -1;
	data->first_line_of_hd = 1;
	return (1);
}

static int	is_heredoc_end(t_data *data, size_t i, char *boucle_cmd)
{
	int		tmp;

	if (!is_weird_heredoc(boucle_cmd, 0))
	{
		free(boucle_cmd);
		ft_putstr_fd("42sh: parse error near '\\n'\n", 2);
		return (-1);
	}
	while (data->c == '\0' && boucle_cmd[i])
	{
		if (ft_strnstr(boucle_cmd + i, "<<", 2))
		{
			data->command_save = ft_strdup(boucle_cmd);
			tmp = init_things_heredoc(data, boucle_cmd, &i);
			if (tmp < 0)
				return (tmp);
		}
		i++;
	}
	if (boucle_cmd)
		free(boucle_cmd);
	if (data->c)
		return (1);
	return (0);
}

int			is_quote_end(t_data *data)
{
	size_t	i;
	char	*b;

	i = data->quote_old_index;
	b = ft_strjoin(data->cmd_tmp, data->cmd);
	while (b[i])
	{
		if (data->c == '\0')
		{
			if (is_quote_open(b[i]) && !is_escaped_char(b, i))
				data->c = b[i];
		}
		else if (is_quote_close(data->c, b[i]) && !is_escaped_char(b, i))
			data->c = '\0';
		i++;
	}
	data->quote_old_index = i;
	free(b);
	if (data->c)
	{
		data->quote_or_hd = 0;
		return (1);
	}
	i = data->end_hd;
	return (is_heredoc_end(data, i, ft_strjoin(data->cmd_tmp, data->cmd)));
}
