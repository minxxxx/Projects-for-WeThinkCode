/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 12:32:53 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 13:29:17 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

extern t_location_info const	g_locinfo[sp_num_locs];

static int		check_program_error(GLuint program, GLuint flag)
{
	GLint		success[1];
	GLchar		msg[1024];

	glGetProgramiv(program, flag, success);
	if (*success == GL_FALSE)
	{
		glGetProgramInfoLog(program, sizeof(msg), NULL, msg);
		qprintf("\033[35m%s\033[0m\n", msg);
		return (1);
	}
	return (0);
}

static int		new_program(t_env const *e, t_program *p)
{
	size_t					i;
	t_vshader const	*const	vs = VSOFP(e, p);

	p->handle = glCreateProgram();
	glAttachShader(p->handle, vs->handle);
	glAttachShader(p->handle, FSOFP(e, p)->handle);
	if (p->gshader != sp_no_gshader)
		glAttachShader(p->handle, GSOFP(e, p)->handle);
	if (p->tcshader != sp_no_tcshader)
		glAttachShader(p->handle, TCSOFP(e, p)->handle);
	if (p->teshader != sp_no_teshader)
		glAttachShader(p->handle, TESOFP(e, p)->handle);
	i = 0;
	while (i < vs->n_locations)
	{
		glBindAttribLocation(p->handle
								, i, g_locinfo[vs->locations[i].type].str);
		i++;
	}
	glLinkProgram(p->handle);
	if (check_program_error(p->handle, GL_LINK_STATUS))
		return (ERROR("glLinkProgram(...)"));
	glValidateProgram(p->handle);
	if (check_program_error(p->handle, GL_LINK_STATUS))
		return (ERROR("glValidateProgram(...)"));
	return (0);
}

void			sp_delete_programs(t_env *e)
{
	t_program				*p;
	t_program const *const	end = ITEND_PROGRAMS(e);

	p = e->programs;
	while (p < end)
	{
		glDetachShader(p->handle, VSOFP(e, p)->handle);
		glDetachShader(p->handle, FSOFP(e, p)->handle);
		if (p->gshader != sp_no_gshader)
			glDetachShader(p->handle, GSOFP(e, p)->handle);
		glDeleteProgram(p->handle);
		p++;
	}
	return ;
}

int				sp_init_programs(t_env *e)
{
	int		i;

	i = 0;
	while (i < sp_num_programs)
	{
		if (new_program(e, e->programs + i))
			return (ERRORF("new_program(%d)", i));
		i++;
	}
	return (0);
}
