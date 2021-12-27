/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_campos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 17:03:28 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/25 14:56:07 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <math.h>
#include "scop.h"

#define HELD (sp_is_held)
#define NOHELD (sp_control_held)

#define COMPUTE(V) (V) & NOHELD ? 0 : (V)
#define GETSTATE(E, V) ((E)->keystates[(V)] ? 1 : 0)
#define BASICCOMPUTE(E, U, D) (GETSTATE((E), (U)) - GETSTATE((E), (D)))

static int		compute_key(t_env const *const e, int up, int d)
{
	up = e->keystates[up];
	d = e->keystates[d];
	if ((up & NOHELD) || !(up & HELD))
		up = sp_not_held;
	else
		up = 1;
	if ((d & NOHELD) || !(d & HELD))
		d = sp_not_held;
	else
		d = 1;
	return (up - d);
}

static void		updade_pos(t_env *e, float elms, t_bool *up)
{
	int const	mvx = compute_key(e, sp_a_key, sp_d_key);
	int const	mvy = compute_key(e, sp_space_key, sp_c_key);
	int const	mvz = compute_key(e, sp_w_key, sp_s_key);
	float const	nb = (float)(mvx * mvx + mvy * mvy + mvz * mvz);
	float		fact;

	if (mvx && (*up = true))
	{
		fact = elms / nb * (float)mvx;
		e->cpos.z += sin(e->cangles[0] - (M_PI / 2)) * fact;
		e->cpos.x += cos(e->cangles[0] - (M_PI / 2)) * fact;
	}
	if (mvz && (*up = true))
	{
		fact = elms / nb * (float)mvz;
		e->cpos.z += sin(e->cangles[0]) * fact;
		e->cpos.x += cos(e->cangles[0]) * fact;
	}
	if (mvy && (*up = true))
	{
		fact = elms / nb * (float)mvy;
		e->cpos.y += fact;
	}
	return ;
}

static void		update_angles_mouse(t_env *e, t_bool *up)
{
	double		mpos[2];

	*up = true;
	glfwGetCursorPos(e->win, mpos, mpos + 1);
	e->cangles[0] += (mpos[0] - e->mpos[0]) * MOUSE_SENSITIVITYF;
	e->cangles[1] -= (mpos[1] - e->mpos[1]) * MOUSE_SENSITIVITYF;
	memcpy(e->mpos, mpos, sizeof(mpos));
	return ;
}

static void		update_angles_keyboard(t_env *e, t_bool *up)
{
	int const	mvya = BASICCOMPUTE(e, sp_right_key, sp_left_key);
	int const	mvpi = BASICCOMPUTE(e, sp_up_key, sp_down_key);

	if (mvya)
	{
		*up = true;
		e->cangles[0] += 1.0 * mvya / (float)(mvpi * mvpi + 1) * e->time_el;
	}
	if (mvpi)
	{
		*up = true;
		e->cangles[1] += 1.0 * mvpi / (float)(mvya * mvya + 1) * e->time_el;
	}
	return ;
}

void			sp_update_campos(t_env *e, t_bool force)
{
	t_bool	update;

	update = false;
	if (glfwGetInputMode(e->win, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
		update_angles_mouse(e, &update);
	update_angles_keyboard(e, &update);
	updade_pos(e, (float)e->time_el * MOVEMENT_SPEEDF, &update);
	if (update || force)
	{
		if (e->cangles[1] > CAMERA_POSBOUNDF)
			e->cangles[1] = CAMERA_POSBOUNDF;
		else if (e->cangles[1] < -CAMERA_POSBOUNDF)
			e->cangles[1] = -CAMERA_POSBOUNDF;
		e->view = m4_lookat(e->cpos,
		v3_add(e->cpos, v3_frontnormed(e->cangles)), ATOV3(0.f, 1.f, 0.f));
		e->viewproj = m4_dotprod(&e->projection, &e->view);
		if (e->sunskin_autotess)
			sp_sunskin_update_autotess(e);
	}
	return ;
}
