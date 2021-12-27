/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atobin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:55:17 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/27 16:28:28 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atobin(int c)
{
	char	*ret;
	int		index;
	int		res;

	index = 8;
	res = 0;
	if (c)
	{
		if (!(ret = (char *)malloc(sizeof(char) * 8)))
			return (ERROR);
		while (--index >= 0)
		{
			ret[index] = c % 2 + '0';
			c = c / 2;
		}
		res = ft_atoi(ret);
		free(ret);
		return (res);
	}
	return (ERROR);
}
