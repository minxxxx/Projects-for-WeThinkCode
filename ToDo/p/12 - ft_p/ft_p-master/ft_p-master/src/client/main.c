/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 16:19:03 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 16:29:30 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void		reinit_data(t_data *data)
{
	data->error = 0;
	if (data->cmd_str)
		free(data->cmd_str);
	free_cmd(data->cmd);
}

int			init_data(t_data *data, char **av)
{
	if ((data->port = ft_atoi(av[2])) <= 0)
	{
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd(": invalid port\n", 2);
		return (1);
	}
	data->machine = av[1];
	data->prompt = ft_strdup("ft_p$ ");
	data->error = 0;
	data->cmd_str = NULL;
	if (!(data->socket = create_socket(data->port, av[0], data->machine)))
		return (1);
	return (0);
}

static int	print_usage_and_ret(char *av)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd(" <machine> <port>\n", 2);
	return (1);
}

static void	boucle_principale(t_data *data, char **cmd)
{
	handle_line(data, *cmd);
	print_prompt(data, 1);
	ft_strdel(cmd);
	reinit_data(data);
}

int			main(int ac, char **av)
{
	t_data			data;
	char			*cmd;
	t_command_func	tab[50];
	t_answer		answer;

	if (ac != 3)
		return (print_usage_and_ret(av[0]));
	singleton_data(&data);
	signal(SIGINT, sigint);
	if (init_data(&data, av))
		return (1);
	answer = get_answer(&data);
	if (answer.error <= 0)
		error_connection(&data);
	ft_printf("%s\n", answer.str);
	free_answer(answer);
	data.tab = tab;
	init_tab(data.tab);
	print_prompt(&data, 0);
	while (get_next_line(0, &cmd))
		boucle_principale(&data, &cmd);
	free(data.prompt);
	return (0);
}
