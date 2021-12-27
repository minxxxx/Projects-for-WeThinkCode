/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_advanced_var_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	free_arg_and_stop(char **arg)
{
	free(*arg);
}

static int	delete_var(char **str, size_t index, size_t length, char *arg)
{
	char *new_str;

	if (index > 0)
		new_str = ft_strsub(*str, 0, index - 1);
	else
		new_str = ft_strdup("");
	new_str = ft_strjoinaf1(new_str, (*str) + length);
	free(*str);
	free(arg);
	*str = new_str;
	return (1);
}

static void	wrong_var_and_stop(t_data *d, char *arg, char **str, size_t *index)
{
	delete_var(str, *index + 1, d->var_length, arg);
	*index = d->var_index_begin;
	return ;
}

static void	search_arg_in_env(t_data *d, char **arg, char **str, size_t *index)
{
	char	tmp_char;

	tmp_char = (*str)[d->var_length];
	(*str)[d->var_length] = '\0';
	*arg = find_var_env(d, *str + *index + 1, d->env);
	(*str)[d->var_length] = tmp_char;
}

void		is_var_and_replace(t_data *data, char **str, size_t *index)
{
	char	*arg;

	if (!is_escaped_char(*str, *index) && (*str)[*index] == '$')
	{
		data->var_index_begin = *index;
		data->var_length = *index + 1;
		if ((*str)[*index + 1] == '?')
		{
			data->var_length++;
			arg = ft_itoa_base(data->ret, 10);
			delete_var_and_replace(str, *index, data->var_length, arg);
			return ;
		}
		while (ft_isalnum((*str)[data->var_length]))
			data->var_length++;
		search_arg_in_env(data, &arg, str, index);
		if (data->var_length - (*index + 1) == 0)
			return (free_arg_and_stop(&arg));
		if (ft_strequ(arg, ""))
			return (wrong_var_and_stop(data, arg, str, index));
		else
			delete_var_and_replace(str, *index, data->var_length, arg);
		*index = data->var_length - (*index + 1);
	}
}
