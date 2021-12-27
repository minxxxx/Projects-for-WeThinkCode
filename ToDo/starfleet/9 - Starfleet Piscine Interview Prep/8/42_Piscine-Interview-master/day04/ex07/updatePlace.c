/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:39:50 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 21:39:51 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	updatePlace(unsigned int parkingRow, int pos, int value)
{
	if (value != 0)
		parkingRow |= (1 << pos);
	else
		parkingRow &= ~(1 << pos);
	return (parkingRow);
}
