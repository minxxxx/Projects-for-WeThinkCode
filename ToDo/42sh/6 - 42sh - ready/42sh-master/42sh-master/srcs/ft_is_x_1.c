/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_x_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			is_empty_border(char *str, size_t beg, size_t end)
{
	size_t i;

	i = beg;
	while (str[i] != '\0' && i <= end)
	{
		if (!ft_isspace2(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			is_empty(char *str, size_t *i)
{
	size_t tmp;

	tmp = *i;
	while (str[tmp] != '\0')
	{
		if (!ft_isspace2(str[tmp]))
			return (0);
		tmp++;
	}
	return (1);
}

int			is_special(char *str, int quote)
{
	if (quote == 1)
		str++;
	if (ft_strnstr(str, ">>", 2) || ft_strnstr(str, "<<", 2)
			|| ft_strnstr(str, "&&", 2) || ft_strnstr(str, "2>", 2)
			|| ft_strnstr(str, "2>>", 3) || str[0] == '|'
			|| str[0] == '>' || str[0] == '<' || str[0] == ';')
		return (1);
	return (0);
}

int			ft_isspace2(char car)
{
	if (car == ' ' || car == '\t' || car == '\v' || car == '\f' || car == '\r')
		return (1);
	return (0);
}
