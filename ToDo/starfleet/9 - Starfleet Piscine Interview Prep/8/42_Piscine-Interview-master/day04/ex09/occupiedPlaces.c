/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:47:28 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 21:47:29 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			occupiedPlaces(unsigned int parkingRow)
{
	int		count;

	for (count = 0; parkingRow != 0; count += 1)
		parkingRow = parkingRow & (parkingRow - 1);
	return (count);
}
