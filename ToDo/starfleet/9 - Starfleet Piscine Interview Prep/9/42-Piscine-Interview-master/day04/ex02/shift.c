/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 23:44:15 by amontano          #+#    #+#             */
/*   Updated: 2019/01/14 23:44:17 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *rightShift(char *bin, int k)
{
    char tmp[6];

    for (int i = 0; i < 6; i++)
        tmp[i] = bin[i];
    for (int i = 0; i < 6; i++)
    {
        if (i + k < 6)
            bin[i + k] = tmp[i];
        if (i < k)
            bin[i] = '1';
    }
    return (bin);
}

char *leftShift(char *bin, int k)
{
    char tmp[6];

    for (int i = 0; i < 6; i++)
        tmp[i] = bin[i];
    for (int i = 6; i > 0; i--)
    {
        if (i - k > 0)
            bin[i - k] = tmp[i];
        if (6 - i < k)
            bin[i] = '0';
    }
    return (bin);
}

int toInt(char *bits)
{
    int ret = 0;

    if ((bits[0] & 0x1) == 0)
    {
        for (int i = 5; i > 0; i--)
        {
            if (bits[i] == '1')
                ret += 1 << (5 - i);
        }
        return (ret);
    }
    else
    {
        ret = -1;
        for (int i = 5; i > 0; i--)
        {
            if (bits[i] == '0')
                ret -= 1 << (5 - i);
        }
        return (ret);
    }
}