/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quesglob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:02:03 by ftait             #+#    #+#             */
/*   Updated: 2017/11/24 02:54:07 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

int		quesglob(const char *name, char *str)
{
	int i;

	i = 0;
	if (ft_strlen(name) == ft_strlen(str))
	{
		while (name[i] != '\0')
		{
			if (str[i] != '?')
				if (str[i] != name[i])
					return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
