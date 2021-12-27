/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unif_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 09:01:30 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/19 18:16:05 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			sp_unif_model(t_env const *e, t_ob const *ob)
{
	t_program const	*p = POFOB(e, ob);

	UNIF(p, mMatrix4fv, "model", 1, GL_TRUE, (float*)&ob->mat);
	return ;
}

void			sp_unif_model_mix(t_env const *e, t_ob const *ob)
{
	t_program const	*p = POFOB(e, ob);

	UNIF(p, mMatrix4fv, "model", 1, GL_TRUE, (float*)&ob->mat);
	UNIF(p, m1f, "mixval", ob->valf[0]);
	return ;
}

void			sp_unif_viewproj2(t_env const *e, t_program const *p)
{
	UNIF(p, mMatrix4fv, "view", 1, GL_TRUE, (float*)&e->view);
	UNIF(p, mMatrix4fv, "projection", 1, GL_TRUE, (float*)&e->projection);
	return ;
}

void			sp_unif_viewproj(t_env const *e, t_program const *p)
{
	UNIF(p, mMatrix4fv, "viewproj", 1, GL_TRUE, (float*)&e->viewproj);
	return ;
}

void			sp_unif_sunfrag(t_env const *e, t_program const *p)
{
	UNIF(p, m3fv, "sunColor", 1, (float*)&e->suncolor);
	UNIF(p, m1i, "colorUsing", 3); //color using
	return ;
}

void			sp_unif_suntesc(t_env const *e, t_program const *p)
{
	UNIF(p, m1f, "tessLevelIn", e->sunskin_tessin);
	UNIF(p, m1f, "tessLevelOut0", e->sunskin_tessout[0]);
	UNIF(p, m1f, "tessLevelOut1", e->sunskin_tessout[1]);
	UNIF(p, m1f, "tessLevelOut2", e->sunskin_tessout[2]);
	return ;
}

void			sp_unif_sungeom(t_env const *e, t_program const *p)
{
	UNIF(p, mMatrix4fv, "viewproj", 1, GL_TRUE, (float*)&e->viewproj);
	UNIF(p, m1i, "colorUsing", e->sunskin_colormode);
	return ;
}

void			sp_unif_landfs(t_env const *e, t_program const *p)
{
	(void)e;
	(void)p;
	return ;
}

void			sp_unif_landvs(t_env const *e, t_program const *p)
{
	(void)e;
	(void)p;
	return ;
}

void			sp_unif_landtesc(t_env const *e, t_program const *p)
{
	UNIF(p, m3fv, "vCamPos", 1, (float*)&e->cpos);
	UNIF(p, m1f, "dRangeTess", e->land_d_range_tess);
	UNIF(p, m1f, "tessLevelInRange", e->land_tesslevelin_range);
	(void)e;
	(void)p;
	return ;
}

void			sp_unif_landgeom(t_env const *e, t_program const *p)
{
	UNIF(p, mMatrix4fv, "viewproj", 1, GL_TRUE, (float*)&e->viewproj);
	UNIF(p, m3fv, "posfactors", 1, (float*)&LAND_COORDFACT);
	(void)e;
	(void)p;
	return ;
}

void			sp_unif_landsbox(t_env const *e, t_program const *p)
{
	UNIF(p, m3fv, "posfactors", 1, (float*)&LAND_COORDFACT);
	sp_activate_texture(p, sp_image1_texslot, &e->land_tex1, "ymap");
	(void)e;
	(void)p;
	return ;
}
