/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_to_vertex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:41:40 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:41:40 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <math.h>

#define EPSILON 0.1f

void	sp_calc_uv_spherical(t_mesh const *me, t_vertex_basic *vertex)
{
	t_vec3		tmp;

	tmp = *(t_vec3*)&vertex->pos;
	if (ABS(tmp.x) < EPSILON && ABS(tmp.z) < EPSILON)
	{
		tmp.x = EPSILON;
		tmp.z = EPSILON;
	}
	vertex->tex.u = fabs(atan(tmp.x / tmp.z)) * me->tex_scale[0];
	vertex->tex.v = acos(tmp.y / sqrt(tmp.x * tmp.x
									+ tmp.y * tmp.y
									+ tmp.z * tmp.z))
		* me->tex_scale[1];
	return ;
}

void	sp_calc_uv_planaroxy(t_mesh const *me, t_vertex_basic *vertex)
{
	vertex->tex.u = vertex->pos.x * me->tex_scale[0];
	vertex->tex.v = vertex->pos.y * me->tex_scale[1];
	return ;
}

#define VALID(v) (v < 10.f && v > -10.f && !isnan(v))

void	sp_calc_uv_box(t_mesh const *me, t_vertex_basic *vertex)
{
	float const		nx = ABS(vertex->nor.x);
	float const		ny = ABS(vertex->nor.y);
	float const		nz = ABS(vertex->nor.z);

	if (nz > nx && nz > ny)
	{
		vertex->tex.u = vertex->pos.x * me->tex_scale[0];
		vertex->tex.v = vertex->pos.y * me->tex_scale[1];
	}
	else if (ny > nx)
	{
		vertex->tex.u = vertex->pos.x * me->tex_scale[0];
		vertex->tex.v = -vertex->pos.z * me->tex_scale[1];
	}
	else
	{
		vertex->tex.u = -vertex->pos.z * me->tex_scale[0];
		vertex->tex.v = vertex->pos.y * me->tex_scale[1];
	}
	return ;
}
