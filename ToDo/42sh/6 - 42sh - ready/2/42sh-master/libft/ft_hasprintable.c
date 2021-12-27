/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasprintable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:07:51 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:07:58 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hasprintable(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (ft_isspace(*str) == 1)
			str++;
		else
		{
			i++;
			str++;
		}
	}
	return (i);
}
