/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:25:53 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 18:36:00 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

size_t		ft_strlen(char *str)
{
	size_t		result;
	uint32_t	*i;

	result = 0;
	i = (uint32_t *)str;
	if (!str)
		return (0);
	while (42)
	{
		if (!(*i & 0x000000ff))
			return (result);
		if (!(*i & 0x0000ff00))
			return (result + 1);
		if (!(*i & 0x00ff0000))
			return (result + 2);
		if (!(*i & 0xff000000))
			return (result + 3);
		result += 4;
		++i;
	}
}

int			ft_wstrlen(wint_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (MB_CUR_MAX < 2 ? -1 : 2);
	else if (c <= 0xFFFF)
		return (MB_CUR_MAX < 3 ? -1 : 3);
	else if (c <= 0x10FFFF)
		return (MB_CUR_MAX < 4 ? -1 : 4);
	else
		return (-1);
}
