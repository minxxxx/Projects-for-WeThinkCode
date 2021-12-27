/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   land_mesh_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 08:40:36 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/19 17:11:19 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdlib.h>
#include <assert.h>
#include <math.h>

static void		push_vertex(t_ftvector vec[1]
							, int const mapcoords[2], int mapwidth)
{
	t_vertex_basic		vert[1];

	*(t_vec2*)&vert->tex = ATOV2(
		(float)mapcoords[0] / (float)mapwidth
		, (float)mapcoords[1] / (float)mapwidth
		);
	ftv_push_back_unsafe(vec, vert);
	return ;
}

static void		push_faces(t_ftvector vec[1], int vbowidth)
{
	int				row;
	int				col;
	t_face_basic	face[1];

	row = 1;
	while (row < vbowidth)
	{
		col = 1;
		while (col < vbowidth)
		{
			face->indices[0] = (col - 0) + (row - 0) * vbowidth;
			face->indices[1] = (col - 1) + (row - 1) * vbowidth;
			face->indices[2] = (col - 1) + (row - 0) * vbowidth;
			ftv_push_back_unsafe(vec, face);
			face->indices[2] = face->indices[1];
			face->indices[1] = (col - 0) + (row - 1) * vbowidth;
			ftv_push_back_unsafe(vec, face);
			col++;
		}
		row++;
	}
	return ;
}

void			sp_land_fill_mesh(t_env const *e, t_vao_basic *vao)
{
	int const		vbowidth = (int)pow(2.f, (LAND_NDEPTHLOOPSCPI + 1));
	int const		mapwidth = (int)pow(2.f, (LAND_NDEPTHLOOPSI + 1));
	int const		mappoints = mapwidth * mapwidth;
	int const		stride = mapwidth / vbowidth;
	int				i;
	/* float			*ymap; */

	assert(vbowidth > 0);
	if (ftv_reserve(&vao->vbo.vertices, vbowidth * vbowidth))
		sp_enomem();
	if (ftv_reserve(&vao->ebo.faces, vbowidth * vbowidth * 2))
		sp_enomem();
	/* ymap = malloc(sizeof(float) * mappoints); */
	/* if (ymap == NULL) */
	/* 	sp_enomem(); */
	T;
	/* glBindTexture(GL_TEXTURE_2D, e->land_tex1.handle); */
	/* glGetTexImage(GL_TEXTURE_2D, 0, GL_RED, GL_FLOAT, ymap); */
	i = 0;
	qprintf("vbowidth: %d\n", vbowidth);
	qprintf("mapwidth: %d\n", mapwidth);
	qprintf("mappoints: %d\n", mappoints);
	qprintf("stride: %d\n", stride);
	while (i < vbowidth * vbowidth)
	{
		/* if (i < 10) */
		/* 	qprintf("%.8f\n", ymap[i]); */
		push_vertex(&vao->vbo.vertices
			, (int[]){i % vbowidth * stride, i / vbowidth * stride}, mapwidth);
		i++;
	}
	push_faces(&vao->ebo.faces, vbowidth);
	/* ftv_printn(&vao->vbo.vertices, "FFFFFFFff", 10); */
	/* ftv_printn(&vao->ebo.faces, "uuu", 5); */
	vao->vbo.ntex = 2;
	/* vao->vbo.npos = 3; */
	/* vao->vbo.nnor = 3; */
	/* free(ymap); */
	return ;
}
