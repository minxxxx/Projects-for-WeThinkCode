/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parsing_floats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 17:32:29 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/03 11:40:43 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "objmodel/objmodel_parsing.h"

static void	push_floats(t_ftvector *v, float const fbuf[3])
{
	if (ftv_push_back(v, fbuf))
		sp_enomem();
	return ;
}

int			op_match_v(t_objmodel *m, char const *buf)
{
	float		fbuf[3];
	int			i;

	i = 0;
	while (i < 3)
	{
		fbuf[i++] = (float)strtod(buf, (char**)&buf);
		if (buf == NULL)
			return (ERROR("Error parsing v"));
	}
	push_floats(&m->coords, fbuf);
	return (0);
}

int			op_match_vt(t_objmodel *m, char const *buf)
{
	float		fbuf[3];
	int			i;

	i = 0;
	while (i < 2)
	{
		fbuf[i++] = strtod(buf, (char**)&buf);
		if (buf == NULL)
			return (ERROR("Error parsing vt"));
	}
	push_floats(&m->textures, fbuf);
	return (0);
}

int			op_match_vn(t_objmodel *m, char const *buf)
{
	float		fbuf[3];
	int			i;

	i = 0;
	while (i < 3)
	{
		fbuf[i++] = strtod(buf, (char**)&buf);
		if (buf == NULL)
			return (ERROR("Error parsing vn"));
	}
	push_floats(&m->normals, fbuf);
	return (0);
}
