/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cog_meshfill1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 15:53:38 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/03 16:10:26 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "objmodel/objmodel.h"
#include <math.h>
#include <string.h>

/*
**  [[[cog
**  import cog
**  cog.outl("*" "/")
**  from confloader import output_meshfill
**  output_meshfill(0)
**  cog.out("/" "*")
**  ]]]
*/

int			sp_meshfill_main(t_mesh *me, t_vao_basic *vao)
{
	return (sp_meshfillbumb_objmodel(me, vao));
}

int			sp_meshfill_plane(t_mesh *me, t_vao_basic *vao)
{
	return (sp_meshfillbumb_objmodel(me, vao));
}

int			sp_meshfill_sun(t_mesh *me, t_vao_basic *vao)
{
	return (sp_meshfillbumb_objmodel(me, vao));
}

int			sp_meshfill_land(t_mesh *me, t_vao_basic *vao)
{
	sp_land_fill_mesh(sp_instance(), vao);
	return (0);
	(void)me;
}

/*
**  [[[end]]]
*/
