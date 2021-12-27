/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups_to_vbo_box.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:42:24 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:42:25 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	group_to_face(t_face_basic *face)
{
	float const		nx = ABS(face->nor.x);
	float const		ny = ABS(face->nor.y);
	float const		nz = ABS(face->nor.z);

	if (nz > nx && nz > ny)
		face->group = face->nor.z > 0.f ? 0 : 1;
	else if (ny > nx)
		face->group = face->nor.y > 0.f ? 2 : 3;
	else
		face->group = face->nor.x > 0.f ? 4 : 5;
	return ;
}

void		sp_groups_to_ebo_box(t_vao_basic *vao)
{
	ftv_foreach0(&vao->ebo.faces, &group_to_face);
	return ;
}
