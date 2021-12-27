/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obs_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 13:49:29 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 15:54:32 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <math.h>

/*
** float[0] = angle
** float[1] = elapsed fact
** float[3] = radius
*/

void		sp_obupdate_plane(t_env const *e, t_ob *ob)
{
	ob->valf[0] += (float)e->time_el * ob->valf[1];
	ob->position = v3_add(
		PLANES_CENTER_V3
		, ATOV3(-sin(ob->valf[0]) * ob->valf[2]
		, 0.f, -cos(ob->valf[0]) * ob->valf[2]))
	;
	if (ob->vali[0] > 0)
	{
		ob->rotation.y = ob->valf[0];
		ob->rotation.z = 30.f / ob->valf[2];
	}
	else
	{
		ob->rotation.y = ob->valf[0] + M_PI;
		ob->rotation.z = -30.f / ob->valf[2];
	}
	ob->moved = true;
	return ;
}

void		sp_obupdate_mainob(t_env const *e, t_ob *ob)
{
	if (ob->vali[0] > 0)
	{
		ob->valf[0] += e->time_el / 2;
		if (ob->valf[0] > 1.f)
		{
			ob->vali[0] = 0;
			ob->valf[0] = 1.f;
		}
	}
	else if (ob->vali[0] < 0)
	{
		ob->valf[0] -= e->time_el / 2;
		if (ob->valf[0] < 0.f)
		{
			ob->vali[0] = 0;
			ob->valf[0] = 0.f;
		}
	}
	return ;
}

void		sp_obupdate_sun(t_env const *e, t_ob *ob)
{
	ob->mat = m4_translate_nonuniform(e->sunpos_cartesian);
	ob->mat = m4_rotationref_axis(&ob->mat, y_axis, e->sunskin_rot);
	return ;
}
