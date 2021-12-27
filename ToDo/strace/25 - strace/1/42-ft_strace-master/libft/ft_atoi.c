/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:45:10 by jtranchi          #+#    #+#             */
/*   Updated: 2015/11/29 13:13:01 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*clean(char *str)
{
	while (*str == '\n' || *str == '\v' ||
			*str == '\t' || *str == '\r' ||
			*str == '\f' || *str == ' ')
		str++;
	return (str);
}

int			ft_atoi(char *str)
{
	int result;

	result = 0;
	str = clean(str);
	if (*str == '-' && ft_isdigit(*(str + 1)))
	{
		result = 0 - (*(str + 1) - '0');
		while (ft_isdigit(*(str + 2)))
			result = result * 10 - (*(str++ + 2) - '0');
	}
	else if (*str == '+' && ft_isdigit(*(str + 1)))
	{
		result = *(str + 1) - '0';
		while (ft_isdigit(*(str + 2)))
			result = result * 10 + (*(str++ + 2) - '0');
	}
	else if (ft_isdigit(*str))
	{
		result = *str - '0';
		while (ft_isdigit(*(str + 1)))
			result = result * 10 + *(str++ + 1) - '0';
	}
	else
		return (0);
	return (result);
}
