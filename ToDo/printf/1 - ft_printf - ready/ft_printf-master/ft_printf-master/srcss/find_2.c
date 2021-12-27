/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 23:15:52 by jcamhi            #+#    #+#             */
/*   Updated: 2016/02/01 10:01:10 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_increase(int *i, int *j)
{
	*i = *i + 1;
	*j = *j + 1;
}

int		after_width(const char *str, int i)
{
	if (str[i] == '*')
		i++;
	else
		while (ft_isdigit((int)str[i]))
			i++;
	return (i);
}
