/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 10:33:50 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:57:21 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define FREEARRAY if(*a.new[0]!='\0')ft_delarray(a.new)
#define SIGNAL_1 signal(SIGINT, signal_sigint_main);
#define SIGNAL_2 signal(SIGTSTP, signal_sigkill_main);
#define SIGNALS SIGNAL_1;SIGNAL_2;p = fork()
#define CHECK_EXIT if(e==25)exit(1)

/*
 ** This will increment the shell level in the enviroment by one
*/

void				ft_shlvl(t_all *a)
{
	int				i;
	int				n;
	char			**str;
	char			*temp;

	i = 0;
	while (ft_strstr(a->new[i], "SHLVL=") == NULL)
		i++;
	str = ft_strsplit(a->new[i], '=');
	n = ft_atoi(str[1]);
	free(str[1]);
	n = n + 1;
	str[1] = ft_itoa(n);
	str[0] = ft_addequal(str[0]);
	temp = ft_strjoin(str[0], str[1]);
	free(a->new[i]);
	a->new[i] = ft_strdup(temp);
	ft_delarray(str);
	ft_strdel(&temp);
}

/*
 ** Some fancy method of printing current directory.
*/

void				ft_print_dir(void)
{
	char			dir[4096];
	char			**path;
	int				i;
	int				n;

	i = 0;
	if (getcwd(dir, sizeof(dir)) == NULL)
		ft_putendl("getcwd error");
	else
	{
		n = ft_strlen(dir);
		if (n > 1)
		{
			path = ft_strsplit(dir, '/');
			i = ft_arraylen(path) - 1;
			ft_putstr(CYAN1"[");
			ft_putstr(path[i]);
			ft_putstr("] "RESET);
			ft_delarray(path);
		}
		else
			ft_putstr(CYAN1"[/] "RESET);
	}
}

void				ft_loop_cmds(char **cmds, t_all *a, struct termios *term)
{
	while (*cmds != NULL)
	{
		ft_sequence(*cmds, a, term);
		cmds++;
	}
}

/*
** This is the heart of the shell, it runs and infinite while loop, prints a
** dir as a name, waits for input, and sends input to run the cmds/builtins
** that matches
*/

void				ft_hist_sub(t_all *a, struct termios *term)
{
	char			**cmds;

	if (a->c[0] != '\0')
		ft_add_to_hist(a->c, a);
	if (a->c[0] == '!')
		a->c = ft_exec_history(a->c, a);
	if (a->c[0] == '(')
		ft_subshell(a->c, a, 0, term);
	else if (ft_isprint(a->c[0]) != 0 || ft_hasprintable(a->c) > 0)
	{
		if (ft_strchr(a->c, ';') != NULL)
		{
			cmds = ft_strsplit_colon(a->c, ';');
			ft_loop_cmds(cmds, a, term);
			ft_delarray(cmds);
		}
		else
			ft_sequence(a->c, a, term);
	}
}

void				ft_loop(char **env)
{
	struct termios	term;
	t_all			a;

	a.new = ft_arraydup(env);
	ft_shlvl(&a);
	ft_createhistory(&a);
	a.history = ft_set_heredoc_arr();
	a.c = "";
	a.i = ft_get_dir();
	while (1)
	{
		handle_signals(&a);
		ft_print_dir();
		non_canonical(&term, "start");
		while (keyhook(&a))
			;
		non_canonical(&term, "end");
		ft_hist_sub(&a, &term);
		ft_strdel(&a.c);
		a.c = ft_strnew(1);
		a.i = ft_get_dir();
	}
	FREEARRAY;
}
