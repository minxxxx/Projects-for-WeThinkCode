/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_dumb_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 14:36:32 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/03 18:36:10 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			sp_meshfillbumb_objmodel(t_mesh *me, t_vao_basic *vao)
{
	t_objmodel				m[1];

	if (op_parse_obj(m, ME_OBJFILESTR(sp_instance(), me)))
		return (ERROR("op_parse_obj(m)"));
	op_retreive_data(m, vao);
	sp_clean_objmodel(m);
	return (0);
}
