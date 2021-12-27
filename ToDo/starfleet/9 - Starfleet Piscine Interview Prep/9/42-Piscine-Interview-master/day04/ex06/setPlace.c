/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 01:57:35 by amontano          #+#    #+#             */
/*   Updated: 2019/01/15 01:57:37 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int setPlace(unsigned int parkingRow, int pos)
{
    return (parkingRow | (0x1 << pos));
}
