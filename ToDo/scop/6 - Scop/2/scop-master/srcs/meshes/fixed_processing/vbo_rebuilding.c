/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbo_rebuilding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 16:27:03 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:46:11 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdlib.h>

static t_bool	is_pushed_for_group(t_vertex_transp const tvertex[1]
									, t_face_basic const *faces
									, t_ui curi, int group)
{
	t_ui						i;

	i = 0;
	while (i < curi)
	{
		if (faces[tvertex->faces[i]].group == group)
			return (true);
		i++;
	}
	return (false);
}

static void		update_indices_for_group(t_vertex_transp const tvertex[1]
											, t_face_basic *faces
											, t_ui i
											, size_t indices[2])
{
	int const			group = faces[tvertex->faces[i]].group;
	t_face_basic		*face;
	int					j;

	while (i < tvertex->nfaces)
	{
		face = faces + tvertex->faces[i];
		if (face->group == group)
		{
			j = 0;
			while (j < 3)
			{
				if (face->indices[j] == indices[0])
					face->indices[j] = indices[1];
				j++;
			}
		}
		i++;
	}
	return ;
}

static void		duplicate_vertex(t_vao_basic vao[1]
									, t_vertex_transp const tvertex[1]
									, size_t vi)
{
	t_ftvector *const			vertices = &vao->vbo.vertices;
	t_vertex_basic const		vertex = ((t_vertex_basic*)vertices->data)[vi];
	t_face_basic *const			faces = vao->ebo.faces.data;
	int							group;
	t_ui						i;

	i = 1;
	while (i < tvertex->nfaces)
	{
		group = faces[tvertex->faces[i]].group;
		if (!is_pushed_for_group(tvertex, faces, i, group))
		{
			if (ftv_push_back(vertices, &vertex))
				ft_enomem();
			update_indices_for_group(tvertex, faces, i
										, (size_t[2]){vi, vertices->size - 1});
		}
		i++;
	}
	return ;
}

void			sp_rebuild_vbo_from_groups(t_vao_basic *vao)
{
	t_transp_ebo	tebo[1];

	sp_transpose_ebo(tebo, vao);
	ftv_foreachi(&tebo->tvertices, &duplicate_vertex, vao);
	ftv_release(&tebo->tvertices, NULL);
	free(tebo->field);
	return ;
}
