/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vao_final_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:37:26 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/19 07:49:28 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <unistd.h>

extern t_location_info const	g_locinfo[sp_num_locs];

static void	push_attributes(t_vshader const *vs, size_t vert_width)
{
	size_t		i;
	GLvoid		*delta;

	delta = NULL;
	qprintf("    Locations:  ");
	i = -1;
	while (++i < vs->n_locations)
	{
		qprintf("\"\033[31m%s\033[0m\":%u,%u,%02u,%02u  ",
				g_locinfo[vs->locations[i].type].str
				, i, vs->locations[i].size
				, vert_width, delta);
		glVertexAttribPointer(i, vs->locations[i].size, GL_FLOAT, GL_FALSE
								, vert_width, delta);
		glEnableVertexAttribArray(i);
		delta += vs->locations[i].size * sizeof(GLfloat);
	}
	qprintf("\n");
	return ;
}

static void	push_buffers(t_mesh *me, t_ftvector const vbo_final[1]
							, t_ftvector const ebo_final[1])
{
	if (!me->generated)
		glGenBuffers(1, me->handles + 1);
	glBindBuffer(GL_ARRAY_BUFFER, me->handles[1]);
	glBufferData(GL_ARRAY_BUFFER, vbo_final->size * vbo_final->chunk_size
					, vbo_final->data, me->usage);
	if (!me->generated)
		glGenBuffers(1, me->handles + 2);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, me->handles[2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER
					, ebo_final->size * ebo_final->chunk_size
					, ebo_final->data, me->usage);
}

void		sp_vao_final_push(t_mesh *me, t_vshader const *vs
						, t_ftvector const vbo_final[1]
						, t_ftvector const ebo_final[1])
{
	size_t const	vao_size = vbo_final->size * vbo_final->chunk_size
		+ ebo_final->size * ebo_final->chunk_size;

	if (!me->generated)
		glGenVertexArrays(1, me->handles + 0);
	glBindVertexArray(me->handles[0]);
	if (vao_size > 100000000)
	{
		qprintf("Vao's size is %zu(%.2f MB), continue ?\n"
				, vao_size, (float)vao_size / 1000000.f);
		read(0, NULL, 1);
	}
	push_buffers(me, vbo_final, ebo_final);
	push_attributes(vs, vbo_final->chunk_size);
	glBindVertexArray(0);
	me->generated = true;
	return ;
}
