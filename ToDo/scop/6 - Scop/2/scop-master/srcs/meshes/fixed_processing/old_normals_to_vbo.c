/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_normals_to_vbo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:40:13 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:40:14 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		sp_vbo_normals_restore(t_ftvector *dst, t_ftvector const *src)
{
	t_vertex_basic				*vert_dst;
	t_vertex_basic const		*vert_src = src->data;
	t_vertex_basic const *const	vert_src_end = ftv_end(src);

	vert_dst = dst->data;
	while (vert_src != vert_src_end)
	{
		*(t_vec3*)&vert_dst->nor = *(t_vec3*)&vert_src->nor;
		vert_src++;
		vert_dst++;
	}
	return ;
}
