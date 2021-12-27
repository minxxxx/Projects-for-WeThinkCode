/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:20:02 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/24 16:20:03 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_power(int nb, int power)
{
	long long int	r;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	r = nb;
	while (power > 1)
	{
		r = r * nb;
		power--;
	}
	return (r);
}
