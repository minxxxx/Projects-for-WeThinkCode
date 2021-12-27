/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 12:07:31 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/19 17:51:51 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# ifdef MAC_OS_MODE
#  define GLFW_INCLUDE_GLCOREARB
# else
#  include <GL/glew.h>
# endif

# include <GLFW/glfw3.h>

# include "libft.h"
# include "ft_timeval.h"

# include "ftmath.h"
# include "configuration/scop_conf.h"
# include "scop_types.h"
# include "configuration/cog_meshfill.h"
# include "fterror.h"
# include "objmodel/objmodel.h"

# define sp_enomem ft_enomem	// to fix at home

/*
** DEBUG
*/
# include "ft_debug.h"
# define DEBUG(ARG) qprintf("%s\n", (ARG))
# define DEBUGF(...) qprintf(__VA_ARGS__), ft_putchar_fd('\n', 2)
void        sp_debug_putquad_screencoord(t_vec2i topright);
void        sp_debug_puttexture2d(t_env const *e, t_texture const *t);

/*
** REDUNDANT MACROES
*/
# define UNIFLOC_(P, N)  glGetUniformLocation((P)->handle, N)
# define UNIFPREFIX_(T) glUnifor ## T
# define UNIF(P, T, N, ...) UNIFPREFIX_(T)(UNIFLOC_(P, N), __VA_ARGS__)

/*
** PROTOTYPES
*/
/*
** CONTROLS
*/
void		sp_toggle_mouse_state(t_env *e);
void		sp_keystate(t_env *e, int a, t_keystate newstate);
void		sp_keyevent(t_env *e, int a, t_keystate keystate);
void		sp_keymodrelease(t_env *e, t_keystate keystate);
void		sp_update_states(t_env *e);
void		sp_update_campos(t_env *e, t_bool force);
void		sp_update_sunpos(t_env *e, t_bool force);
void		sp_update_sunrot(t_env *e, t_bool force);
void		sp_update_mainobpos(t_env *e);
void		sp_kevent_toggle_mouse_state(t_env *e);
void		sp_kevent_mix_item(t_env *e, int direction);
void		sp_kevent_reset_campos(t_env *e);

/*
** ENV
*/
void		sp_clean_env(t_env *e);
int			sp_init_env(t_env *e);
t_env		*sp_instance(void);

int			sp_loadconf_vshaders(t_env *e);
int			sp_loadconf_fshaders(t_env *e);
int			sp_loadconf_gshaders(t_env *e);
int			sp_loadconf_tcshaders(t_env *e);
int			sp_loadconf_teshaders(t_env *e);
int			sp_loadconf_programs(t_env *e);
int			sp_loadconf_textures(t_env *e);
int			sp_loadconf_meshes(t_env *e);
int			sp_loadconf_models(t_env *e);
int			sp_loadconf_options_mesh(t_env *e);

void		sp_timings_init(t_env *e);
void		sp_timings_update(t_env *e);
void		sp_timings_handle_nofocus(t_env *e);

/*
** GLFW
*/
void		sp_disable_glfw(t_env *e);
int			sp_init_glfw(t_env *e);

/*
** SHADERS
*/
void		sp_delete_shaders(t_env *e);
int			sp_init_shaders(t_env *e);
t_byte		sp_location_size(t_vshader const *vs, enum e_location_type type);
t_byte		sp_locations_nbytes(t_vshader const *vs);

/*
** PROGRAMS
*/
void		sp_delete_programs(t_env *e);
int			sp_init_programs(t_env *e);

/*
** TEXTURES
*/
int			sp_init_textures(t_env *e);
void		sp_delete_textures(t_env *e);
int			parse_tga(char const *filepath, t_ftvector *v, t_ui dim[2]);
void		sp_activate_texture(t_program const *p, t_texslot texslot
								, t_texture const *t, char const *unifname);

/*
** MESHES
*/
void		sp_delete_meshes(t_env *e);
int			sp_refresh_vbo(t_env const *e, t_mesh const *me);
int			sp_meshfillbumb_objmodel(t_mesh *me, t_vao_basic *vao);

/*
** MESHES CREATION
*/
int			sp_init_meshes(t_env *e);
int			sp_new_mesh(t_env const *e, t_mesh *me);
int			sp_vao_primary_build(t_mesh const *me, t_vao_basic *vao);
void		sp_vao_secondary_build(t_env const *e, t_mesh const *me
								   , t_vao_basic *vao, t_vshader const *vs);
void		sp_vao_final_build(t_ftvector vbo_final[1], t_ftvector ebo_final[1]
								, t_vao_basic const vao[1]);
void		sp_vao_final_push(t_mesh *me, t_vshader const *vs
								, t_ftvector const vbo_final[1]
								, t_ftvector const ebo_final[1]);
/*
** MESHES CREATION PROCESSING FIXED
*/
void		sp_recenter_positions(t_vbo_basic *vbo);
void		sp_rebuild_vbo_from_groups(t_vao_basic *vao);
void		sp_normals_to_ebo(t_vao_basic *vao);
void		sp_normals_to_vbo(t_vao_basic *vao);
void        sp_transpose_ebo(t_transp_ebo tebo[1], t_vao_basic const vao[1]);
void		sp_vbo_normals_restore(t_ftvector *dst, t_ftvector const *src);
/*
** MESHES CREATION PROCESSING CUSTOM
*/
void		sp_calc_uv_spherical(t_mesh const *me, t_vertex_basic *vertex);
void		sp_calc_uv_planaroxy(t_mesh const *me, t_vertex_basic *vertex);
void		sp_calc_uv_box(t_mesh const *me, t_vertex_basic *vertex);
void		sp_groups_to_ebo_box(t_vao_basic *vao);

/*
** MAIN OB HANDLING
*/
void		sp_mainob_changemodel(t_env *e, t_model_index moi);
void		sp_mainob_resetpos(t_env *e);
void        sp_mainme_scroll_objfile(t_env *e, int v); //ranger
void    sp_mainme_toggle_recenter(t_env *e, int v);
void    sp_mainme_scroll_ebogrouping(t_env *e, int v);
void    sp_mainme_toggle_ebogroupingbefore(t_env *e, int v);//ranger aussi jusquici
void    sp_mainme_scroll_texwrapping(t_env *e, int v);
void    sp_mainme_change_texscale(t_env *e, int v);

/*
** SUNSKIN
*/
void            sp_sunskin_tessout(t_env *e, int action);
void            sp_sunskin_tessin(t_env *e, int way);
void			sp_sunskin_update_autotess(t_env *e);
void			sp_sunskin_toggle_autotess(t_env *e);
void			sp_sunskin_scoll_colormode(t_env *e);

/*
** LAND GENERATION
*/
int			sp_init_land(t_env *e);
void		sp_fill_landgrid(t_ftvector *lines);
void		sp_fill_landvertices(t_ftvector const *lines, t_vbo_basic *vbo,
	float bounds[2]);
void		sp_fill_landfaces(t_ftvector const *lines, t_ftvector *vertices);
void		sp_fill_landrgb(t_vbo_basic *vbo, float const bounds[2]);
void		sp_land_fill_mesh(t_env const *e, t_vao_basic *vao);

/*
** UNIFORMS
*/
void		sp_unif_model(t_env const *e, t_ob const *ob);
void		sp_unif_model_mix(t_env const *e, t_ob const *ob);
void		sp_unif_land(t_env const *e, t_ob const *ob);
void		sp_unif_viewproj(t_env const *e, t_program const *p);
void		sp_unif_viewproj2(t_env const *e, t_program const *p);
void		sp_unif_light(t_env const *e, t_program const *p);
void		sp_unif_lightstruct(t_env const *e, t_program const *p);
void		sp_unif_sunfrag(t_env const *e, t_program const *p);
void		sp_unif_suntesc(t_env const *e, t_program const *p);
void		sp_unif_sungeom(t_env const *e, t_program const *p);

void		sp_unif_landfs(t_env const *e, t_program const *p);
void		sp_unif_landsbox(t_env const *e, t_program const *p);
void		sp_unif_landvs(t_env const *e, t_program const *p);
void		sp_unif_landgeom(t_env const *e, t_program const *p);
void		sp_unif_landtesc(t_env const *e, t_program const *p);

/*
** OBS (OBJECTS)
*/
int			sp_init_obs(t_env *e);
void		sp_delete_obs(t_env *e);
void		sp_update_obs(t_env *e);
void		sp_render_obs(t_env const *e);
int			sp_fill_obs(t_env *e);
void		sp_obupdate_sun(t_env const *e, t_ob *ob);
void		sp_obupdate_mainob(t_env const *e, t_ob *ob);
void		sp_obupdate_plane(t_env const *e, t_ob *ob);
t_bool		sp_ob_getnot_hidden(t_env const *e, t_ob const *ob);
t_bool		sp_ob_get_moved(t_env const *e, t_ob const *ob);
t_bool		sp_ob_get_shadow(t_env const *e, t_ob const *ob);
t_ob		sp_default_ob(t_model_index moi);

/*
** SHADOW BOX
*/
int			sp_init_sbox(t_env *e);
void		sp_render_sbox(t_env const *e);
#endif
