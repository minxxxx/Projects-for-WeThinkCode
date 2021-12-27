/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 09:59:10 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/31 09:59:10 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <string.h>

int		searchPrice(struct s_art **arts, char *name)
{
	if (arts != NULL && name != NULL)
	{
		for (int i = 0; arts[i] != NULL; i += 1)
		{
			if (!strcmp(arts[i]->name, name))
				return (arts[i]->price);
		}
	}
	return (-1);
}
