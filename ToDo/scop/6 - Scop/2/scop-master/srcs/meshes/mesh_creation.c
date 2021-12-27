/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 14:25:20 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:38:47 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <string.h>

t_location_info const	g_locinfo[sp_num_locs] = {
	{"pos", offsetof(t_vertex_basic, pos), offsetof(t_vbo_basic, npos)},
	{"col", offsetof(t_vertex_basic, col), offsetof(t_vbo_basic, ncol)},
	{"tex", offsetof(t_vertex_basic, tex), offsetof(t_vbo_basic, ntex)},
	{"nor", offsetof(t_vertex_basic, nor), offsetof(t_vbo_basic, nnor)}
};

static int	validate_vbo(t_vbo_basic const *vbo, t_vshader const *vs)
{
	size_t		i;
	int			error;
	t_byte		num_elt_vbo;
	t_byte		num_elt_vs;

	error = 0;
	i = 0;
	while (i < sp_num_locs)
	{
		num_elt_vbo = *REACH_OFFSET(t_byte, vbo, g_locinfo[i].vbo_basic_offset);
		num_elt_vs = sp_location_size(vs, i);
		if (num_elt_vbo != num_elt_vs)
		{
			ERRORF("%s(%hhu/%hhu)", g_locinfo[i].str, num_elt_vbo, num_elt_vs);
			error = 1;
		}
		i++;
	}
	return (error);
}

int			sp_new_mesh(t_env const *e, t_mesh *me)
{
	t_vao_basic				vao[1];
	t_vshader const *const	vs = VSOFME(e, me);
	t_ftvector				vbo_final[1];
	t_ftvector				ebo_final[1];

	bzero(vao, sizeof(vao));
	if (sp_vao_primary_build(me, vao))
		return (ERROR("sp_build_vao_primary(vao, vs)"));
	sp_vao_secondary_build(e, me, vao, vs);
	if (validate_vbo(&vao->vbo, vs))
		return (ERROR("validate_vbo(...)"));
	sp_vao_final_build(vbo_final, ebo_final, vao);
	sp_vao_final_push(me, vs, vbo_final, ebo_final);
	qprintf("\033[32m%-7zu\033[0mVerts, \033[32m%-7zu\033[0mFaces "
			, vbo_final->size, ebo_final->size);
	me->faces3 = ebo_final->size * 3;
	qprintf("\n");
	qprintf("vbo: ");
	ftv_summarize(vbo_final);
	qprintf("ebo: ");
	ftv_summarize(ebo_final);
	ftv_release(&vao->vbo.vertices, NULL);
	ftv_release(&vao->ebo.faces, NULL);
	ftv_release(vbo_final, NULL);
	ftv_release(ebo_final, NULL);
	return (0);
}
