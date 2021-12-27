/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 22:37:51 by amontano          #+#    #+#             */
/*   Updated: 2019/01/06 22:37:53 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		cmp(const void *p, const void *q)
{
	t_art *a;
	t_art *b;
	int			res;

	a = (t_art *)p;
	b = (t_art *)q;
	res = strcmp( (char *)a->name, (char *)b->name);
	return (res);
}

void    sortArts(struct s_art **arts)
{
	size_t nel = 0;
	while (arts[nel])
		nel++;
	qsort(arts, nel, sizeof(t_art *), &cmp);
}