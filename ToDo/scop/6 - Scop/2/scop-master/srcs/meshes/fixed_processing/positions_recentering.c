/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_recentering.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 16:25:30 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/03 16:25:57 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <string.h>

static void		sum_pos(t_vec3 *sum, t_vertex_basic const *v)
{
	*sum = v3_add(*sum, *(t_vec3 const*)&v->pos);
	return ;
}

static void		recenter_pos(t_vec3 const *sum, t_vertex_basic *v)
{
	*(t_vec3*)&v->pos = v3_sub(*(t_vec3*)&v->pos, *sum);
	return ;
}

void			sp_recenter_positions(t_vbo_basic *vbo)
{
	t_vec3		v[1];

	bzero(v, sizeof(*v));
	ftv_foreach(&vbo->vertices, &sum_pos, v);
	v[0].x /= (float)vbo->vertices.size;
	v[0].y /= (float)vbo->vertices.size;
	v[0].z /= (float)vbo->vertices.size;
	qprintf("    Recentering positons: ");
	v3_print(*v);
	ftv_foreach(&vbo->vertices, &recenter_pos, v);
	return ;
}
