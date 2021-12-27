/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cog_enums.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 13:02:15 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/12 17:10:50 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COG_ENUMS_H
# define COG_ENUMS_H

/*
**  [[[cog
**  import cog
**  cog.outl("*" "/")
**  from confloader import output_enums
**  output_enums()
**  cog.out("/" "*")
**  ]]]
*/
typedef enum				e_vshader_index
{
	sp_landrender_vshader,
	sp_poteno_to_uv_vshader,
	sp_poin_poout_mvptrans_vshader,
	sp_po_to_noop_noviewproj_vshader,
	sp_landsbox_vshader,
	sp_po2_noop_vshader,
	sp_num_vshaders
}							t_vshader_index;

typedef enum				e_fshader_index
{
	sp_landrender_fshader,
	sp_couvno_blendli_fshader,
	sp_co_sun_fshader,
	sp_depth01_fshader,
	sp_landgen_normals_fshader,
	sp_landgen_diag_fshader,
	sp_landgen_horiz_fshader,
	sp_landgen_notrel_fshader,
	sp_debug_print_sampler_fshader,
	sp_num_fshaders
}							t_fshader_index;

typedef enum				e_gshader_index
{
	sp_face_grey_gshader,
	sp_po_facegrey_gshader,
	sp_pos_to_cubemap_gshader,
	sp_landrender_gshader,
	sp_num_gshaders,
	sp_no_gshader
}							t_gshader_index;

typedef enum				e_tcshader_index
{
	sp_test_tcshader,
	sp_landrender_tcshader,
	sp_num_tcshaders,
	sp_no_tcshader
}							t_tcshader_index;

typedef enum				e_teshader_index
{
	sp_test_teshader,
	sp_landrender_teshader,
	sp_num_teshaders,
	sp_no_teshader
}							t_teshader_index;

typedef enum				e_program_index
{
	sp_landrender_program,
	sp_sun_program,
	sp_pointshadow_program,
	sp_pointshadowland_program,
	sp_ptn_program,
	sp_landgen_normals_program,
	sp_landgen_diag_program,
	sp_landgen_horiz_program,
	sp_landgen_notrel_program,
	sp_debug_print_sampler_program,
	sp_num_programs
}							t_program_index;

typedef enum				e_texture_index
{
	sp_porcelain_texture,
	sp_wall_texture,
	sp_metal_texture,
	sp_num_textures,
	sp_no_texture
}							t_texture_index;

typedef enum				e_mesh_index
{
	sp_main_mesh,
	sp_plane_mesh,
	sp_sun_mesh,
	sp_land_mesh,
	sp_num_meshes
}							t_mesh_index;

typedef enum				e_model_index
{
	sp_main_model,
	sp_plane_model,
	sp_land_model,
	sp_sun_model,
	sp_num_models
}							t_model_index;

/*
**  [[[end]]]
*/

#endif
