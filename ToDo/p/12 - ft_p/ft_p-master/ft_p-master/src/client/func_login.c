/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_login.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:46:10 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 15:53:41 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static void	fln(t_data *data, char *password)
{
	char	*send;

	send = build_request(NAME_RFC_PASS, password);
	write(data->socket, send, ft_strlen(send));
	free(send);
}

static void	pass_part(t_data *data, char *password)
{
	t_answer answer;

	fln(data, password);
	answer = get_answer(data);
	if (answer.error <= 0)
		error_connection(data);
	if (answer.code == 530)
	{
		ft_printf("%s\n", answer.str);
		free_answer(answer);
		return (set_error_and_ret(data, NULL, NULL));
	}
	else if (answer.code == 230)
	{
		free_answer(answer);
		return (pem(NULL, "Login successful."));
	}
	else
	{
		ft_printf("Error: %s\n", answer.commentaire);
		free_answer(answer);
		return (set_error_and_ret(data, NULL, NULL));
	}
}

static int	check_cases(t_data *data, t_answer answer, char *password)
{
	if (answer.error <= 0)
		error_connection(data);
	if (answer.code == 331 && !password)
	{
		ft_printf("%s\n", answer.str);
		data->error = 1;
		free_answer(answer);
		return (1);
	}
	else if (answer.code == 230)
	{
		ft_putstr("Login successful.\n");
		free_answer(answer);
		return (1);
	}
	else if (answer.code != 331)
	{
		ft_printf("%s\n", answer.str);
		data->error = 1;
		free_answer(answer);
		return (1);
	}
	return (0);
}

void		func_login(t_data *data)
{
	t_answer	answer;
	t_cmd		*cmd;
	char		*send;
	char		*username;
	char		*password;

	cmd = &(data->cmd);
	if (cmd->cmd_tab[1] == NULL)
	{
		ft_putstr("Usage: login username [password]\n");
		data->error = 1;
		return ;
	}
	username = cmd->cmd_tab[1];
	send = build_request(NAME_RFC_USER, username);
	password = NULL;
	if (cmd->cmd_tab[2])
		password = cmd->cmd_tab[2];
	write(data->socket, send, ft_strlen(send));
	free(send);
	answer = get_answer(data);
	if (check_cases(data, answer, password))
		return ;
	pass_part(data, password);
}
