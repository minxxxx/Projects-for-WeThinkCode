/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 00:06:31 by amontano          #+#    #+#             */
/*   Updated: 2019/01/18 00:06:32 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int cmp(const void *a, const void * b)
{
    t_art **aye = (t_art **)a;
    t_art **bee = (t_art **)b;
    return (strcmp((*aye)->name, (*bee)->name));
}

void heapSort(struct s_art **masterpiece, int n)
{
    heapsort(masterpiece, n, sizeof(t_art **), cmp);
}

