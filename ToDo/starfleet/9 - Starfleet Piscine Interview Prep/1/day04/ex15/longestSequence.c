/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:09:11 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 22:09:12 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		longestSequence(unsigned int parkingRow)
{
	int	seq;

	for (seq = 0; parkingRow != 0; seq += 1)
		parkingRow &= (parkingRow << 1);
	return (seq);
}
