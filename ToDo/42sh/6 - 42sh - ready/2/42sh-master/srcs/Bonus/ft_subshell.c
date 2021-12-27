/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subshell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:46:23 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:47:42 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define ONE count++;s.c = ft_strnew(1);cmds = NULL
#define TWO ft_print_sub(count);non_canonical(term, "start")
#define THR TWO; while(keyhook_sub(&s))a->yes=1;non_canonical(term, "end")
#define F if(s.c[0] != '\0')ft_strdel(&s.c)
#define N ft_delarray(cmds)
#define O ft_strdel(&cmds[ft_arraylen(cmds)-1]);ft_exe_sub_arr(cmds,a,term);N
#define FF if (cmds[0][0] != '\0' && cmds[0][0] != ')') O
#define VAR char **cmds;t_subsh	s

/*
 ** If subshell was open it now has to execute multiple commands hence this is
 ** the purpose of this function.
*/

void	ft_exe_sub_arr(char **cmds, t_all *a, struct termios *term)
{
	int		i;

	i = -1;
	while (cmds[++i] != NULL)
		ft_sequence(cmds[i], a, term);
}

/*
 ** If subshell is closed it will execute the single command
*/

void	ft_exe_sub(char *cmd, t_all *a, struct termios *term)
{
	ft_memmove(cmd, cmd + 1, ft_strlen(cmd));
	cmd[(ft_strlen(cmd) - 1)] = '\0';
	ft_sequence(cmd, a, term);
}

/*
 ** Prints the correct amount of subshells
*/

void	ft_print_sub(int count)
{
	ft_putstr_fd("\n", 0);
	while (count > 1)
	{
		ft_putstr(YELLOW"subshell "RESET);
		count--;
	}
	ft_putstr(YELLOW"subshell> "RESET);
}

/*
 ** Checks if it will rum the cmd or open the subshell loop
*/

void	ft_subshell(char *cmd, t_all *a, int count, struct termios *term)
{
	VAR;
	ONE;
	if (cmd[0] == '(' && cmd[(ft_strlen(cmd) - 1)] == ')')
		ft_exe_sub(cmd, a, term);
	else
	{
		cmds = ft_set_heredoc_arr();
		while (1)
		{
			THR;
			if (s.c[0] == '(')
				ft_subshell(s.c, a, count, term);
			else if (ft_strstr(s.c, ")") != NULL)
			{
				cmds = ft_add_to_array(cmds, s.c);
				break ;
			}
			else
				cmds = ft_add_to_array(cmds, s.c);
			ft_strdel(&s.c);
			s.c = ft_strnew(1);
		}
		FF;
		F;
	}
}
