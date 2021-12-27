/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_advanced_subs_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void		delete_subs_and_replace(char **str,
	size_t index, size_t length, char *arg)
{
	char *new_str;

	if (index > 0)
		new_str = ft_strsub(*str, 0, index);
	else
		new_str = ft_strdup("");
	new_str = ft_strjoinaf12(new_str, arg);
	new_str = ft_strjoinaf1(new_str, *str + length);
	free(*str);
	*str = new_str;
}

char		*find_subs_in_parsing(t_data *data, char *str, size_t length)
{
	t_history	*list;
	char		*arg;
	char		*pattern;
	int			len;

	if (data->history == NULL)
		return (NULL);
	list = data->history;
	arg = NULL;
	pattern = ft_strsub(str, 0, length);
	len = (int)ft_strlen(pattern);
	while (list)
	{
		if (ft_strnequ(pattern, list->line, len))
		{
			free(pattern);
			return (ft_strdup(list->line));
		}
		list = list->prec;
	}
	free(pattern);
	return (arg);
}

int			subs_for_last_command(t_data *data, char **arg, size_t *length)
{
	if (data->history != NULL)
		*arg = ft_strdup(data->history->line);
	else
		return (0);
	(*length)++;
	return (1);
}

int			subs_for_command_number(t_data *data, char **arg,
	char **str, size_t *length)
{
	while (ft_isdigit((*str)[*length]))
		(*length)++;
	if ((*arg = history_subsitution_nb_arg(data, *str + data->subs_index + 1))
		== NULL)
		return (0);
	return (1);
}

int			subs_default(t_data *data, char **arg, char **str, size_t *length)
{
	if (data->subs_flag == 0)
	{
		while (ft_isspace2((*str)[*length]) == 0 && (*str)[*length])
			(*length)++;
	}
	else if (data->subs_flag == 1)
	{
		while (ft_isspace2((*str)[*length]) == 0 && (*str)[*length] != '"'
			&& (*str)[*length])
			(*length)++;
	}
	if (*length - (data->subs_index + 1) == 0)
	{
		ft_putstr_fd("42sh: incorrect pattern for '!'\n", 2);
		return (0);
	}
	if ((*arg = find_subs_in_parsing(data, *str + data->subs_index + 1,
		*length - (data->subs_index + 1))) == NULL)
	{
		ft_putstr_fd("42sh: event not found\n", 2);
		return (0);
	}
	return (1);
}
