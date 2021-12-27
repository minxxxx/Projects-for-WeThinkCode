/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:56:14 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 21:56:15 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int			carPosition(unsigned int parkingRow)
{
	int		ret;

	ret = -1;
	if (parkingRow != 0 && !(parkingRow & (parkingRow - 1)))
	{
		ret = (int)log2(parkingRow);
	}
	return (ret);
}
