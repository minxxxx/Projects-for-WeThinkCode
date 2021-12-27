/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obs_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 13:44:32 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/15 14:05:15 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <math.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define CONV(...) (t_ob[1]){__VA_ARGS__}
#define OB(T,...) push_ob(e,CONV(dob((T),NARG(__VA_ARGS__),##__VA_ARGS__)),0)
#define OBMN(T,...) push_ob(e,CONV(dob((T),NARG(__VA_ARGS__),##__VA_ARGS__)),1)

static size_t const		g_obdata[][2] =
{
	{offsetof(t_ob, hidden), sizeof(t_bool)},
	{offsetof(t_ob, moved), sizeof(t_bool)},
	{offsetof(t_ob, shadow), sizeof(t_bool)},
	{offsetof(t_ob, position), sizeof(t_vec3)},
	{offsetof(t_ob, rotation), sizeof(t_vec3)},
	{offsetof(t_ob, scale), sizeof(t_vec3)},
	{offsetof(t_ob, update), sizeof(void(*)())},
	{offsetof(t_ob, valf), sizeof(float[3])},
	{offsetof(t_ob, vali), sizeof(int[1])},
};

static void	push_ob(t_env *e, t_ob const *ob, t_bool ismain)
{
	t_ftlist	*vec;

	vec = e->obs + MEOFOB(e, ob)->program;
	if (ftl_push_back(vec, (t_ftlist_node const*)ob))
		sp_enomem();
	if (ismain)
		e->mainob = (t_ob*)vec->prev;
	return ;
}

static void	retreive_varg(va_list *ap, t_ob_param id, void *buf)
{
	if (id == ob_hid)
		(*(t_bool*)buf) = va_arg(*ap, t_bool);
	else if (id == ob_mov)
		(*(t_bool*)buf) = va_arg(*ap, t_bool);
	else if (id == ob_sha)
		(*(t_bool*)buf) = va_arg(*ap, t_bool);
	else if (id == ob_pos)
		(*(t_vec3*)buf) = va_arg(*ap, t_vec3);
	else if (id == ob_rot)
		(*(t_vec3*)buf) = va_arg(*ap, t_vec3);
	else if (id == ob_sca)
		(*(t_vec3*)buf) = va_arg(*ap, t_vec3);
	else if (id == ob_up)
		(*(void(**)())buf) = va_arg(*ap, void(*)());
	else if (id == ob_vf)
		memcpy(buf, va_arg(*ap, float*), sizeof(float) * 3);
	else if (id == ob_vi)
		memcpy(buf, va_arg(*ap, int*), sizeof(int) * 1);
	return ;
}

static t_ob	dob(t_model_index moi, int narg, ...)
{
	va_list		ap;
	t_ob		tmp;
	t_ob_param	paramid;
	t_byte		buf[sizeof(t_vec3)];

	tmp = sp_default_ob(moi);
	va_start(ap, narg);
	assert(narg % 2 == 0);
	while (narg >= 2)
	{
		paramid = va_arg(ap, t_ob_param);
		assert(paramid < ob_num_param);
		retreive_varg(&ap, paramid, buf);
		memcpy(((void*)&tmp) + g_obdata[paramid][0], buf, g_obdata[paramid][1]);
		narg -= 2;
	}
	va_end(ap);
	return (tmp);
}

int			sp_fill_obs(t_env *e)
{
	float	rad;
	int		dir;

	OBMN(sp_main_model, ob_pos, D_MAINOBPOS_V3, ob_rot, D_MAINOBANGLES_V3
	, ob_up, &sp_obupdate_mainob, ob_vi, ((int[1]){1}));
	OB(sp_land_model);
	OB(sp_sun_model, ob_up, &sp_obupdate_sun, ob_mov, false);
	rad = 45.f;
	while (rad < 500.f)
	{
		dir = 1 - rand() % 2 * 2;
		OB(sp_plane_model, ob_sca, OTOV3(0.5f), ob_up, &sp_obupdate_plane
		, ob_sha, false
		, ob_vi, ((int[1]){dir})
		, ob_vf
		, ((float[3]){M_PI * 2 * ft_randf01()
		, (float)dir * (0.1f + ft_randf01())
		, rad
		}));
		rad += 25.f * ft_randf01();
	}
	return (0);
}
