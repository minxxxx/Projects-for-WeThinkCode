/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 15:43:33 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 13:03:52 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		ft_redirection_error(int err, char *file, int fd)
{
	if (err == 1)
		ft_putstr_fd("error: no such file or directory : ", fd);
	else if (err == 2)
		ft_putstr_fd("error: permission denied : ", fd);
	else if (err == 3)
	{
		ft_putstr_fd("-bash: parse error near `\\", fd);
		ft_putendl_fd("n'", fd);
	}
	else if (err == 4)
		ft_putstr_fd("error: could not open file : ", fd);
	else if (err == 5)
		ft_putstr_fd("-bash: command not found : ", fd);
	else if (err == 6)
		ft_putstr_fd("error: not a directory: ", fd);
	if (file != NULL)
		ft_putendl_fd(file, fd);
	return (-1);
}
