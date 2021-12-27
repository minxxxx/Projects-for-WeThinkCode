/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:49:11 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 21:49:12 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			carPosition(unsigned int parkingRow)
{
	int		ret;

	ret = -1;
	if (parkingRow != 0 && !(parkingRow & (parkingRow - 1)))
	{
		for (ret = 0; parkingRow > 1; ret += 1)
			parkingRow >>= 1;
	}
	return (ret);
}
