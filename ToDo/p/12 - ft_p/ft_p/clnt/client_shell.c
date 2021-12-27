/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 22:02:23 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 21:54:32 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <signal.h>
#include <unistd.h>
#include <sys/param.h>

static void		listen_and_print(t_env *env)
{
	int		ret;
	char	buf[1024];
	int		i;

	while ((ret = read(env->sock, buf, 1023)) > 0)
	{
		buf[ret] = '\0';
		i = -1;
		while (buf[++i])
		{
			if (buf[i] == EOF)
				return ;
			ft_putchar_fd(buf[i], 1);
		}
	}
}

static void		print_prompt(t_env *env)
{
	ft_putstr("\033[34mftpclient ");
	ft_putstr(env->addr);
	ft_putchar('@');
	ft_putstr(env->port);
	ft_putstr("\033[0m > ");
}

static t_env	*save_env(t_env *env)
{
	static t_env	*statenv = NULL;

	if (env)
		statenv = env;
	return (statenv);
}

static void		signal_ctrl_c(int sig)
{
	ft_putchar('\n');
	print_prompt(save_env(NULL));
	(void)sig;
}

void			client_shell(t_env *env)
{
	char	*line;
	int		ret;

	save_env(env);
	signal(SIGINT, &signal_ctrl_c);
	print_prompt(env);
	while (get_next_line(0, &line) > 0 && ft_strcmp(line, "quit")
		&& ft_strcmp(line, "exit"))
	{
		env->cmd = v_strsplit(line, ' ');
		if ((ret = is_cmd_valid(env)) == 1)
		{
			write(env->sock, line, ft_strlen(line));
			listen_and_print(env);
		}
		else if (!ret)
			write(1, "\033[31m[ERROR]\033[0m Unknown command\n", 33);
		print_prompt(env);
	}
	write(env->sock, "quit", 5);
}
