/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 20:56:56 by amontano          #+#    #+#             */
/*   Updated: 2019/01/06 20:56:58 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int searchPrice(struct s_art **arts, char *name)
{
    if ((*arts)->name && name)
        while (*arts != NULL)
        {
            if (strcmp(name, (*arts)->name) == 0)
                return ( (*arts)->price );
            arts++;
        }
    return (-1);
}
