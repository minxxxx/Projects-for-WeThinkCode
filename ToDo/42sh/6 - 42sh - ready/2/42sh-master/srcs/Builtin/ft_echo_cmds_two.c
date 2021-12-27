/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_cmds_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 23:29:00 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:50:01 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
 ** exe echo cmds
*/

void	ft_echo_exe_cmd(char *str, t_all *a)
{
	char	*temp;

	temp = ft_strjoin(str, " | xargs");
	ft_line(temp, a);
	ft_strdel(&temp);
}
