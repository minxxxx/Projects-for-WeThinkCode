/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:09:17 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:10 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

char	*ft_complete_cmd(char special, char *separator)
{
	char		*line;
	char		*full_cmd;

	line = NULL;
	full_cmd = ft_strjoin(g_main_line.cmd, separator);
	while (!line || !ft_strchr(line, special))
	{
		ft_putstr(">");
		get_next_line(0, &line);
		full_cmd = ft_strjoin(full_cmd, line);
		full_cmd = ft_strjoin(full_cmd, separator);
	}
	return (full_cmd);
}
