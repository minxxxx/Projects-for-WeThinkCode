/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals_calculations_ebo.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 16:26:04 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:41:11 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <assert.h>
#include <math.h>

static void		normal_to_face(t_vertex_basic const *vertices
								, t_face_basic face[1])
{
	t_vec3 const	p0pos = *((t_vec3*)&vertices[face->indices[0]].pos);
	t_vec3 const	p1pos = *((t_vec3*)&vertices[face->indices[1]].pos);
	t_vec3 const	p2pos = *((t_vec3*)&vertices[face->indices[2]].pos);

	face->vec[0] = v3_normalize(v3_sub(p0pos, p1pos));
	face->vec[1] = v3_normalize(v3_sub(p1pos, p2pos));
	face->vec[2] = v3_normalize(v3_sub(p2pos, p0pos));
	face->nor = v3_cross(v3_inv(face->vec[0]), face->vec[2]);
	assert(!isnan(face->nor.x));
	assert(!isnan(face->nor.y));
	assert(!isnan(face->nor.z));
	return ;
}

void			sp_normals_to_ebo(t_vao_basic *vao)
{
	ftv_foreach(&vao->ebo.faces, &normal_to_face, vao->vbo.vertices.data);
	return ;
}
