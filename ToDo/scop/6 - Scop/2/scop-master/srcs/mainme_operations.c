/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainme_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:42:57 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:42:57 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	sp_mainme_scroll_objfile(t_env *e, int v)
{
	t_mesh *const	me = e->meshes + sp_main_mesh;

	me->objfile = (me->objfile + v + sp_num_objfiles) % sp_num_objfiles;
	sp_new_mesh(e, me);
	return ;
}

void	sp_mainme_toggle_recenter(t_env *e, int v)
{
	t_mesh *const	me = e->meshes + sp_main_mesh;

	me->recenter_positions = (me->recenter_positions + 1) % 2;
	sp_new_mesh(e, me);
	(void)v;
	return ;
}

void	sp_mainme_scroll_ebogrouping(t_env *e, int v)
{
	t_mesh *const	me = e->meshes + sp_main_mesh;

	me->ebogrouping = (me->ebogrouping + v + sp_num_ebogroupings)
		% sp_num_ebogroupings;
	sp_new_mesh(e, me);
	return ;
}

void	sp_mainme_toggle_ebogroupingbefore(t_env *e, int v)
{
	t_mesh *const	me = e->meshes + sp_main_mesh;

	me->vertices_normals_before_split =
		(me->vertices_normals_before_split + 1) % 2;
	sp_new_mesh(e, me);
	(void)v;
	return ;
}

void	sp_mainme_scroll_texwrapping(t_env *e, int v)
{
	t_mesh *const	me = e->meshes + sp_main_mesh;

	me->texwrapping = (me->texwrapping + v + sp_num_texwrappings)
		% sp_num_texwrappings;
	sp_new_mesh(e, me);
	return ;
}

void	sp_mainme_change_texscale(t_env *e, int v)
{
	t_mesh *const	me = e->meshes + sp_main_mesh;
	float const		fact = v > 0 ? 1.05f : 0.95f;

	me->tex_scale[0] *= fact;
	me->tex_scale[1] *= fact;
	sp_new_mesh(e, me);
	return ;
}
