/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cog_loadconf3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 09:50:09 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/15 12:56:17 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <string.h>

int			sp_loadconf_options_mesh(t_env *e)
{
	t_options_mesh const	tmp = {

	{"res/teapot.obj", "res/teapot2.obj", "res/42.obj", "res/alfa147.obj",
	"res/cessna.obj", "res/tetrahedron.obj", "res/venice.obj"},
	{{NULL, "None"}, {&sp_groups_to_ebo_box, "Box"}},
	{{&sp_calc_uv_planaroxy, "Plan oxy"}
	, {&sp_calc_uv_spherical, "Spherical"}
	, {&sp_calc_uv_box, "Box"}}
	};
	memcpy(&e->options_mesh, &tmp, sizeof(tmp));
	return (0);
}
