/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:43:55 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/22 18:21:09 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_shell	*get_struct(t_shell *struc)
{
	static t_shell	*shell = NULL;

	if (struc == 0)
		return (shell);
	else
		shell = struc;
	return (0);
}

void	init_shell(t_shell *shell)
{
	shell->fd[0] = STDIN_FILENO;
	shell->fd[1] = STDOUT_FILENO;
	shell->fd[2] = STDERR_FILENO;
	if ((shell->fd[3] = open("/dev/tty", O_RDWR)) == -1)
		quit_error(1);
	shell->col = 0;
	shell->input_len = 0;
	shell->p_len = 0;
	shell->env_lst = NULL;
	shell->hist = NULL;
	shell->hist_end = 1;
	shell->input = NULL;
	shell->input_save = NULL;
	shell->buffer = NULL;
	shell->input_buf = NULL;
	shell->curs_pos = NULL;
	shell->tree = NULL;
	get_struct(shell);
}

int		main(int ac, char **av, char **environ)
{
	t_shell		*shell;

	(void)ac;
	(void)av;
	(void)environ;
	if (!(shell = (t_shell *)malloc(sizeof(*shell))))
		quit_error(9);
	set_sig_handler();
	init_shell(shell);
	init_term(shell);
	store_environ(shell, environ);
	read_input(shell);
	return (0);
}
