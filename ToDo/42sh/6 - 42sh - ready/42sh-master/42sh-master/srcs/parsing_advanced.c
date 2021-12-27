/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_advanced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:20 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	var_and_tilde_no_quote(t_data *data, char **str, size_t *index)
{
	is_var_and_replace(data, str, index);
	if ((*str)[*index])
		is_tilde_and_replace(data, str, index);
}

static int	replace_depending_quotes(t_data *data, char **str,
	char *open_quote, size_t *index)
{
	if (*open_quote == '\0' &&
		is_quote_true_open((*str)[*index], *str, *index))
		*open_quote = (*str)[*index];
	else if (*open_quote != '\0' && is_quote_true_close((*str)[*index],
		*open_quote, *str, *index))
		*open_quote = '\0';
	else if (*open_quote == '\0'
		&& (*str)[*index])
	{
		if (is_subs_and_replace(data, str, index, 0) == 0)
			return (0);
		if (data->flag_enter && (*str)[*index])
			var_and_tilde_no_quote(data, str, index);
	}
	else if (*open_quote == '"' && (*str)[*index])
	{
		if (is_subs_and_replace(data, str, index, 1) == 0)
			return (0);
		if (data->flag_enter && (*str)[*index])
			is_var_and_replace(data, str, index);
	}
	return (1);
}

int			true_var_and_subs(t_data *data, char **str)
{
	size_t	index;
	char	open_quote;

	index = 0;
	open_quote = '\0';
	while ((*str)[index])
	{
		while (ft_isspace2((*str)[index]))
			index++;
		if (!(*str)[index])
			continue ;
		while ((*str)[index] && !ft_isspace2((*str)[index]))
		{
			if (!replace_depending_quotes(data, str, &open_quote, &index))
				return (0);
			if ((*str)[index] && !data->subs_for_first_char)
				index++;
		}
	}
	return (1);
}
