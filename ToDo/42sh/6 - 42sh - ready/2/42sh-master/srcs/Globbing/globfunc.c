/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:06:35 by ftait             #+#    #+#             */
/*   Updated: 2017/11/24 02:53:08 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

int		globfunction(const char *name, char *str)
{
	if (isglob(str) == 0)
		return (0);
	if (isglob(str) == 1)
		if (starglob(name, str) == 1)
			return (1);
	if (isglob(str) == 2)
		if (quesglob(name, str) == 1)
			return (1);
	if (isglob(str) == 3)
		if (bracglob(name, str) == 1)
			return (1);
	if (isglob(str) == 4)
		if (curlyglob(name, str) == 1)
			return (1);
	return (0);
}
