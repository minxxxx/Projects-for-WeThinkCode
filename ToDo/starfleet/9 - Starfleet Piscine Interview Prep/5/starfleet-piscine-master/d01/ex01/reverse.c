/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:48:12 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/24 14:59:04 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <string.h>

void printReverse(struct s_node *lst)
{
	if (lst->next)
	{
		printReverse(lst->next);
		write(1, " ", 1);
	}
	write(1, lst->word, strlen(lst->word));
}