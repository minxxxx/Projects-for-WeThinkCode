/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 21:19:02 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:20:23 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "env.h"
#include "shell.h"
#include "parser.h"

static void		ft_small_init(char **env)
{
	myenv_control_tower(env, NULL, NULL, "load");
	tgetent(0, getenv("TERM"));
	tputs(tgetstr("sc", 0), 0, ft_shell_putchar);
}

int				main(int ac, char **av, char **env)
{
	t_term	*shell;
	int		ret;

	if (ac != 1 || av[1] != NULL)
		return (1);
	ft_small_init(env);
	shell = ft_init_shell();
	ret = 0;
	while (1)
	{
		ret = ft_read_entry(&shell);
		if (ret == 1 && shell->std_usr == 1)
			ft_exec_quotes(&shell);
		if (ret == 1 && shell->std_usr == 0)
		{
			if (ft_strlen(shell->save) > 0)
				ft_parser_control_tower(shell->line);
			ft_memset(shell->line, 0, MAX_LEN);
			ft_putstr(shell->prt);
			shell->std_cur = ft_strlen(shell->prt);
			ft_strdel(&shell->save);
			tputs(tgetstr("sc", 0), 0, ft_shell_putchar);
		}
	}
	return (0);
}
