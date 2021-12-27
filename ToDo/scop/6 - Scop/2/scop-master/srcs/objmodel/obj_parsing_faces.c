/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parsing_faces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 10:12:13 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/15 13:25:20 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "objmodel/objmodel_parsing.h"

static int	parse_width3(t_objmodel *m, char const *buf)
{
	t_ui	uibuf[9];
	int		ret;

	op_parse_uiblock(&buf, uibuf, (int[]){0, 3, 6, -2});
	op_faces_decr_indices(uibuf, 0, 9);
	if (!op_faces_indices_valid(m, uibuf))
		return (1);
	op_insert_face(m, uibuf);
	while (1)
	{
		uibuf[3] = uibuf[6];
		ret = op_parse_uiblock(&buf, uibuf, (int[]){6, -2});
		if (ret == -1)
			return (1);
		else if (ret == 1)
			break ;
		op_faces_decr_indices(uibuf, 6, 7);
		if (!op_faces_indices_valid(m, uibuf))
			return (1);
		op_insert_face(m, uibuf);
	}
	return (0);
}

static int	parse_width5(t_objmodel *m, char const *buf)
{
	t_ui	uibuf[9];

	(void)m;
	(void)buf;
	(void)uibuf;
	return (0);
}

static int	parse_width6(t_objmodel *m, char const *buf)
{
	t_ui	uibuf[9];

	(void)m;
	(void)buf;
	(void)uibuf;
	return (0);
}

static int	parse_width8(t_objmodel *m, char const *buf)
{
	t_ui	uibuf[9];
	int		ret;

	op_parse_uiblock(&buf, uibuf, (int[]){0, -1, 1, -1, 2,
				3, -1, 4, -1, 5,
				6, -1, 7, -1, 8, -2});
	op_faces_decr_indices(uibuf, 0, 9);
	if (!op_faces_indices_valid(m, uibuf))
		return (1);
	op_insert_face(m, uibuf);
	while (1)
	{
		memmove(uibuf + 3, uibuf + 6, sizeof(t_ui) * 3);
		ret = op_parse_uiblock(&buf, uibuf, (int[]){6, -1, 7, -1, 8, -2});
		if (ret == -1)
			return (1);
		else if (ret == 1)
			break ;
		op_faces_decr_indices(uibuf, 6, 9);
		if (!op_faces_indices_valid(m, uibuf))
			return (1);
		op_insert_face(m, uibuf);
	}
	return (0);
}

int			op_match_f(t_objmodel *m, char const *buf)
{
	static int		(*fun)(t_objmodel *m, char const *buf) = NULL;

	if (m->width == 0)
	{
		op_init_meshvectors(m);
		if (m->width == 3)
			fun = &parse_width3;
		else if (m->width == 5)
			fun = &parse_width5;
		else if (m->width == 6)
			fun = &parse_width6;
		else if (m->width == 8)
			fun = &parse_width8;
	}
	return (fun(m, buf));
}
