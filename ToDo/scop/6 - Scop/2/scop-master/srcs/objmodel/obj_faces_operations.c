/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_faces_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 13:49:05 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/03 11:39:26 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "objmodel/objmodel_parsing.h"

void	op_faces_decr_indices(t_ui b[9], int i, int end)
{
	while (i < end)
		b[i++]--;
	return ;
}

int		op_parse_uiblock(char const **buf, t_ui uibuf[9], int const *indices)
{
	int		i;
	char	*ptr[1];

	i = 0;
	while (1)
	{
		if (indices[i] == -1)
		{
			if (*(*buf)++ != '/')
				return (-1);
		}
		else if (indices[i] == -2)
			break ;
		else
		{
			uibuf[indices[i]] = (t_ui)strtoul(*buf, ptr, 10);
			if (*ptr == NULL)
				return (-1);
			if (*buf == *ptr)
				return (i == 0 ? 1 : -1);
			*buf = *ptr;
		}
		i++;
	}
	return (0);
}

t_bool	op_faces_indices_valid(t_objmodel const *m, t_ui const b[9])
{
	size_t	s;

	s = m->coords.size;
	if (b[0] > s || b[3] > s || b[6] > s)
		return (false);
	if (m->width == 5 || m->width == 8)
	{
		s = m->textures.size;
		if (b[1] > s || b[4] > s || b[7] > s)
			return (false);
	}
	if (m->width == 6 || m->width == 8)
	{
		s = m->normals.size;
		if (b[2] > s || b[5] > s || b[8] > s)
			return (false);
	}
	return (true);
}
