/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 18:18:57 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/10 18:19:33 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		x;
	float	new_x;
	float	old_x;

	if (nb == 1)
		return (1);
	else if (nb < 4)
		return (0);
	if (nb < 100)
		x = 7;
	else
		x = 50;
	old_x = x;
	while (x * x != nb)
	{
		new_x = (x + nb / x) / 2;
		if (new_x == x || old_x == new_x)
			return (0);
		else
		{
			old_x = x;
			x = new_x;
		}
	}
	return (x);
}
