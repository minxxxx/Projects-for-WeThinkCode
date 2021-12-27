/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 04:05:18 by amontano          #+#    #+#             */
/*   Updated: 2019/01/16 04:05:20 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void swap(char *x, char *y) 
{ 
    char temp = *x; 

    *x = *y; 
    *y = temp; 
} 

static void permute(char *str, int l, int r)
{
    int i;
    
    if (l == r)
        printf("%s\n", str);
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((str + l), (str + i));
            permute(str, l + 1, r);
            swap((str + l), (str + i));
        }
    }
}

void	printPermutations(char *str)
{
    permute(str, 0, strlen(str) - 1);
}

