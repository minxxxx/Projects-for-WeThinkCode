/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obs_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 12:01:57 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/19 12:03:39 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#define LOC(N)  glGetUniformLocation(p->handle, N)
#define PREFIX(T) glUniform ## T
#define U(T, N, ...) PREFIX(T)(LOC(N), __VA_ARGS__)

#define NORM_AT_42_IS_WTF(E, OB, MO) (MO)->update_uniforms((E), (OB))

static void		render_ob(t_env const *e, t_ob *ob)
{
	t_model const *const	mo = MOOFOB(e, ob);
	t_mesh const *const		me = MEOFMO(e, mo);
	t_program const *const	p = POFME(e, me);

	if (mo->update_uniforms != NULL)
		NORM_AT_42_IS_WTF(e, ob, mo);
	if (mo->texture != sp_no_texture)
		sp_activate_texture(p, sp_image1_texslot, TOFMO(e, mo), "ourTexture");
	if (p->gltexi[sp_sbox_texslot] >= 0)
		sp_activate_texture(p, sp_sbox_texslot, &e->sbox_texture, "depthMap");
	if (me->program == sp_landrender_program)
	{
		sp_activate_texture(p, sp_image1_texslot, &e->land_tex1, "ymap");
		sp_activate_texture(p, sp_image2_texslot, &e->land_tex2, "colmap");
		sp_activate_texture(p, sp_image3_texslot, &e->land_tex3, "normap");
	}
	glBindVertexArray(me->handles[0]);
	if (p->tcshader != sp_no_tcshader)
	{
		glPatchParameteri(GL_PATCH_VERTICES, 3);
		glDrawElements(GL_PATCHES, me->faces3, GL_UNSIGNED_INT, 0);
	}
	else
		glDrawElements(GL_TRIANGLES, me->faces3, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	return ;
}

void			render_prog_obs(t_env const *e, t_program_index i)
{
	t_program const	*const	p = e->programs + i;
	t_ftlist const *const	prl = e->obs + i;
	void					(*const vsunif_update)() = VSOFP(e, p)->unif_update;
	void					(*const fsunif_update)() = FSOFP(e, p)->unif_update;
	void					(*const gsunif_update)() = GSOFP(e, p)->unif_update;
	void					(*const tcsunif_update)() = TCSOFP(e, p)->unif_update;
	void					(*const tesunif_update)() = TESOFP(e, p)->unif_update;

	glUseProgram(p->handle);
	if (vsunif_update != NULL)
		vsunif_update(e, p);
	if (fsunif_update != NULL)
		fsunif_update(e, p);
	if (p->gshader != sp_no_gshader && gsunif_update != NULL)
		gsunif_update(e, p);
	if (p->tcshader != sp_no_tcshader && tcsunif_update != NULL)
		tcsunif_update(e, p);
	if (p->teshader != sp_no_teshader && tesunif_update != NULL)
		tesunif_update(e, p);
	ftl_foreach_if((void*)prl, &render_ob, (void*)e, &sp_ob_getnot_hidden);
	return ;
}

void			sp_render_obs(t_env const *e)
{
	t_program_index		i;

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, WIN_WIDTHI, WIN_HEIGHTI);
	glEnable(GL_DEPTH_TEST);
	glClearColor(155. / 256., 216. / 256., 220. / 256., 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	i = -1;
	while (++i < sp_num_programs)
	{
		if (e->obs[i].size == 0)
			continue ;
		render_prog_obs(e, i);
	}
	return ;
}
