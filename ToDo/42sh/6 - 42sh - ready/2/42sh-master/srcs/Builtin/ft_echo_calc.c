/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:13:58 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:49:39 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void		ft_pipe_equation(char *equation, t_all *a)
{
	char	*cmd;
	char	*pipe;

	cmd = ft_strjoin("echo ", equation);
	pipe = ft_strjoin(cmd, " | bc");
	ft_pipecheck(pipe, a);
	ft_strdel(&cmd);
	ft_strdel(&pipe);
}

void		ft_echo_calc(char *str, t_all *a)
{
	char	*math;
	int		i;
	int		len;

	i = 7;
	len = 0;
	a->yes = 1;
	while (str[i++] != ')')
		len++;
	math = (char *)malloc(sizeof(char) * (len + 1));
	i = 8;
	len = 0;
	while (str[i] != ')')
	{
		math[len] = str[i];
		len++;
		i++;
	}
	math[len] = '\0';
	ft_pipe_equation(math, a);
	ft_strdel(&math);
}
