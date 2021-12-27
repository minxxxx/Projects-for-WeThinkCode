/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:05:15 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 22:05:15 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			leftmostCar(unsigned int parkingRow)
{
	int		ret;

	ret = -1;
	if (parkingRow != 0)
	{
		for (ret = 0; parkingRow != 1; ret += 1)
			parkingRow >>= 1;
	}
	return (ret);
}
