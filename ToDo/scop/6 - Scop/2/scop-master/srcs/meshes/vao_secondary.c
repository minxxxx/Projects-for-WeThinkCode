/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vao_secondary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:36:11 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:36:13 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
** Three ways of building secondary vao:
**		1. No split.
**				Basic. Might do nothing on some primary vao.
**		2. Split.
**				Parts detection inside mesh, duplication of vertices to separate
**				parts. Done for normals+uv calculations.
**		2.1 Keep vertices' normals after-split
**				e.g. 42.obj
**		2.2 Keep vertices' normals before-split
**				But uses normals after-split for uv calculations.
**				e.g. teapot.obj with uvwrap_box
**			
*/

static void	no_split(t_env const *e, t_mesh const *me
					 , t_vao_basic *vao, t_vshader const *vs)
{
	t_byte const	nnor_req = sp_location_size(vs, sp_nor_loc);
	t_byte const	ntex_req = sp_location_size(vs, sp_tex_loc);

	if (me->recenter_positions)
		sp_recenter_positions(&vao->vbo);
	if (nnor_req != vao->vbo.nnor)
	{
		sp_normals_to_ebo(vao);
		sp_normals_to_vbo(vao);
	}
	if (ntex_req != vao->vbo.ntex)
	{
		ftv_foreach(&vao->vbo.vertices, ME_TEXWRAPFUN(e, me), (void*)me);
		vao->vbo.ntex = 2;
	}
	return ;
}

static void	with_split_nor_after(t_env const *e, t_mesh const *me
								 , t_vao_basic *vao, t_vshader const *vs)
{
	t_byte const	ntex_req = sp_location_size(vs, sp_tex_loc);

	if (me->recenter_positions)
		sp_recenter_positions(&vao->vbo);
	sp_normals_to_ebo(vao);
	ME_EBOGRPFUN(e, me)(vao);
	sp_rebuild_vbo_from_groups(vao);
	sp_normals_to_vbo(vao);
	if (ntex_req != vao->vbo.ntex)
	{
		ftv_foreach(&vao->vbo.vertices, ME_TEXWRAPFUN(e, me), (void*)me);
		vao->vbo.ntex = 2;
	}
	return ;
}

static void	with_split_nor_before(t_env const *e, t_mesh const *me
								  , t_vao_basic *vao, t_vshader const *vs)
{
	t_ftvector		vbo_save[1];

	if (me->recenter_positions)
		sp_recenter_positions(&vao->vbo);
	sp_normals_to_ebo(vao);
	sp_normals_to_vbo(vao);
	ME_EBOGRPFUN(e, me)(vao);
	sp_rebuild_vbo_from_groups(vao);
	if (ftv_copy(vbo_save, &vao->vbo.vertices))
		ft_enomem();
	sp_normals_to_vbo(vao);
	ftv_foreach(&vao->vbo.vertices, ME_TEXWRAPFUN(e, me), (void*)me);
	vao->vbo.ntex = 2;
	sp_vbo_normals_restore(&vao->vbo.vertices, vbo_save);
	ftv_release(vbo_save, NULL);
	return ;
	(void)vs;
}

void		sp_vao_secondary_build(t_env const *e, t_mesh const *me
								   , t_vao_basic *vao, t_vshader const *vs)
{
	if (me->ebogrouping != sp_no_ebogrouping &&
		sp_location_size(vs, sp_nor_loc) != vao->vbo.nnor)
	{
		if (me->vertices_normals_before_split)
			with_split_nor_before(e, me, vao, vs);
		else
			with_split_nor_after(e, me, vao, vs);
	}
	else
		no_split(e, me, vao, vs);
	return ;
}
