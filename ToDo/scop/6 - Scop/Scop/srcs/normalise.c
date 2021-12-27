/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 10:16:50 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/27 10:22:27 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_vertex	normalise_point(t_vertex *p1, t_vertex *p2, t_vertex *p3)
{
	t_vertex	u;
	t_vertex	v;
	t_vertex	normal;
	float		temp;

	u.x = p2->x - p1->x;
	u.y = p2->y - p1->y;
	u.z = p2->z - p1->z;
	v.x = p3->x - p1->x;
	v.y = p3->y - p1->y;
	v.z = p3->z - p1->z;
	normal.x = (u.y * v.z) - (u.z * v.y);
	normal.y = (u.z * v.x) - (u.x * v.z);
	normal.z = (u.x * v.y) - (u.y * v.x);
	temp = sqrt(normal.x * normal.x +
		normal.y * normal.y + normal.z * normal.z);
	normal.x = (normal.x / temp) / 10;
	normal.y = (normal.y / temp) / 10;
	normal.z = (normal.z / temp) / 10;
	glNormal3f(normal.x, normal.y, normal.z);
	return (normal);
}
