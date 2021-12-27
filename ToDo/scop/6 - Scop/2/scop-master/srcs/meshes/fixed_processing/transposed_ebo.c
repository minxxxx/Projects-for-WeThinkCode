/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transposed_ebo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:40:04 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:40:04 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdlib.h>

static void	set_nfaces(t_transp_ebo tebo[1], t_face_basic const face[1])
{
	size_t					i;
	t_vertex_transp *const	tvertices = tebo->tvertices.data;

	i = 0;
	while (i < 3)
	{
		tvertices[face->indices[i]].nfaces++;
		i++;
	}
	return ;
}

static void	set_faces_ptr(t_ui *tmp_field[1], t_vertex_transp tvertex[1])
{
	tvertex->faces = *tmp_field;
	*tmp_field += tvertex->nfaces;
	tvertex->nfaces = 0;
	return ;
}

static void	set_faces(t_transp_ebo tebo[1], t_face_basic const face[1]
					 	, size_t facei)
{
	size_t					i;
	t_vertex_transp *const	tvertices = tebo->tvertices.data;
	t_vertex_transp			*tvertex;

	i = 0;
	while (i < 3)
	{
		tvertex = tvertices + face->indices[i];
		tvertex->faces[tvertex->nfaces++] = facei;
		i++;
	}
	return ;
}

void		sp_transpose_ebo(t_transp_ebo tebo[1], t_vao_basic const vao[1])
{
	t_ui		*field_tmp[1];

	if (ftv_init_instance(&tebo->tvertices, sizeof(t_vertex_transp)))
		ft_enomem();
	if (ftv_insert_count(&tebo->tvertices
							, &(t_vertex_transp){0, NULL}
							, vao->vbo.vertices.size))
		ft_enomem();
	ftv_foreach(&vao->ebo.faces, &set_nfaces, tebo);
	tebo->field = malloc(sizeof(t_ui) * 3 * vao->ebo.faces.size);
	if (tebo->field == NULL)
		ft_enomem();
	*field_tmp = tebo->field;
	ftv_foreach(&tebo->tvertices, &set_faces_ptr, field_tmp);
	ftv_foreachi(&vao->ebo.faces, &set_faces, tebo);
	return ;
}
