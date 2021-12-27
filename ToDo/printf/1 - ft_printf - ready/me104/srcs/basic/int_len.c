/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:22:23 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 20:23:29 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		int_len(intmax_t nbr)
{
	uintmax_t	tmp;

	if (nbr < 0)
		tmp = (uintmax_t)-nbr;
	else
		tmp = (uintmax_t)nbr;
	if (tmp >= 1000000000000000000)
		return (19);
	else if (tmp >= 100000000000000000)
		return (18);
	else if (tmp >= 10000000000000000)
		return (17);
	else if (tmp >= 1000000000000000)
		return (16);
	else if (tmp >= 100000000000000)
		return (15);
	else if (tmp >= 10000000000000)
		return (14);
	else if (tmp >= 1000000000000)
		return (13);
	else if (tmp >= 100000000000)
		return (12);
	else if (tmp >= 10000000000)
		return (11);
	return (int_len2(tmp));
}

int		int_len2(uintmax_t nbr)
{
	if (nbr >= 1000000000)
		return (10);
	else if (nbr >= 100000000)
		return (9);
	else if (nbr >= 10000000)
		return (8);
	else if (nbr >= 1000000)
		return (7);
	else if (nbr >= 100000)
		return (6);
	else if (nbr >= 10000)
		return (5);
	else if (nbr >= 1000)
		return (4);
	else if (nbr >= 100)
		return (3);
	else if (nbr >= 10)
		return (2);
	else
		return (1);
}
