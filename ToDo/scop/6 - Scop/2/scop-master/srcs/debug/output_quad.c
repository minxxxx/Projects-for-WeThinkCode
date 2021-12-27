/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_quad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 15:19:38 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/17 15:59:32 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		sp_debug_putquad_screencoord(t_vec2i topright)
{
	t_vec2 const		trf = {(float)topright.x, (float)topright.y};
	GLfloat const		right = (trf.x - WIN_HALFWIDTHF) / WIN_HALFWIDTHF;
	GLfloat const		top = (trf.y - WIN_HALFHEIGHTF) / WIN_HALFHEIGHTF;
	GLfloat const		vertices[] = {
		right, top, -1.0f, top, right, -1.0f, -1.0f, -1.0f};
	GLuint				handles[2];

	glGenVertexArrays(1, handles + 0);
	glBindVertexArray(handles[0]);
	glGenBuffers(1, handles + 1);
	glBindBuffer(GL_ARRAY_BUFFER, handles[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
	glViewport(0, 0, WIN_WIDTHI, WIN_HEIGHTI);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, sizeof(vertices) / sizeof(*vertices) / 2);
	glBindVertexArray(0);
	glDeleteBuffers(1, handles + 1);
	glDeleteVertexArrays(1, handles + 0);
	return ;
}
