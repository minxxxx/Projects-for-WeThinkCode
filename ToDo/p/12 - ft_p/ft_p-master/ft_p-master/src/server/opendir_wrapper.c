/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir_wrapper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:46 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:48 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int	can_be_oppenedir(const char *path, const char *exec_path)
{
	char	*prec;
	char	*next;

	prec = get_current_dir();
	if (chdir(path) == -1)
		return (free_and_ret(prec, NULL, NULL, 0));
	next = get_current_dir();
	chdir(prec);
	if (ft_strncmp(next, exec_path, ft_strlen(exec_path)) != 0)
		return (free_and_ret(prec, next, NULL, 0));
	else
		return (free_and_ret(prec, next, NULL, 1));
}

DIR	*opendir_wrapper(t_data *data, const char *path)
{
	if (!path)
		return (NULL);
	if (!can_be_oppenedir(path, data->exec_path))
		return (NULL);
	return (opendir(path));
}
