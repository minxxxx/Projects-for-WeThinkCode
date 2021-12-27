/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 05:39:26 by amontano          #+#    #+#             */
/*   Updated: 2019/01/16 05:39:28 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

/*
*
**      T # of tables
**      M # of mins per table
**      N # of groups
**      C is my collision counter that im proud of
*/

static void get_values(int *tm,t_people **ppl, int *n)
{
    if (*ppl)
    {
        get_values(tm, ppl + 1, n);
        *tm += (*ppl)->time;
        *n += 1;
    }
}

static void get_collisions(int *c, t_people **ppl, int n, int lim)
{
    for (int i = 0; i < n; i++){
        for (int k = 0; k < n; k++) {
                *c += ((ppl[i]->time + ppl[k]->time) > lim) ? 1 : -1;
        }
    }
}

int isPossible(struct s_people **people, int nbTable, int totalTime)
{
    int total_table_minutes = 0;
    int num_guests = 0;
    int collisions = 0;

    get_values(&total_table_minutes, people, &num_guests);
    get_collisions(&collisions, people, num_guests, totalTime);
    printf("[collisions: %d]\t [N-T: %d]\t [totTime: %d]\t [tableHours: %d]\n", \
        collisions, num_guests - nbTable, total_table_minutes, totalTime * nbTable);
    if ( (num_guests > nbTable) && (collisions > num_guests - nbTable) )
        return (0);
    return (total_table_minutes <= (totalTime * nbTable));
}

