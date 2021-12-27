/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_add_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/03 18:10:50 by adomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void		command_with_semicolon(t_data *data, char *str,
		size_t *i, t_env **env)
{
	data->command = add_cmd_elem(data->command, create_cmd_elem(
				ft_strsub(str, data->parse_old_i, *i - data->parse_old_i),
				data->parse_count, data->parse_heredocs));
	exec_cmd(env, data->command, data);
	delete_list_command(data->command);
	data->command = NULL;
}

static int		command_with_logical_operators(t_data *data, char *str,
		size_t *i, t_env **env)
{
	data->command = add_cmd_elem(data->command, create_cmd_elem(
				ft_strsub(str, data->parse_old_i, *i - data->parse_old_i),
				data->parse_count, data->parse_heredocs));
	exec_cmd(env, data->command, data);
	data->command->sep = def_sep(str + *i - 2);
	if (data->command && ((data->command->ret == 0 &&
					data->command->sep == OUOU) || (data->command->ret != 0 &&
						data->command->sep == ETET)))
	{
		delete_list_command(data->command);
		data->command = NULL;
		while (str[*i] && str[*i] != ';' && !ft_strnequ(str + *i, "||", 2))
			(*i)++;
		if (str[*i] && (str[*i] == ';' || ft_strnequ(str + *i, "||", 2)))
			(*i) += (str[*i] == ';') ? 1 : 2;
		else
			return (0);
		return (1);
	}
	delete_list_command(data->command);
	data->command = NULL;
	return (1);
}

int				add_command(t_data *data, char *str, size_t *i, t_env **env)
{
	if (str[*i - 1] == ';')
		command_with_semicolon(data, str, i, env);
	else if (*i > 2 && (ft_strnequ(str + *i - 2, "||", 2) ||
				ft_strnequ(str + *i - 2, "&&", 2)))
	{
		if (!command_with_logical_operators(data, str, i, env))
			return (0);
	}
	else
		data->command = add_cmd_elem(data->command, create_cmd_elem(
					ft_strsub(str, data->parse_old_i, *i - data->parse_old_i),
					data->parse_count, data->parse_heredocs));
	return (1);
}
