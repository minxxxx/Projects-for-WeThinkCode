/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:24:53 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/17 22:49:00 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
	if (firstDollarsBet <= 0 || nbGame-- < 0)
		return 0.0;
	if (firstDollarsBet >= dollarsWanted)
		return 1.0;
	return (18 * probabilityWin(firstDollarsBet * 2, dollarsWanted, nbGame)
			+ probabilityWin(firstDollarsBet / 2, dollarsWanted, nbGame)) / 37;
}
