/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:00:36 by amontano          #+#    #+#             */
/*   Updated: 2019/01/10 21:00:38 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void insert(t_player *in, t_player **arr)
{
    int i = 0;
    t_player        *tmp;

    while (arr[i] && in->score < arr[i]->score)
        i++;
    tmp = arr[i];
    arr[i] = in;
    while (arr[i + 1])
    {
        arr[i] = tmp;
        tmp = arr[i + 1];
        i++;
    }
}

void insertionSort(struct s_player **players)
{
    t_player    **sorted_array;

    //init sorting array
    int max = 0;
    while (players[max])
        max++;
    int i = 0;
    sorted_array = (t_player **)malloc(sizeof(t_player *) * max);
    for (int k = 0; k < max; k++)
        sorted_array[k] = NULL;
    while (i < max)
    {
        insert(players[i], sorted_array);
        i++;
    }
    for (int i = 0; i < max; i++)
        players[i] = sorted_array[i];
}

