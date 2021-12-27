/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starglob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:01:57 by ftait             #+#    #+#             */
/*   Updated: 2017/11/24 02:54:33 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
 ** please dont use this function anywhere else.. might have undefined behaviour
*/

static int	ft_strendcmp(const char *name, char *str)
{
	int	i;

	i = 0;
	while (name[i] != str[0])
	{
		if (name[i] == '\0')
			return (0);
		i++;
	}
	if (ft_strcmp(&name[i], str) == 0)
		return (1);
	return (0);
}

int			starglob(const char *name, char *str)
{
	if (ft_strlen(str) == 1)
	{
		if (str[0] == '*')
			return (1);
		return (0);
	}
	else if (str[0] != '*')
	{
		if (ft_strncmp(name, str, ft_strlen(str) - 1) == 0)
			return (1);
		return (0);
	}
	else if (str[0] == '*')
		if (ft_strendcmp(name, &(str[1])) != 0)
			return (1);
	return (0);
}
