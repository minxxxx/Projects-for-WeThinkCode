/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_av_ac2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 17:08:12 by wide-aze          #+#    #+#             */
/*   Updated: 2015/11/06 22:58:13 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

#define BAD_M_VALUE_MSG1 "ft_script: invalid timeout value "
#define BAD_M_TIME_MSG1 "ft_script: invalid flush time "
#define BAD_M_TIME_MSG2 ": Undefined error: 0"
#define BAD_M_TIME_MSG3 ": Result too large"

t_bool			is_zero(char *arg)
{
	int		i;

	i = 0;
	if (*arg == '+' || *arg == '-')
		arg++;
	while (arg[i] == '0')
		i++;
	if (!ft_isdigit(arg[i]) && i)
		return (TRUE);
	return (FALSE);
}

static char		**m_opt_found2(char *arg, t_bool ismsg2)
{
	ft_putstr(BAD_M_VALUE_MSG1);
	ft_putstr(arg);
	if (ismsg2)
		ft_putendl(BAD_M_TIME_MSG2);
	else
		ft_putendl(BAD_M_TIME_MSG3);
	return (NULL);
}

char			**m_opt_found(t_env *env, char *arg, int *ac, char **av)
{
	int		nb;

	if (*arg == '\0' || is_zero(arg))
		return (av);
	if (ft_strlen(arg) > 11 || (*arg != '-' && *arg != '+'
	&& ft_strlen(arg) > 10))
		return (m_opt_found2(arg, FALSE));
	if (!ft_str_isint2(arg) || (nb = ft_atoi(arg)) < 0)
		return (m_opt_found2(arg, TRUE));
	if (nb)
	{
		OPT_M_VALUE = nb;
		OPT_M_TIME = OPT_M_VALUE + get_time();
		OPT_M_ENABLED = TRUE;
	}
	(*ac)--;
	return (++av);
}

char			**s_opt_found(t_env *env, char *arg, int *ac, char **av)
{
	if (arg && arg[0])
	{
		OPT_S_ENABLED = TRUE;
		SHELLNAME = arg;
		(*ac)--;
		return (++av);
	}
	return (NULL);
}

int				filename_found(t_env *env, int ac, char **av)
{
	if (!ft_strlen(*av))
		return (ft_putendl_ret("./ft_script: : No such file or directory", -1));
	FILENAME = *av;
	if (ac > 1)
	{
		CMD_TAB = av + 1;
		NB_CMD = ac - 1;
	}
	return (0);
}
