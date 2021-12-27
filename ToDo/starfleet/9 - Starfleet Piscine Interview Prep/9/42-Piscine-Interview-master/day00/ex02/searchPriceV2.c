/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 23:51:49 by amontano          #+#    #+#             */
/*   Updated: 2019/01/06 23:51:50 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int searchPrice(struct s_art **arts, int n, char *name)
{
    int left;
    int right;
    int mid;
    int cmp;

    left = 0;
    right = n - 1;
    while (left <= right)
    {
        mid = floor((left + right) / 2);
        cmp = strcmp(arts[mid]->name, name);
        if (cmp == 0)
            return (arts[mid]->price);
        else if (cmp < 0)
            left = mid + 1;
        else if (cmp > 0)
            right = mid - 1;
    }
    return (-1);
}
