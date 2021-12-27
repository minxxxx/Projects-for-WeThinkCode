
#include "scop.h"
#include <limits.h>

static float const		g_sun_tess[][3] = {
	{2.000000f, 30.f, 15.f},
	{2.200000f, 28.f, 14.f},
	{2.500000f, 26.f, 13.f},
	{3.000000f, 24.f, 12.f},
	{4.000000f, 22.f, 11.f},
	{5.000000f, 20.f, 10.f},
	{6.000000f, 18.f, 9.f},
	{7.500000f, 16.f, 8.f},
	{10.00000f, 14.f, 7.f},
	{16.50000f, 12.f, 6.f},
	{25.00000f, 10.f, 5.f},
	{50.00000f, 8.0f, 4.f},
	{100.0000f, 6.0f, 3.f},
	{200.0000f, 4.0f, 2.f},
	{400.0000f, 2.0f, 2.f},
	{500.0000f, 2.0f, 1.f},
	{1.f / 0.f, 1.0f, 1.f}
};

void			sp_sunskin_update_autotess(t_env *e)
{
	int		i;
	float	dist;

	dist = v3_dist(e->sunpos_cartesian, e->cpos);
	i = 0;
	while (1)
	{
		if (dist < g_sun_tess[i][0])
		{
			e->sunskin_tessin = g_sun_tess[i][1];
			e->sunskin_tessout[0] = g_sun_tess[i][2];
			e->sunskin_tessout[1] = g_sun_tess[i][2];
			e->sunskin_tessout[2] = g_sun_tess[i][2];
			return ;
		}
		i++;
	}
	return ;
}

void			sp_sunskin_tessout(t_env *e, int action)
{
	float const	way = 1 - (action & 0x8 ? 2 : 0);

	if (action & 0x1)
	{
		e->sunskin_tessout[0] += way;
		if (e->sunskin_tessout[0] < 1.f)
			e->sunskin_tessout[0] = 1.f;
	}
	if (action & 0x2)
	{
		e->sunskin_tessout[1] += way;
		if (e->sunskin_tessout[1] < 1.f)
			e->sunskin_tessout[1] = 1.f;
	}
	if (action & 0x4)
	{
		e->sunskin_tessout[2] += way;
		if (e->sunskin_tessout[2] < 1.f)
			e->sunskin_tessout[2] = 1.f;
	}
	return ;
}

void			sp_sunskin_tessin(t_env *e, int way)
{
	e->sunskin_tessin += (float)way;
	if (e->sunskin_tessin < 1.f)
		e->sunskin_tessin = 1.f;
	return ;
}

void			sp_sunskin_toggle_autotess(t_env *e)
{
	if (e->sunskin_autotess)
		e->sunskin_autotess = false;
	else
	{
		e->sunskin_autotess = true;
		sp_sunskin_update_autotess(e);
	}
	return ;
}

void			sp_sunskin_scoll_colormode(t_env *e)
{
	e->sunskin_colormode = (e->sunskin_colormode) % 3 + 1;
	return ;
}
