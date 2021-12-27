/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 03:13:41 by amontano          #+#    #+#             */
/*   Updated: 2019/01/09 03:13:42 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void printReverse(struct s_node *lst)
{
    if (lst->next)
        printReverse(lst->next);
    printf(" %s", lst->word);
}
