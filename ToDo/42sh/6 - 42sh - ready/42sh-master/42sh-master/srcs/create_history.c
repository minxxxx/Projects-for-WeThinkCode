/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void		parse_and_exec(t_data *data, t_env **env)
{
	if (data->cmd_tmp[0] == '\0')
	{
		free(data->cmd_tmp);
		data->cmd_tmp = ft_strdup("");
	}
	else if (data->quote_or_hd == 0)
		data->cmd = ft_strjoinaf2(data->cmd_tmp, data->cmd);
	data->index = 0;
	invert_term();
	signal(SIGINT, SIG_IGN);
	exec_cmd(env, parse(data->cmd, data->heredocs, env, data), data);
	signal(SIGINT, sigint);
	invert_term();
	data->c = '\0';
	reinitialise_heredoc(data, 1);
	if (data->cmd_tmp)
		free(data->cmd_tmp);
	data->cmd_tmp = ft_strdup("");
	data->quote_old_index = 0;
	if (data->list_auto)
		delete_list_auto(data->list_auto);
	data->list_auto = NULL;
	delete_list_command(data->command);
	data->command = NULL;
}

static int		create_history_handle_heredoc(t_data *data)
{
	if (is_key(data))
	{
		reinitialise_heredoc(data, 0);
		return (1);
	}
	else
	{
		if (data->first_line_of_hd == 0)
		{
			data->heredocs_tmp = ft_strjoinaf1(data->heredocs_tmp, data->cmd);
			data->heredocs_tmp = ft_strjoinaf1(data->heredocs_tmp, "\n");
		}
		data->first_line_of_hd = 0;
	}
	return (0);
}

static int		command_not_finished(t_data *data, int i)
{
	if (i == -1)
		reinitialise_heredoc(data, 1);
	else if (data->c == '<')
	{
		if (create_history_handle_heredoc(data))
			return (1);
	}
	else if (data->c == '\0')
	{
		free(data->cmd_tmp);
		data->cmd_tmp = ft_strdup("");
	}
	else
	{
		data->cmd_tmp = ft_strjoinaf1(data->cmd_tmp, data->cmd);
		data->cmd_tmp = ft_strjoinaf1(data->cmd_tmp, "\n");
	}
	data->index++;
	return (0);
}

int				create_history(t_data *data, t_env **env)
{
	int i;

	i = 0;
	ft_putstr("\n");
	if (true_var_and_subs(data, &data->cmd) && data->c != '<' &&
		(i = is_quote_end(data)) == 0 && (data->cmd[0] != '\0'))
		parse_and_exec(data, env);
	else if (command_not_finished(data, i))
		return (create_history(data, env));
	free(data->prompt);
	data->prompt = print_prompt(*env, data);
	data->len_prompt = ft_strlen(data->prompt);
	data->real_len_cmd = 0;
	if (data->first)
	{
		free(data->first);
		data->first = NULL;
	}
	data->first_search = 1;
	data->history_en_cours = NULL;
	if (data->cmd)
		free(data->cmd);
	data->cmd = ft_strdup("");
	data->index = 0;
	return (0);
}
