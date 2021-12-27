/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:43:17 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 21:43:17 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		isFilled(unsigned int parkingRow)
{
	return (~((parkingRow + 1) & parkingRow));
}
