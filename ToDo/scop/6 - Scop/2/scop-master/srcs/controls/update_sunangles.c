
#include "scop.h"

#define GETSTATE(E, V) ((E)->keystates[(V)] ? 1 : 0)
#define BASICCOMPUTE(E, U, D) (GETSTATE(E, U) - GETSTATE(E, D))

static void		update_angle(t_env e[1])
{
	int const	mv = BASICCOMPUTE(e, sp_i_key, sp_o_key);

	
	if (mv)
	{
		e->sunskin_rot += SUN_ROTSPEED * e->time_el * (float)mv;
	}
	return ;
}

void			sp_update_sunrot(t_env *e, t_bool force)
{
	update_angle(e);
	return ;
	(void)force;
}
