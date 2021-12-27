/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:45:33 by amontano          #+#    #+#             */
/*   Updated: 2019/01/14 21:45:35 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *getSum(char *a, char *b)
{
    int     i      = 5;
    char    c      = 0;
    char    sum[6];

    while (i >= 0)
    {
        a[i] &= 0x1;
        b[i] &= 0x1;
        sum[i] = a[i] ^ b[i] ^ c ? '1' : '0';
        c = (a[i] & b[i]) | (b[i] & c);
        b[i] = sum[i];
        i--;
    }
    return (b);
}

int toInt(char *bits)
{
    int ret = 0;

    for (int i = 5; i >= 0; i--)
    {
        if (bits[i] == '1')
            ret += 1 << (5 - i);
    }
    return (ret);
}