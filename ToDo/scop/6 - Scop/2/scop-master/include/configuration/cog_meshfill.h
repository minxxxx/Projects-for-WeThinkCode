/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cog_meshfill.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 13:03:26 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/10 13:15:56 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COG_MESHFILL_H
# define COG_MESHFILL_H

/*
**  [[[cog
**  import cog
**  cog.outl("*" "/")
**  from confloader import output_meshfill_prototypes
**  output_meshfill_prototypes()
**  cog.out("/" "*")
**  ]]]
*/
int		sp_meshfill_main(t_mesh *me, t_vao_basic *vao);
int		sp_meshfill_plane(t_mesh *me, t_vao_basic *vao);
int		sp_meshfill_sun(t_mesh *me, t_vao_basic *vao);
int		sp_meshfill_land(t_mesh *me, t_vao_basic *vao);
/*
**  [[[end]]]
*/

#endif
