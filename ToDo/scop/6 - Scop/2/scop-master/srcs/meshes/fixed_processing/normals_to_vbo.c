/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals_calculations_vbo.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 16:26:31 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:40:45 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <string.h>
#include <math.h>

static void	bzero_normals(t_vertex_basic *vert)
{
	bzero(&vert->nor, sizeof(vert->nor));
	return ;
}

static void	sum_normals(t_vertex_basic *verts, t_face_basic const *f)
{
	int		i;
	int		j;
	float	angle;

	i = 0;
	j = 2;
	while (i < 3)
	{
		angle = acos(v3_dot_normed(v3_inv(f->vec[i]), f->vec[j % 3]));
		*(t_vec3*)&verts[f->indices[i]].nor =
			v3_add(*(t_vec3*)&verts[f->indices[i]].nor
					, v3_mul_scalar(f->nor, angle));
		i++;
		j++;
	}
	return ;
}

static void	normalize_normals(t_vertex_basic *vert)
{
	*(t_vec3*)&vert->nor = v3_normalize(*(t_vec3*)&vert->nor);
	return ;
}

void		sp_normals_to_vbo(t_vao_basic *vao)
{
	ftv_foreach0(&vao->vbo.vertices, &bzero_normals);
	ftv_foreach(&vao->ebo.faces, &sum_normals, vao->vbo.vertices.data);
	ftv_foreach0(&vao->vbo.vertices, &normalize_normals);
	vao->vbo.nnor = 3;
	return ;
}
