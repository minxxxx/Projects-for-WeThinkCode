/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:28:01 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/26 03:44:56 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <limits.h>
#include <strings.h>
#define RANGE UCHAR_MAX

void countSort(unsigned char *arr, int n)
{
    int count[RANGE + 1], i, i2;

    bzero(&count, sizeof(count));
	i = i2 = -1;
    while (++i < n)
        count[arr[i]]++;
	for (i = 0; i < RANGE + 1; i++)
		while (--count[i] > -1)
			arr[++i2] = i;
}