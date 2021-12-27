/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objmodel_retreive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 17:06:35 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:35:48 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "scop.h"
#include "objmodel/objmodel_parsing.h"
#include "ft_containers.h"

static void	push_index(size_t const *ptrpad, void *beginptr, int i)
{
	*(t_ui*)(beginptr + *ptrpad) = (t_ui)i;
	return ;
}

static void	build_faces(t_ftvector *faces, size_t const *pad
						, t_tmpface const *face)
{
	t_face_basic	tmp[1];

	bzero(tmp, sizeof(tmp));
	tmp->indices[0] = *(t_ui*)((void*)face->ptr[0] + *pad);
	tmp->indices[1] = *(t_ui*)((void*)face->ptr[1] + *pad);
	tmp->indices[2] = *(t_ui*)((void*)face->ptr[2] + *pad);
	ftv_push_back_unsafe(faces, tmp);
	return ;
}

static void	retreive_faces(t_objmodel const *const m, t_ftvector *faces)
{
	size_t	padtoindex;

	if (ftv_reserve(faces, m->faces.size))
		sp_enomem();
	padtoindex = m->vertices.chunk_size - sizeof(t_ui);
	ftv_foreach2(&m->faces, &build_faces, faces, &padtoindex);
	return ;
}

static void	extract_vertices(t_vertex_basic *dst, void const *src
								, t_ui const nfloats[1])
{
	float	*floats;

	floats = (float*)(src + sizeof(t_ftset_node));
	memcpy(&dst->pos, floats + 0, sizeof(float) * 3);
	if (*nfloats == 5 || *nfloats == 8)
		memcpy(&dst->tex, floats + 3, sizeof(float) * 2);
	if (*nfloats == 6)
		memcpy(&dst->nor, floats + 3, sizeof(float) * 3);
	else if (*nfloats == 8)
		memcpy(&dst->nor, floats + 5, sizeof(float) * 3);
	return ;
}

void		op_retreive_data(t_objmodel *m, t_vao_basic *vao)
{
	size_t		ptrpad;
	t_ui		nfloats[1];

	ptrpad = m->width * sizeof(float) + sizeof(t_ftset_node);
	vao->vbo.npos = 3;
	if (m->width == 5 || m->width == 8)
		vao->vbo.ntex = 2;
	if (m->width == 6 || m->width == 8)
		vao->vbo.nnor = 3;
	fts_foreachi(&m->vertices, &push_index, &ptrpad);
	retreive_faces(m, &vao->ebo.faces);
	*nfloats = (m->vertices.chunk_size - sizeof(t_ui) - sizeof(t_ftset_node))
				/ sizeof(float);
	ft_set_to_vector(&m->vertices, &vao->vbo.vertices
						, &extract_vertices, nfloats);
	return ;
}
