/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 23:19:40 by wide-aze          #+#    #+#             */
/*   Updated: 2015/10/25 14:53:46 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

#define DEB_ "-----------------------"
#define DEB_START_MSG (" " DEB_ "\n|     DEBUG ENABLED     |\n " DEB_)
#define DEB_END_MSG (" " DEB_)

static void		print_opt(t_env *env)
{
	ft_putstr("OPTIONS ENABLED:");
	if (OPT_A)
		ft_putstr(" a");
	if (OPT_K)
		ft_putstr(" k");
	if (OPT_Q)
		ft_putstr(" q");
	ft_putchar('\n');
}

static void		print_cmd(t_env *env)
{
	int		i;

	i = -1;
	ft_putstr("CMD:");
	while (++i < NB_CMD)
	{
		ft_putchar(' ');
		ft_putstr(CMD(i));
	}
	ft_putstr(" (");
	ft_putnbr(NB_CMD);
	ft_putstr(")\n");
}

static void		print_flush_time(t_env *env)
{
	ft_putstr("FLUSH TIME: ");
	ft_putnbr(OPT_T_VALUE);
	if (START_AND_STOP_DIRECTLY)
		ft_putstr_col(" /!\\ START_AND_STOP_DIRECTLY /!\\", 31);
	ft_putchar('\n');
}

static void		print_timeout(t_env *env)
{
	ft_putstr("TIMEOUT: ");
	if (OPT_M_ENABLED)
	{
		ft_putstr("enabled (");
		ft_putnbr(OPT_M_VALUE);
		ft_putstr(" seconds)");
	}
	else
		ft_putstr("disabled");
	ft_putchar('\n');
}

void			print_debug(t_env *env)
{
	if (!DEBUG_MODE)
		return ;
	ft_putendl_col(DEB_START_MSG, 32);
	print_opt(env);
	print_cmd(env);
	print_flush_time(env);
	print_timeout(env);
	ft_putstr("SHELL: ");
	ft_putendl(SHELLNAME);
	ft_putstr("FILENAME: ");
	ft_putendl((FILENAME) ? FILENAME : "typescript");
	ft_putendl_col(DEB_END_MSG, 32);
}
