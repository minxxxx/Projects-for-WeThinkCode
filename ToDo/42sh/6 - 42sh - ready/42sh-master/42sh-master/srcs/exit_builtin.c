/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void		reinitialise_heredoc_flag_true(t_data *data)
{
	free_heredoc(data, data->heredocs);
	data->end_hd = 0;
	data->quote_or_hd = 0;
	data->first_line_of_hd = 1;
	data->quote_old_index = 0;
}

static void		reinitialise_heredoc_flag_false(t_data *data)
{
	data->c = '\0';
	free(data->cmd);
	data->heredocs = add_hc_elem(data->heredocs,
			create_hc_elem(ft_strdup(data->heredocs_tmp)));
	if (data->cmd_tmp && data->cmd_tmp[0] != '\0')
	{
		free(data->cmd_tmp);
		data->cmd_tmp = ft_strdup("");
	}
	data->index = data->old_index;
	data->real_len_cmd = 0;
	data->quote_or_hd = 1;
	data->cmd = ft_strdup(data->command_save);
	if (data->command_save)
		free(data->command_save);
	data->command_save = NULL;
}

void			reinitialise_heredoc(t_data *data, int flag)
{
	if (flag)
		reinitialise_heredoc_flag_true(data);
	else
		reinitialise_heredoc_flag_false(data);
	if (data->key_here)
	{
		free(data->key_here);
		data->key_here = NULL;
	}
	if (data->heredocs_tmp && data->heredocs_tmp[0] != '\0')
	{
		free(data->heredocs_tmp);
		data->heredocs_tmp = ft_strdup("");
	}
}

void			delete_heredocs(t_data *data)
{
	free_heredoc(data, data->heredocs);
	if (data->heredocs_tmp)
		free(data->heredocs_tmp);
	if (data->key_here)
		free(data->key_here);
}

int				ft_exit_bi(char **scmd, t_env *env, t_data *data)
{
	int	tmp;

	tmp = (scmd && scmd[1] ? ft_atoi(scmd[1]) : -1);
	free(singleton_termios(NULL, 0));
	history_exit(data);
	delete_list(env);
	delete_heredocs(data);
	delete_list_history(data->history);
	if (data->command)
		delete_list_command(data->command);
	delete_list_var(data->var);
	delete_list_auto(data->list_auto);
	delete_data(data);
	if (tmp != -1)
	{
		exit(tmp);
	}
	exit(EXIT_SUCCESS);
}
