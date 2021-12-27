/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:47:37 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/02 15:27:38 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

char	*print_prompt_2(t_env *env, t_data *data, char *prompt)
{
	char	*new;
	char	*tmp;

	new = find_var_env(data, "PROMPT", env);
	if (ft_strequ(new, ""))
	{
		free(new);
		new = getcwd(NULL, 0);
		if (!new)
		{
			tmp = find_var_env(data, "HOME", env);
			if (ft_strequ(tmp, ""))
				tmp = ft_strjoinaf1(tmp, "/");
			change_arg(env, "PWD", tmp);
			chdir(tmp);
			new = getcwd(NULL, 0);
			free(tmp);
		}
		prompt = ft_strdup("<");
		prompt = ft_strjoinaf12(prompt, new);
		prompt = ft_strjoinaf1(prompt, ">$ ");
	}
	else
		prompt = new;
	return (prompt);
}

char	*print_prompt(t_env *env, t_data *data)
{
	char	*prompt;

	prompt = NULL;
	ft_putstr("\e[38;5;208m");
	if (data->c != '\0')
	{
		prompt_quote(data);
		ft_putstr("\e[39m");
		return (data->prompt);
	}
	prompt = print_prompt_2(env, data, prompt);
	ft_putstr(prompt);
	ft_putstr("\e[39m");
	if (isatty(0) && (int)ft_strlen(prompt) == data->win_x)
	{
		data->index = 0;
		move_r2l(data);
		data->index--;
	}
	return (prompt);
}

void	init_heredocs(t_data *data)
{
	data->heredocs = NULL;
	data->key_here = NULL;
	data->heredocs_tmp = ft_strdup("");
	data->command_save = NULL;
	data->end_hd = 0;
	data->quote_or_hd = 0;
	data->first_line_of_hd = 1;
	get_index_min_win(data);
	init_history(data);
	singleton_data(data, 1);
}

void	init_data(t_data *data)
{
	data->c = '\0';
	get_winsize(data);
	data->prompt = print_prompt(data->env, data);
	data->len_prompt = ft_strlen(data->prompt);
	data->cmd = ft_strdup("");
	data->index = 0;
	data->real_len_cmd = 0;
	data->history = NULL;
	data->history_en_cours = NULL;
	data->first = NULL;
	data->first_search = 1;
	data->cmd_tmp = ft_strdup("");
	data->quote_old_index = 0;
	data->mode_copy = 0;
	data->clipboard = NULL;
	data->list_auto = NULL;
	data->cmd_before_auto = NULL;
	data->index_before_auto = 0;
	data->absolute_cmd_before_auto = NULL;
	data->absolute_cmd_before_cmd_before_move = NULL;
	data->index_before_move = 0;
	data->ret = 0;
	data->index_max_copy = 0;
	init_heredocs(data);
}

int		main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac > 1)
	{
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	data.env = ft_parse_env(env);
	data.var = NULL;
	if (singleton_termios(init_term(&data), 1) == NULL)
	{
		ft_putstr_fd("42sh: Can't find terminal definition. Exiting now.\n", 2);
		delete_list(data.env);
		return (0);
	}
	signal(SIGINT, sigint);
	signal(SIGWINCH, sigwinch);
	init_data(&data);
	signal_handler();
	boucle(data.env, &data);
	return (0);
}
