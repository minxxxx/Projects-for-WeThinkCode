/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 04:19:03 by amontano          #+#    #+#             */
/*   Updated: 2019/01/16 04:19:06 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

static int should_swap(char *str, int start, int cur)
{
    for (int i = start; i < cur; i++)
        if (str[i] == str[cur])
            return (0);
    return (1);
}

static void swap(char *x, char *y) 
{ 
    char temp = *x; 

    *x = *y; 
    *y = temp; 
} 

static void permute(char *str, int l, int r)
{
    int i, flag;
    
    if (l == r)
        printf("%s\n", str);
    else {
        for (i = l; i <= r; i++) {
            if ((flag = should_swap(str, l, i))) {
                swap((str + l), (str + i));
                permute(str, l + 1, r);
                swap((str + l), (str + i));
            }
        }
    }
}

void	printPermutations(char *str)
{
    permute(str, 0, strlen(str) - 1);
}