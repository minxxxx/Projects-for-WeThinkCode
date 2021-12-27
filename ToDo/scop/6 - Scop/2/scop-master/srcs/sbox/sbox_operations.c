/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sbox_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 17:35:51 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 14:56:22 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int				sp_init_sbox(t_env *e)
{
	int		i;

	glGenTextures(1, &e->sbox_texture.handle);
	glBindTexture(GL_TEXTURE_CUBE_MAP, e->sbox_texture.handle);
	i = 0;
	while (i < 6)
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i++
			, 0, GL_DEPTH_COMPONENT
			, e->sbox_texture.dim[0], e->sbox_texture.dim[1], 0
			, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glGenFramebuffers(1, &e->sbox_fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, e->sbox_fbo);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
		e->sbox_texture.handle, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		return (ERROR("Framebuffer not complete!\n"));
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	return (0);
}
