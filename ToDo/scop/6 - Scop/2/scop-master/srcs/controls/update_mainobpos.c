/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mainobpos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 17:05:03 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 17:08:05 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scop.h"

#define HELD (sp_is_held | sp_control_held)
#define NOHELD (0)

#define COMPUTE(V) (V) & NOHELD ? 0 : (V)
#define GETSTATE(E, V) ((E)->keystates[(V)] ? 1 : 0)

static int		compute_key(t_env const *const e, int up, int d)
{
	up = e->keystates[up];
	d = e->keystates[d];
	if ((up & NOHELD) || !((up & HELD) == HELD))
		up = sp_not_held;
	else
		up = sp_is_held;
	if ((d & NOHELD) || !((d & HELD) == HELD))
		d = sp_not_held;
	else
		d = sp_is_held;
	return (up - d);
}

static void		updade_pos(t_env *e, float elms, t_bool *up, t_ob *ob)
{
	int const	mvx = compute_key(e, sp_a_key, sp_d_key);
	int const	mvy = compute_key(e, sp_space_key, sp_c_key);
	int const	mvz = compute_key(e, sp_w_key, sp_s_key);
	float const	nb = (float)(mvx * mvx + mvy * mvy + mvz * mvz);
	float		fact;

	if (mvx && (*up = true))
	{
		fact = elms / nb * (float)mvx;
		ob->position.z += sin(e->cangles[0] - (M_PI / 2)) * fact;
		ob->position.x += cos(e->cangles[0] - (M_PI / 2)) * fact;
	}
	if (mvz && (*up = true))
	{
		fact = elms / nb * (float)mvz;
		ob->position.z += sin(e->cangles[0]) * fact;
		ob->position.x += cos(e->cangles[0]) * fact;
	}
	if (mvy && (*up = true))
	{
		fact = elms / nb * (float)mvy;
		ob->position.y += fact;
	}
	return ;
}

void			sp_update_mainobpos(t_env *e)
{
	t_bool		up[1];

	updade_pos(e, (float)e->time_el * MOVEMENT_SPEEDF, up, e->mainob);
	if (*up)
		e->mainob->moved = true;
	return ;
}
