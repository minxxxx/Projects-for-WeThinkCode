/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sunpos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 17:03:11 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 17:03:12 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <math.h>
#include "scop.h"

#define SPH(E) ((E)->sunpos_spherical)
#define RADIUS(E) SPH((E)).x
#define THETA(E) SPH((E)).y
#define PHI(E) SPH((E)).z

#define CAR(E) ((E)->sunpos_cartesian)

#define GETSTATE(E, V) ((E)->keystates[(V)] ? 1 : 0)
#define BASICCOMPUTE(E, U, D) (GETSTATE((E), (U)) - GETSTATE((E), (D)))

static void				update_radius(t_env *e, t_bool *update)
{
	int const	mvr = BASICCOMPUTE(e, sp_minus_key, sp_equal_key);

	if (mvr)
	{
		*update = true;
		RADIUS(e) += e->time_el * SUN_RSPEED * (float)mvr;
	}
	return ;
}

static void				update_inclination(t_env *e, t_bool *update)
{
	int const	mvt = BASICCOMPUTE(e, sp_l_key, sp_apos_key);

	if (mvt)
	{
		*update = true;
		THETA(e) += e->time_el * SUN_ASPEED * (float)mvt;
	}
	return ;
}

static void				update_azimuth(t_env *e, t_bool *update)
{
	int const	mvp = BASICCOMPUTE(e, sp_p_key, sp_semico_key);

	if (mvp)
	{
		*update = true;
		PHI(e) += e->time_el * SUN_ASPEED * (float)mvp;
	}
	return ;
}

static inline t_mat4	shadow_viewproj(t_env const *const e
										, t_vec3 const view_vec
										, t_vec3 const up_vec)
{
	return (m4_dotprod(&e->sbox_proj, (t_mat4[]){
	m4_lookat(e->sunpos_cartesian
	, v3_add(e->sunpos_cartesian, view_vec)
	, up_vec)}));
}

void					sp_update_sunpos(t_env *e, t_bool force)
{
	t_bool	update;

	update = false;
	update_radius(e, &update);
	update_inclination(e, &update);
	update_azimuth(e, &update);
	if (update || force)
	{
		if (RADIUS(e) < SUN_RBOUNDF)
			RADIUS(e) = SUN_RBOUNDF;
		CAR(e).x = RADIUS(e) * sin(PHI(e)) * cos(THETA(e));
		CAR(e).z = RADIUS(e) * sin(PHI(e)) * sin(THETA(e));
		CAR(e).y = RADIUS(e) * cos(PHI(e));
		memcpy(&e->sbox_viewproj, ((t_mat4[6]){
			shadow_viewproj(e, ATOV3(+1.0, 0.0, 0.0), ATOV3(0.0, -1.0, 0.0)),
			shadow_viewproj(e, ATOV3(-1.0, 0.0, 0.0), ATOV3(0.0, -1.0, 0.0)),
			shadow_viewproj(e, ATOV3(0.0, +1.0, 0.0), ATOV3(0.0, 0.0, +1.0)),
			shadow_viewproj(e, ATOV3(0.0, -1.0, 0.0), ATOV3(0.0, 0.0, -1.0)),
			shadow_viewproj(e, ATOV3(0.0, 0.0, +1.0), ATOV3(0.0, -1.0, 0.0)),
			shadow_viewproj(e, ATOV3(0.0, 0.0, -1.0), ATOV3(0.0, -1.0, 0.0))
		}), sizeof(e->sbox_viewproj));
		if (e->sunskin_autotess)
			sp_sunskin_update_autotess(e);
	}
	return ;
}
