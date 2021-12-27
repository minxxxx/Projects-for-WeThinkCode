/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 03:25:03 by amontano          #+#    #+#             */
/*   Updated: 2019/01/15 03:25:05 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
   int count = 0;
   while (parkingRow)
   {
       parkingRow &= (parkingRow - 1);
       count++;
   }
   return (count);
}
//this is Kernighan's algorithm