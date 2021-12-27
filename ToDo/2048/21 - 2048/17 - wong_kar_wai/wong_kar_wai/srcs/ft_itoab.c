/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:49:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/28 17:18:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int				ft_itoab(int n, char *buff)
{
	int				len;
	int				tmp;

	len = (n < 0) ? 2 : 1;
	if (n < 0)
		*buff = '-';
	else if (n == 0)
		*buff = '0';
	tmp = n;
	while ((tmp /= 10) != 0)
		len++;
	buff += len;
	*(buff--) = '\0';
	if (n <= 0)
	{
		*(buff--) = '0' + (-n % 10);
		n /= -10;
	}
	while (n != 0)
	{
		*(buff--) = '0' + (n % 10);
		n /= 10;
	}
	return (len);
}
