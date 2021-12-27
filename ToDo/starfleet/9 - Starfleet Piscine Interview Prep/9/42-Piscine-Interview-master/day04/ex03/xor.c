/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 01:35:23 by amontano          #+#    #+#             */
/*   Updated: 2019/01/15 01:35:24 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

char *getXor(char *a, char *b)
{
    for(int i = 0; i < 6; i++)
        a[i] = ((a[i] & 0x1) ^ (b[i] & 0x1)) + 48;
    return (a);
}

int toInt(char *bits)
{
    int ret = 0;
    int len = strlen(bits) - 1;
    
    for (int i = len; i >= 0; i--)
    {
        if (bits[i] == '1')
            ret += 1 << (len - i);
    }
    return (ret);
}