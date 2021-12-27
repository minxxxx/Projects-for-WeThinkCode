/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   land_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 08:05:58 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/19 19:00:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <string.h>
#include <math.h>

static void	first_pass(t_program const p[1], t_land_tmp const ld[1])
{
	glUseProgram(p->handle);
	UNIF(p, m1i, "level_stride", ld->grid_width / 2);
	UNIF(p, m1iv, "phase_startoffset", 2, (int[]){0, 0});
	UNIF(p, m2fv, "random_seeds", 1, (float[]){ft_randf01(), ft_randf01()});
	UNIF(p, m1f, "land_average_y", LAND_YF);
	UNIF(p, m1f, "land_range_y", LAND_RANGEF);
	UNIF(p, m1f, "land_min_y", LAND_MINYF);
	UNIF(p, m1f, "land_magnitude_y", LAND_MAGNITUDEYF);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glFlush();//flush!!
	return ;
}

static void	push_tex_and_unif(t_program const p[1], t_land_tmp const ld[1]
							  , int stride, float land_range)
{
	glUseProgram(p->handle);
	UNIF(p, m1i, "level_stride", stride);
	UNIF(p, m2fv, "random_seeds", 1, (float[]){ft_randf01(), ft_randf01()});
	UNIF(p, m1f, "land_average_y", LAND_YF);
	UNIF(p, m1f, "land_range_y", land_range);
	UNIF(p, m1i, "tex", 0);
	UNIF(p, m1f, "land_min_y", LAND_MINYF);
	UNIF(p, m1f, "land_magnitude_y", LAND_MAGNITUDEYF);
	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, *ld->ytex_handle);
	return ;
}

static void	generate_land(t_env e[1], t_land_tmp ld[1])
{
	t_program const		*p;
	int					stride;
	float				land_range;
	int					depth_loop;

	glBindFramebuffer(GL_FRAMEBUFFER, *ld->fbo_handle);
	glViewport(0, 0, ld->grid_width, ld->grid_width);
	glDisable(GL_DEPTH_TEST);
	glBindVertexArray(*ld->vao_handle);
	first_pass(e->programs + sp_landgen_notrel_program, ld);	
	stride = ld->grid_width;
	land_range = LAND_RANGEF;
	depth_loop = 0;
	while (++depth_loop <= LAND_NDEPTHLOOPSI)
	{
		land_range *= LAND_RANGEDECAYF;
		stride /= 2;
		p = e->programs + sp_landgen_diag_program;
		push_tex_and_unif(p, ld, stride, land_range);
		UNIF(p, m1iv, "phase_startoffset", 2, (int[]){stride / 2, stride / 2});
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		glFlush();		
		p = e->programs + sp_landgen_horiz_program;
		push_tex_and_unif(p, ld, stride, land_range);
		UNIF(p, m1iv, "phase_startoffset", 2, (int[]){stride / 2, 0});
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		UNIF(p, m1iv, "phase_startoffset", 2, (int[]){0, stride / 2});
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		glFlush();
	}
	glFinish(); // ???
	glBindVertexArray(0);
	glUseProgram(0);
	return ;
}

static void	generate_normals(t_env e[1], t_land_tmp ld[1])
{
	t_program const		*p;

	glBindFramebuffer(GL_FRAMEBUFFER, *ld->fbo2_handle);
	glViewport(0, 0, ld->grid_width, ld->grid_width);
	glDisable(GL_DEPTH_TEST);
	glBindVertexArray(*ld->vao_handle);
	p = e->programs + sp_landgen_normals_program;
	glUseProgram(p->handle);
	/* UNIF(p, m1i, "level_stride", stride); */
	/* UNIF(p, m1f, "height_factor", 1.f / 25.f); */
	UNIF(p, m3fv, "posfactors", 1, (float*)&LAND_COORDFACT);
	/* UNIF(p, m1f, "land_range_y", land_range); */
	UNIF(p, m1i, "ymap", 0);
	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, *ld->ytex_handle);
	
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glFinish(); // ???
	/* glFlush(); */
	glBindVertexArray(0);
	glUseProgram(0);
	return ;
}
 
static void	setup_ld(t_land_tmp ld[1])
{
	bzero(ld, sizeof(*ld));
	ld->grid_npoints = (int)pow(4.f, (float)(LAND_NDEPTHLOOPSI + 1));
	ld->grid_width = (int)pow(2.f, (float)(LAND_NDEPTHLOOPSI + 1));
	qprintf("grid_npoints:%d grid_width:%d\n", ld->grid_npoints
			, ld->grid_width);
	return ;
}

static int	setup_textures(t_land_tmp ld[1])
{
	glGenTextures(1, ld->ytex_handle);
	glBindTexture(GL_TEXTURE_2D, *ld->ytex_handle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0 , GL_R32F , ld->grid_width , ld->grid_width, 0
				 , GL_RED, GL_FLOAT, NULL);
	glGenTextures(1, ld->coltex_handle);
	glBindTexture(GL_TEXTURE_2D, *ld->coltex_handle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ld->grid_width , ld->grid_width, 0
				 , GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glGenTextures(1, ld->nortex_handle);
	glBindTexture(GL_TEXTURE_2D, *ld->nortex_handle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB32F, ld->grid_width , ld->grid_width, 0
				 , GL_RGB, GL_FLOAT, NULL);
	return (0);
}

static int	setup_fbo(t_land_tmp ld[1])
{	
	glGenFramebuffers(1, ld->fbo_handle);
	glBindFramebuffer(GL_FRAMEBUFFER, *ld->fbo_handle);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0
						 , *ld->ytex_handle, 0);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1
						 , *ld->coltex_handle, 0);
	glDrawBuffers(2, (GLenum[]){GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1});
	glReadBuffer(GL_NONE);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		return (ERROR("Framebuffer not complete!"));
	glGenFramebuffers(1, ld->fbo2_handle);
	glBindFramebuffer(GL_FRAMEBUFFER, *ld->fbo2_handle);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0
						 , *ld->nortex_handle, 0);
	glDrawBuffers(1, (GLenum[]){GL_COLOR_ATTACHMENT0});
	glReadBuffer(GL_NONE);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		return (ERROR("Framebuffer not complete!"));
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	return (0);
}

static void	setup_vao(t_land_tmp ld[1])
{
	GLfloat const	 vertices[] = {
	-1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, -1.0f};

	glGenVertexArrays(1, ld->vao_handle);
	glBindVertexArray(*ld->vao_handle);
	glGenBuffers(1, ld->vbo_handle);
	glBindBuffer(GL_ARRAY_BUFFER, *ld->vbo_handle);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	/* glDeleteBuffers(1, &quad_vbo); */
	return ;
}

int			sp_init_land(t_env *e)
{
	t_land_tmp		ld[1];

	setup_ld(ld);
	if (setup_textures(ld))
		return (ERROR("setup_textures(...)"));
	if (setup_fbo(ld))
		return (ERROR("setup_fbo(...)"));
	setup_vao(ld);
	generate_land(e, ld);
	generate_normals(e, ld);
	e->land_tex1 = (t_texture){NULL, GL_TEXTURE_2D
		, {ld->grid_width, ld->grid_width}, *ld->ytex_handle};
	e->land_tex2 = e->land_tex1;
	e->land_tex2.handle = *ld->coltex_handle;
	e->land_tex3 = e->land_tex1;
	e->land_tex3.handle = *ld->nortex_handle;
	e->land_d_range_tess = sqrt(2.f) * LAND_COORDFACT.x;
	e->land_tesslevelin_range = pow(2.f, LAND_NDEPTHLOOPSI - LAND_NDEPTHLOOPSCPI);
	glBindTexture(GL_TEXTURE_2D, *ld->coltex_handle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	/* glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); */
	glBindTexture(GL_TEXTURE_2D, *ld->nortex_handle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	return (0);
}
