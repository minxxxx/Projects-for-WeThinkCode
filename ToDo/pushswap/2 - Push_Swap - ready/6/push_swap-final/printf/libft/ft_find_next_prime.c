/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:09:00 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/27 18:09:13 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_next_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 3)
		return (2);
	if (nb > 2)
	{
		while ((nb % i) != 0 && i < nb)
			i++;
		if (nb == i)
			return (i);
		else
			return (ft_find_next_prime(nb + 1));
	}
	return (1);
}
