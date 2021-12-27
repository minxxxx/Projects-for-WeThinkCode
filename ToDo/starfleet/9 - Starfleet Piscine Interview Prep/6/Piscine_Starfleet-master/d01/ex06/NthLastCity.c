/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:55:37 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/09 21:23:24 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void recurse(struct s_city *city, int n, int *r, char **line)
{
	if (!city)
		return ;
	recurse(city->next, n, r, line);
	if ((*r)++ == n)
		*line = city->name;
}

char *NthLastCity(struct s_city *city, int n)
{
	if (!city)
		return 0;
	int r = 0;
	char *line = 0;
	recurse(city, n, &r, &line);
	return line;
}
