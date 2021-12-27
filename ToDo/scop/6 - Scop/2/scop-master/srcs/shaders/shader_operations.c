/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 12:15:52 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/15 09:43:24 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BADLOAD_FMT "Could not open %s \"\033[35m%s\033[0m\""
#define BADCREATE_FMT "Error in glCreateShader(%d)"

#define GLTYPE(NAME) (GL_ ## NAME ## _SHADER)
#define NUM(LETTER) (sp_num_ ## LETTER ## shaders)
#define OF_E(LETTER) offsetof(t_env, LETTER ## shaders)
#define OF_F(TYPE) offsetof(TYPE, filepath)
#define OF_H(TYPE) offsetof(TYPE, handle)

#define S(C, L, T) {GLTYPE(C), #C, NUM(L), OF_E(L), sizeof(T), OF_F(T), OF_H(T)}

static const struct s_env_shader_type	g_shaders_types[] = {
	S(VERTEX, v, t_vshader),
	S(FRAGMENT, f, t_fshader),
	S(GEOMETRY, g, t_gshader),
	S(TESS_CONTROL, tc, t_tcshader),
	S(TESS_EVALUATION, te, t_teshader)
};

static int		check_shader_error(GLuint shader, GLuint flag)
{
	GLint		success[1];
	GLchar		msg[256];

	glGetShaderiv(shader, flag, success);
	if (*success == GL_FALSE)
	{
		glGetShaderInfoLog(shader, sizeof(msg), NULL, msg);
		ERRORF("Shader compilation: \n\033[35m%s\033[0m", msg);
		return (1);
	}
	return (0);
}

static int		sp_load_shader(char const *filepath, char **ptr)
{
	int		fd;
	int		ret;
	char	buffer[1024];

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (ERRORNOF("fopen(\"%s\")", filepath));
	while ((ret = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[ret] = '\0';
		if (*ptr == NULL)
			*ptr = strdup(buffer);
		else
			*ptr = ft_strjoinfree(*ptr, buffer, 1, 0);
		if (*ptr == NULL)
			sp_enomem();
	}
	close(fd);
	if (ret < 0 || *ptr == NULL)
		return (ERRORF("Error while reading %s", filepath));
	return (0);
}

static int		sp_new_shader(char const *filepath, GLuint *handle, GLenum t
							  , char const *global)
{
	char	*text[1];
	GLint	len[1];

	*text = strdup(global);
	if (*text == NULL)
		ft_enomem();
	if (sp_load_shader(filepath, text))
		return (ERROR("sp_load_shader(...)"));
	*handle = glCreateShader(t);
	if (*handle == 0)
	{
		free(*text);
		return (ERRORF(BADCREATE_FMT, *handle));
	}
	*len = strlen(*text);
	glShaderSource(*handle, 1, (char const **)text, len);
	free(*text);
	glCompileShader(*handle);
	return (check_shader_error(*handle, GL_COMPILE_STATUS));
}

void			sp_delete_shaders(t_env *e)
{
	int		i;

	i = 0;
	while (i < sp_num_vshaders)
		glDeleteShader(e->vshaders[i++].handle);
	i = 0;
	while (i < sp_num_fshaders)
		glDeleteShader(e->fshaders[i++].handle);
	return ;
}


int				sp_init_shaders(t_env *e)
{
	size_t									i;
	struct s_env_shader_type const			*stype;
	struct s_env_shader_type const *const	end = END_ARRAY(g_shaders_types);
	void									*ptr;
	char									*global;

	global = NULL;
	if (sp_load_shader("srcs/shaders/global.glsl", &global))
		return (ERROR("Parsing global.glsl"));
	stype = g_shaders_types - 1;
	while (++stype < end)
	{
		i = -1;
		ptr = (void*)e + stype->env_offset;
		while (++i < stype->num_shaders)
		{
			if (sp_new_shader(*(char const**)(ptr + stype->filepath_offset)
								, ptr + stype->handle_offset
							  , stype->type, global))
				return (ERRORF("sp_new_shader(%s:%d)", stype->name, i));
			ptr += stype->struct_size;
		}
	}
	return (0);
}
