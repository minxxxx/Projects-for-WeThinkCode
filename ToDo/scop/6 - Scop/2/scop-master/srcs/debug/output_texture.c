/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 16:34:01 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/17 17:04:19 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		sp_debug_puttexture2d(t_env const *e, t_texture const *t)
{
	t_program const     *p = p = e->programs + sp_debug_print_sampler_program;

	glUseProgram(p->handle);
//	qprintf("using enum%d  handle%d\n", sp_debug_print_sampler_program, p->handle);	
//	UNIF(p, m2fv, "viewport", 1, (float[]){WIN_WIDTHF, WIN_HEIGHTF});
	UNIF(p, m1i, "tex", 0);
	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, t->handle);
	glClear(GL_DEPTH_BUFFER_BIT);
	sp_debug_putquad_screencoord(ATOV2I(t->dim[0], t->dim[1]));
	return ;
}
