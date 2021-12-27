/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:01:27 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/17 11:39:23 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_char(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen_wchar(wchar_t *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		i += ft_strlen_wchar_c(*s);
		s = s + 1;
	}
	return (i);
}

int		ft_strlen_wchar_c(wchar_t s)
{
	int i;

	i = 1;
	if (s >= 0x80 && s < 0x800 && MB_CUR_MAX > 1)
		i = 2;
	else if (s >= 0x800 && s < 0x10000 && MB_CUR_MAX > 1)
		i = 3;
	else if (s >= 0x10000 && s < 0x200000 && MB_CUR_MAX > 1)
		i = 4;
	return (i);
}

int		abs_value(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int		is_signed(char a)
{
	if (a == 'd' || a == 'i')
		return (1);
	return (0);
}
