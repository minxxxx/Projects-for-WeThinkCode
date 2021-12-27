/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 23:14:17 by amontano          #+#    #+#             */
/*   Updated: 2019/01/14 23:14:18 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *bit_negate(char *bits)
{
    while (++bits)
        *bits = *bits ^ 0x1;
    return (&bits[1]);
}

char *getAnd(char *a, char *b)
{
    a = (a[0] == '~') ? bit_negate(a) : a;
    b = (b[0] == '~') ? bit_negate(b) : b;
    for (int i = 0; a[i] && b[i]; i++)
        a[i] = ((a[i] & 0x1) & (b[i] & 0x1)) + 48;
    return (a);
}

char *getOr(char *a, char *b)
{
    a = (a[0] == '~') ? bit_negate(a) : a;
    b = (b[0] == '~') ? bit_negate(b) : b;
    for (int i = 0; a[i] && b[i]; i++)
        a[i] = ((a[i] & 0x1) | (b[i] & 0x1)) + 48;
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
