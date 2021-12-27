/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 00:34:03 by amontano          #+#    #+#             */
/*   Updated: 2019/01/08 00:34:06 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static size_t hash(char *str, int len)
{
    int i = 0;
    size_t  hash = 0x666;
    while (i < len && str[i])
    {
        hash += ((hash << 3) + str[i]) << 3;
        hash -= (hash >> 2) - str[i];
        i++;
    }
    return (hash);
}

int howManyJesus(char *bible, char *jesus)
{
    int         thump   = 0;
    int         len     = strlen(jesus);
    size_t      hsh     = hash(jesus, len);
    
    while (*bible)
    {
        if (hash(bible, len) == hsh)
            thump++;
        bible++;
    }
    return (thump);
}
