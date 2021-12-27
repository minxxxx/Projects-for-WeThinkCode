/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 12:03:22 by ftait             #+#    #+#             */
/*   Updated: 2017/11/24 02:52:07 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static int		braclose(const char *str, char c, int i, int b)
{
	while (b && *(++str) && (i++))
	{
		if (*str == c || *str == c + c % 2 + 1)
		{
			if (*str == c)
				++b;
			else
				--b;
		}
	}
	return (i);
}

int				brackets(const char *str, char c)
{
	if (*str == c)
		return (1);
	else if (!*str || *str == ')' || *str == '}' || *str == ']')
		return (0);
	else if (*str == '(' || *str == '{' || *str == '[')
		return (brackets(str + 1, *str + *str % 2 + 1) *
				brackets(str + braclose(str, *str, 1, 1), c));
	else
		return (brackets(str + 1, c));
}
