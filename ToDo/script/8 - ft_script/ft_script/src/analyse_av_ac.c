/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_av_ac.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 17:08:12 by wide-aze          #+#    #+#             */
/*   Updated: 2015/11/06 22:55:20 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

#define HELP1 "ft_script -- make typescript of terminal session\n\n"
#define HELP2 "\n\nThe following options are available:\n"
#define HELP3 "-a	Append the output to file at EOF\n"
#define HELP4 "-k	Log keys sent to program as well as output\n"
#define HELP5 "-q	Quiet mode (no start/end message)\n"
#define HELP6 "-t	Specify time interval between flushing script output file\n"
#define HELP7 "-s	Choose the shell you want to use (full path)\n"
#define HELP8 "-m	Set a timeout which will stop the script\n"
#define HELP9 "-h	Show help (or --help)\n-d	Enable debug mode (or --debug)"
#define USG_MSG "usage: ./ft_script [--help] [-adkq] [-tsm value] [file [cmd]]"
#define HELP_MSG (HELP1 USG_MSG HELP2 HELP3 HELP4 HELP5 HELP6 HELP7 HELP8 HELP9)
#define NEED_ARG_MSG_T ("ft_script: option requires an argument -- t\n" USG_MSG)
#define NEED_ARG_MSG_S ("ft_script: option requires an argument -- s\n" USG_MSG)
#define BAD_T_TIME_MSG1 "ft_script: invalid flush time "
#define BAD_T_TIME_MSG2 ": Undefined error: 0"
#define BAD_T_TIME_MSG3 ": Result too large"
#define NEED_ARG_MSG_M ("ft_script: option requires an argument -- m\n" USG_MSG)
#define FTLEN(x) ft_strlen(x)

static char		**ft_putendl_ret_null(const char *toprint)
{
	ft_putendl(toprint);
	return (NULL);
}

static char		**t_opt_found(t_env *env, char *arg, int *ac, char **av)
{
	int		nb;

	if (*arg == '\0')
		return (av);
	if (is_zero(arg))
	{
		OPT_T_VALUE = 0;
		return (av);
	}
	if (FTLEN(arg) > 11 || (*arg != '-' && *arg != '+' && FTLEN(arg) > 10))
	{
		ft_putstr(BAD_T_TIME_MSG1);
		ft_putstr(arg);
		return (ft_putendl_ret_null(BAD_T_TIME_MSG3));
	}
	if (!ft_str_isint2(arg) || (nb = ft_atoi(arg)) < 0)
	{
		ft_putstr(BAD_T_TIME_MSG1);
		ft_putstr(arg);
		return (ft_putendl_ret_null(BAD_T_TIME_MSG2));
	}
	if (nb)
		OPT_T_VALUE = nb;
	(*ac)--;
	return (++av);
}

static int		other_opt_found(t_env *env, char *arg)
{
	while (*(++arg))
	{
		if (*arg == 'a')
			OPT_A = TRUE;
		else if (*arg == 'd')
			DEBUG_MODE = TRUE;
		else if (*arg == 'k')
			OPT_K = TRUE;
		else if (*arg == 'q')
			OPT_Q = TRUE;
		else if (*arg == 's' || *arg == 'm' || *arg == 't')
			continue ;
		else
		{
			ft_putstr("ft_script: illegal option -- ");
			ft_putchar(*arg);
			ft_putchar('\n');
			return (ft_putendl_ret(USG_MSG, -1));
		}
	}
	return (0);
}

static char		**analyze_av_ac2(t_env *env, int *ac, char **av)
{
	if (ft_strequ(*av, "-s"))
	{
		if (*ac <= 1)
			return (ft_putendl_ret_null(NEED_ARG_MSG_S));
		if (!(av = s_opt_found(env, av[1], ac, av)))
			return (NULL);
	}
	else if (ft_strequ(*av, "-m"))
	{
		if (*ac <= 1)
			return (ft_putendl_ret_null(NEED_ARG_MSG_M));
		if (!(av = m_opt_found(env, av[1], ac, av)))
			return (NULL);
	}
	else if (ft_strequ(*av, "--debug"))
		DEBUG_MODE = TRUE;
	else if (**av == '-')
	{
		if (other_opt_found(env, *av))
			return (NULL);
	}
	return (av);
}

int				analyze_av_ac(t_env *env, int ac, char **av)
{
	while (ac)
	{
		if (ft_strequ(*av, "--help") || ft_strequ(*av, "-h"))
			return (ft_putendl_ret(HELP_MSG, -1));
		if (ft_strequ(*av, "-t"))
		{
			if (ac <= 1)
				return (ft_putendl_ret(NEED_ARG_MSG_T, -1));
			if (!(av = t_opt_found(env, av[1], &ac, av)))
				return (-1);
		}
		else if (**av == '-')
		{
			if (!(av = analyze_av_ac2(env, &ac, av)))
				return (-1);
		}
		else
			return (filename_found(env, ac, av));
		ac--;
		av++;
	}
	return (0);
}
