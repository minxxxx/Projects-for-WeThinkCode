/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_insert_face.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 11:05:53 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/03 11:40:00 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "objmodel/objmodel_parsing.h"

#define POS(I) (((float*)(m->coords.data)) + 3 * (I))
#define TEXTURE(I) (((float*)m->textures.data) + 2 * (I))
#define NORMAL(I) (((float*)m->normals.data) + 3 * (I))

/*
** 'op_insert_face'		receives indices in the right order.
** 							(plan 0/3/6, texture 1/4/7, normal 2/5/8)
** 							pushes them in ->vertices, ->faces
** **
** 'build_vertex'		receives 3 indices for [0]plan/[1]texture/[2]normal
** 							builds vert[8]
** **
** 'gen_vertex_index'	receives a vertex pointer, returns it's index
**							(may create it's index)
** *
**	'if (m->width != 8 && m->width != 6)'
**		UGLY LVL 9000
*/

static t_ftset_node	*gen_vertex_index(t_objmodel *m, t_ftset_node const *buf)
{
	t_ftset_insertion	result[1];

	if (fts_insert(&m->vertices, buf, result))
		sp_enomem();
	return (result->ptr);
}

static void			build_vertex(t_objmodel const *m, float *vert,
							t_ui const indices[3])
{
	memcpy(vert, POS(indices[0]), sizeof(float) * 3);
	if (m->width == 5)
	{
		memcpy(vert + 3, TEXTURE(indices[1]), sizeof(float) * 2);
	}
	else if (m->width == 6)
	{
		memcpy(vert + 3, NORMAL(indices[2]), sizeof(float) * 3);
	}
	else if (m->width == 8)
	{
		memcpy(vert + 3, TEXTURE(indices[1]), sizeof(float) * 2);
		memcpy(vert + 5, NORMAL(indices[2]), sizeof(float) * 3);
	}
	return ;
}

void				op_insert_face(t_objmodel *m, t_ui const oldind[9])
{
	t_tmpface	newindices[1];
	t_byte		buf[sizeof(t_ftset_node) + sizeof(float) * 8 + sizeof(t_ui)];
	float		*vert;

	vert = (void*)&buf + sizeof(t_ftset_node);
	build_vertex(m, vert, oldind);
	newindices->ptr[0] = gen_vertex_index(m, (t_ftset_node*)buf);
	build_vertex(m, vert, oldind + 3);
	newindices->ptr[1] = gen_vertex_index(m, (t_ftset_node*)buf);
	build_vertex(m, vert, oldind + 6);
	newindices->ptr[2] = gen_vertex_index(m, (t_ftset_node*)buf);
	if (ftv_push_back(&m->faces, newindices))
		sp_enomem();
	return ;
}
