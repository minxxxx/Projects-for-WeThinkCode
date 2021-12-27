/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objmodel_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 08:26:17 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:36:03 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "scop.h"
#include "objmodel/objmodel_parsing.h"

#define SKIP_NODEPART(P) (((void*)(P)) + sizeof(t_ftset_node))

void		sp_clean_objmodel(t_objmodel *m)
{
	ftv_release(&m->textures, NULL);
	ftv_release(&m->coords, NULL);
	ftv_release(&m->normals, NULL);
	if (m->faces.data != NULL)
	{
		ftv_release(&m->faces, NULL);
		fts_release(&m->vertices, NULL);
	}
	return ;
}

static int	cmp_floats(float const *min, float const *max, t_ftset const *s)
{
	return (memcmp(SKIP_NODEPART(min)
					, SKIP_NODEPART(max)
					, s->chunk_size - sizeof(t_ui) - sizeof(t_ftset_node)));
}

void		op_init_meshvectors(t_objmodel *m)
{
	m->width = 3;
	if (m->textures.size > 0)
		m->width += 2;
	if (m->normals.size > 0)
		m->width += 3;
	if (ftv_init_instance(&m->faces, sizeof(t_tmpface)))
		sp_enomem();
	fts_init_instance(&m->vertices, sizeof(t_ftset_node)
						+ sizeof(float) * m->width + sizeof(t_ui), cmp_floats);
	return ;
}
