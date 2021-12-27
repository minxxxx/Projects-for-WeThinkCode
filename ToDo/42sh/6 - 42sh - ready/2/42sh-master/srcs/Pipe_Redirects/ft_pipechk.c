/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipechk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 10:55:46 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/24 03:45:28 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
 ** If it has left arrows it will check if its a redirect or a heredoc
*/

void	ft_l_arrow(char *str, t_all *a)
{
	char	**holder;

	holder = ft_strsplit(str, '<');
	holder = ft_arrtrim(holder);
	a->piped = 1;
	if (ft_strstr(str, " < ") != NULL)
		ft_reverse_direct(holder, a);
	else if (ft_strstr(str, " << ") != NULL && ft_strncmp(str, "<<", 2) != 0)
		ft_heredoc(holder, a);
	else
		a->piped = 0;
	ft_delarray(holder);
}

/*
 ** If it has right arrows it will check if its a redirect or an append
*/

void	ft_r_arrow(char *str, t_all *a)
{
	char	**holder;

	holder = ft_strsplit(str, '>');
	holder = ft_arrtrim(holder);
	a->piped = 1;
	if (ft_strstr(str, " > ") != NULL)
	{
		if (ft_strstr(str, "2>&1") != NULL)
			ft_std_everything(holder, a);
		else
			ft_redirect_in(holder, a);
	}
	else if (ft_strstr(str, " >> ") != NULL)
	{
		if (ft_strstr(str, "2>&1") != NULL)
			ft_std_everything_append(holder, a);
		else
			ft_redirect_in_append(holder, a);
	}
	else if (ft_strstr(str, " 2> ") != NULL)
		ft_stderr(holder, a);
	ft_delarray(holder);
}

/*
 ** If it finds lines it will check if it's a pipe or an OR.
*/

void	ft_line(char *str, t_all *a)
{
	char	**holder;

	holder = ft_strsplit(str, '|');
	holder = ft_arrtrim(holder);
	a->piped = 1;
	if (ft_strstr(str, " | ") != NULL)
		ft_loop_pipe(holder, a);
	else if (ft_strstr(str, " || ") != NULL)
		ft_logical_or(holder, a);
	ft_delarray(holder);
}

/*
 ** Checks which sequence of commands to run depending on results
*/

int		ft_pipecheck(char *str, t_all *a)
{
	int		i;

	a->piped = 0;
	i = 0;
	if (ft_strstr(str, "echo `") != NULL)
	{
		a->piped = 1;
		ft_echo_cmds(str, a);
	}
	else if (ft_strstr(str, " > ") != NULL || ft_strstr(str, " >> ") != NULL
		|| ft_strstr(str, " 2> ") != NULL || ft_strstr(str, " 2>&1 ") != NULL)
		ft_r_arrow(str, a);
	else if (ft_strstr(str, " | ") != NULL || ft_strstr(str, " || ") != NULL)
		ft_line(str, a);
	else if (ft_strstr(str, " < ") != NULL || ft_strstr(str, " << ") != NULL)
		ft_l_arrow(str, a);
	else if (ft_strstr(str, " && ") != NULL)
		i = ft_and(str, a);
	return (i);
}
