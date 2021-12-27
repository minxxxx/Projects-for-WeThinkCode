/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 02:08:48 by amontano          #+#    #+#             */
/*   Updated: 2019/01/15 02:08:49 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int isFilled(unsigned int parkingRow)
{
    return  (parkingRow && !(parkingRow & (-(~(parkingRow)))));
}

//doing '~' followed by taking the 2's complement ('-') effectively adds 1;