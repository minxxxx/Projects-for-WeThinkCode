/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearPlace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:32:55 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 21:32:56 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	clearPlace(unsigned int parkingRow, int pos)
{
	parkingRow &= parkingRow ^ (1 << pos);
	return (parkingRow);
}
