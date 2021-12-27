/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 00:57:04 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/23 12:38:18 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <strings.h>

int	searchPrice(struct s_art **arts, char *name)
{
	struct s_art	**tmp;
	int				i;
	
	i = -1;
	tmp = arts;
	while (tmp[++i])
	{
		if (strcmp(tmp[i]->name, name) == 0)
			return (tmp[i]->price);
	}
	return (-1);
}