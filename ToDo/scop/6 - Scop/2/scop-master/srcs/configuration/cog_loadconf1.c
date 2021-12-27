/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cog_loadconf1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 15:53:55 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 13:09:42 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <string.h>

#define LOC(T, S) ((t_location){(T), (S)})
#define VSHADER(N,F,...) {VSHD_PATH(N), F, NARG(__VA_ARGS__), {__VA_ARGS__}, 0}
#define FSHADER(N, F) {FSHD_PATH(N), (F), 0}
#define GSHADER(N, F) {GSHD_PATH(N), (F), 0}
#define TCSHADER(N, F) {TCSHD_PATH(N), (F), 0}
#define TESHADER(N, F) {TESHD_PATH(N), (F), 0}

/*
**	[[[cog
**	import cog
**	cog.outl("*" "/")
**	from confloader import output_cconf1
**	output_cconf1()
**	cog.outl("/" "*")
**	]]]
*/
int			sp_loadconf_vshaders(t_env *e)
{
	t_vshader const		tmp[sp_num_vshaders] = {

	VSHADER("landrender.vert", &sp_unif_landvs,
	LOC(sp_tex_loc, 2)),
	VSHADER("poteno_to_uv.vert", &sp_unif_viewproj,
	LOC(sp_pos_loc, 3), LOC(sp_tex_loc, 2), LOC(sp_nor_loc, 3)),
	VSHADER("poIn_poOut_mvpTrans.vert", NULL,
	LOC(sp_pos_loc, 3)),
	VSHADER("po_to_noop_noviewproj.vert", NULL,
	LOC(sp_pos_loc, 3)),
	VSHADER("landsbox.vert", &sp_unif_landsbox,
	LOC(sp_tex_loc, 2)),
	VSHADER("po2_noop.vert", NULL,
	LOC(sp_pos_loc, 2)),
	};
	memcpy(&e->vshaders, &tmp, sizeof(tmp));
	return (0);
}

int			sp_loadconf_fshaders(t_env *e)
{
	t_fshader const		tmp[sp_num_fshaders] = {

	FSHADER("landrender.frag", &sp_unif_lightstruct),
	FSHADER("couvno_blendli.frag", &sp_unif_lightstruct),
	FSHADER("co_sun.frag", &sp_unif_sunfrag),
	FSHADER("depth01.frag", NULL),
	FSHADER("landgen_normals.frag", NULL),
	FSHADER("landgen_diag.frag", NULL),
	FSHADER("landgen_horiz.frag", NULL),
	FSHADER("landgen_notrel.frag", NULL),
	FSHADER("debug_print_sampler.frag", NULL),
	};
	memcpy(&e->fshaders, &tmp, sizeof(tmp));
	return (0);
}

int			sp_loadconf_gshaders(t_env *e)
{
	t_gshader const		tmp[sp_num_gshaders] = {

	GSHADER("pouvno_facegrey.geom", NULL),
	GSHADER("po_facegrey.geom", &sp_unif_sungeom),
	GSHADER("pos_to_cubemap.geom", NULL),
	GSHADER("landrender.geom", &sp_unif_landgeom),
	};
	memcpy(&e->gshaders, &tmp, sizeof(tmp));
	return (0);
}

int			sp_loadconf_tcshaders(t_env *e)
{
	t_tcshader const		tmp[sp_num_tcshaders] = {

	TCSHADER("test.tesc", &sp_unif_suntesc),
	TCSHADER("landrender.tesc", &sp_unif_landtesc),
	};
	memcpy(&e->tcshaders, &tmp, sizeof(tmp));
	return (0);
}

int			sp_loadconf_teshaders(t_env *e)
{
	t_teshader const		tmp[sp_num_teshaders] = {

	TESHADER("test.tese", NULL),
	TESHADER("landrender.tese", NULL),
	};
	memcpy(&e->teshaders, &tmp, sizeof(tmp));
	return (0);
}

/*
**	[[[end]]]
*/
