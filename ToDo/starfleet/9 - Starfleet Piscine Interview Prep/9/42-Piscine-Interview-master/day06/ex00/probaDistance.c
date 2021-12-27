/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:51:23 by amontano          #+#    #+#             */
/*   Updated: 2019/01/16 20:51:24 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

double probaDistance(int dist, int *locations, int n)
{
    int good = 0;
    int too_far  = 0;
    int dif = 0;

    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            dif = locations[i] - locations[k];
            dif = (dif < 0) ? -dif : dif;
            (dif > dist) ? too_far++ : good++;
        }
    }
    return ( 1.0 - ((double)good/ (double)(good + too_far)) );
}
