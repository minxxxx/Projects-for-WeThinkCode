/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 14:11:32 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 17:33:54 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <assert.h>

static int		new_texture(t_texture *t)
{
	t_ftvector	v;

	glGenTextures(1, &t->handle);
	glBindTexture(GL_TEXTURE_2D, t->handle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if (ftv_init_instance(&v, sizeof(t_byte) * 4))
		sp_enomem();
	if (parse_tga(t->filepath, &v, t->dim))
		return (ERRORF("parse_tga(%s, &v, dim)", t->filepath));
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, t->dim[0], t->dim[1], 0,
				GL_BGRA, GL_UNSIGNED_BYTE, v.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	ftv_release(&v, NULL);
	glBindTexture(GL_TEXTURE_2D, 0);
	return (0);
}

void			sp_activate_texture(t_program const *p, t_texslot texslot
									, t_texture const *t, char const *unifname)
{
	int const		gltexi = p->gltexi[texslot];

	assert(gltexi >= 0);
	UNIF(p, m1i, unifname, gltexi);
	glActiveTexture(GL_TEXTURE0 + gltexi);
	glBindTexture(t->target, t->handle);
	return ;
}

void			sp_delete_textures(t_env *e)
{
	t_texture			*t;
	t_texture const		*end = ITEND_TEXTURES(e);

	t = e->textures;
	while (t < end)
	{
		glDeleteTextures(1, &t->handle);
		t++;
	}
	return ;
}

int				sp_init_textures(t_env *e)
{
	int		i;

	i = 0;
	while (i < sp_num_textures)
	{
		if (new_texture(e->textures + i))
			return (ERRORF("new_texture(%s, ...)", e->textures[i].filepath));
		i++;
	}
	return (0);
}
