/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 09:36:53 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/07 09:42:29 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		searchPrice(struct s_art **arts, char *name)
{
	for (int i = 0; arts[i]; i++)
		if (!strcmp(arts[i]->name, name))
			return arts[i]->price;
	return -1;
}
