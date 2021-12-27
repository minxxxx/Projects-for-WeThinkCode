/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 10:07:19 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/19 18:16:08 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_TYPES_H
# define SCOP_TYPES_H

# include "libft.h"

# ifdef MAC_OS_MODE
#  define GLFW_INCLUDE_GLCOREARB
# else
#  include <GL/glew.h>
# endif

# include <GLFW/glfw3.h>
# include "ft_vector.h"
# include "ft_list.h"
# include "configuration/scop_conf.h"
# include "meshes/vao.h"

/*
** LAND
*/
typedef struct					s_land_tmp
{
	int							grid_npoints;
	int							grid_width;
	GLuint						fbo_handle[1];
	GLuint						vao_handle[1];
	GLuint						vbo_handle[1];
	GLuint						ytex_handle[1];
	GLuint						coltex_handle[1];
	GLuint						fbo2_handle[1];
	GLuint						nortex_handle[1];
}								t_land_tmp;

/*
** KEYS
*/
typedef enum					e_keyindex
{
	sp_w_key,
	sp_s_key,
	sp_a_key,
	sp_d_key,
	sp_space_key,
	sp_c_key,
	sp_up_key,
	sp_down_key,
	sp_left_key,
	sp_right_key,
	sp_p_key,
	sp_semico_key,
	sp_l_key,
	sp_apos_key,
	sp_minus_key,
	sp_equal_key,
	sp_i_key,
	sp_o_key,
	sp_num_keys
}								t_keyindex;
typedef enum					e_keystate
{
	sp_not_held = 0,
	sp_is_held = 1,
	sp_shift_held = 2,
	sp_control_held = 4,
	sp_alt_held = 8,
	sp_super_held = 16,
}								t_keystate;
enum							e_stateindex
{
	sp_window_focused_state,
	sp_num_states
};
typedef struct					s_keyevents
{
	void						(*fun)();
	int							dat;
	int							key;
	t_keystate					held;
	t_keystate					noheld;
}								t_keyevents;
/*
** Updating uniforms:
** 	A shader defines some updates from scop's env.
**	A model  defines some updates from scop's env + a given t_ob.
*/

/*
** SHADERS
** A shader is tied to several <program>
*/
typedef struct					s_vshader
{
	char const					*filepath;
	void						(*const unif_update)();
	size_t const				n_locations;
	t_location const			locations[4];
	GLuint						handle;
}								t_vshader;
typedef struct					s_fshader
{
	char const					*filepath;
	void						(*const unif_update)();
	GLuint						handle;
}								t_fshader;
typedef struct					s_gshader
{
	char const					*filepath;
	void						(*const unif_update)();
	GLuint						handle;
}								t_gshader;
typedef struct					s_tcshader
{
	char const					*filepath;
	void						(*const unif_update)();
	GLuint						handle;
}								t_tcshader;
typedef struct					s_teshader
{
	char const					*filepath;
	void						(*const unif_update)();
	GLuint						handle;
}								t_teshader;

/*
** TEXTURE
** A texture is tied to several <model>
*/
typedef struct					s_texture
{
	char const					*filepath;
	GLenum const				target;
	t_ui						dim[2];
	GLuint						handle;
}								t_texture;
typedef enum					e_texslot
{
	sp_image1_texslot,
	sp_image2_texslot,
	sp_image3_texslot,
	sp_sbox_texslot,
	sp_num_texslots,
}								t_texslot;

/*
** PROGRAMS
** A program is tied to several <mesh>
*/
typedef struct					s_program
{
	t_vshader_index const		vshader;
	t_fshader_index const		fshader;
	t_gshader_index const		gshader;
	t_tcshader_index const		tcshader;
	t_teshader_index const		teshader;
	t_program_index const		sboxprogram;
	int const					gltexi[sp_num_texslots];
	GLuint						handle;
}								t_program;

/*
** MESH
** A mesh is tied to several <model>
*/
enum							e_objfile
{
	sp_teapot1_objfile,
	sp_teapot2_objfile,
	sp_ft_objfile,
	sp_alfa_objfile,
	sp_cessna_objfile,
	sp_dodecahedron_objfile,
	sp_csie_objfile,
	sp_num_objfiles,
};
enum							e_ebogrouping
{
	sp_no_ebogrouping,
	sp_box_ebogrouping,
	sp_num_ebogroupings,
};
enum							e_texwrapping
{
	sp_oxy_texwrapping,
	sp_spherical_texwrapping,
	sp_box_texwrapping,
	sp_num_texwrappings,
};

typedef struct					s_option_mesh_ebogrouping
{
	void						(*const fun)();
	char const *const			str;
}								t_option_mesh_ebogrouping;
typedef struct					s_option_mesh_texwrapping
{
	void						(*const fun)();
	char const *const			str;
}								t_option_mesh_texwrapping;
typedef struct					s_options_mesh
{
	char const					*objfiles[sp_num_objfiles];
	t_option_mesh_ebogrouping	ebogroupings[sp_num_ebogroupings];
	t_option_mesh_texwrapping	texwrappings[sp_num_texwrappings];
}								t_options_mesh;
# define ME_TEXWRAPFUN(E, ME) E->options_mesh.texwrappings[ME->texwrapping].fun
# define ME_EBOGRPFUN(E, ME) E->options_mesh.ebogroupings[ME->ebogrouping].fun
# define ME_OBJFILESTR(E, ME) E->options_mesh.objfiles[ME->objfile]

typedef struct					s_mesh
{
	GLenum const				usage;
	t_program_index const		program;
	enum e_objfile				objfile;
	int							(*primary_fill)();
	t_bool						recenter_positions;
	enum e_ebogrouping			ebogrouping;
	t_bool						vertices_normals_before_split;
	enum e_texwrapping			texwrapping;
	float						tex_scale[2];

	size_t						faces3;
	GLuint						handles[3];
	t_bool						generated;
}								t_mesh;

/*
** MODEL
** A model is tied to several <ob>
*/
typedef struct					s_model
{
	t_mesh_index				mesh;
	t_texture_index				texture;
	void						(*update_uniforms)();
}								t_model;

/*
** OB (object)
*/
typedef struct					s_ob
{
	t_ftlist_node				list;
	t_bool						hidden;
	t_bool						moved;
	t_bool						shadow;
	t_bool						delete;
	t_model_index				model;
	t_vec3						position;
	t_vec3						rotation;
	t_vec3						scale;
	t_mat4						mat;
	void						(*update)();
	float						valf[3];
	int							vali[1];
}								t_ob;
typedef enum					e_ob_param
{
	ob_hid,
	ob_mov,
	ob_sha,
	ob_pos,
	ob_rot,
	ob_sca,
	ob_up,
	ob_vf,
	ob_vi,
	ob_main,
	ob_num_param,
}								t_ob_param;

/*
** ENV
*/
struct							s_env_shader_type
{
	GLenum						type;
	char						*name;
	size_t						num_shaders;
	size_t						env_offset;
	size_t						struct_size;
	size_t						filepath_offset;
	size_t						handle_offset;
};
typedef struct					s_env
{ //todo, mettre des const partout
	GLFWwindow					*win;

	t_vshader					vshaders[sp_num_vshaders];
	t_fshader					fshaders[sp_num_fshaders];
	t_gshader					gshaders[sp_num_gshaders];
	t_tcshader					tcshaders[sp_num_tcshaders];
	t_teshader					teshaders[sp_num_teshaders];
	t_program					programs[sp_num_programs];
	t_mesh						meshes[sp_num_meshes];
	t_texture					textures[sp_num_textures];
	t_model						models[sp_num_models];
	t_ftlist					obs[sp_num_programs];

	t_options_mesh				options_mesh;
	t_ob						*mainob;

	t_keystate					keystates[sp_num_keys];
	int							states[sp_num_states];
	double						mpos[2];

	float						cangles[2];
	t_vec3						cpos;
	t_mat4						view;

	t_mat4						projection;
	t_mat4						viewproj;

	t_vec3						sunpos_spherical;
	t_vec3						sunpos_cartesian;
	t_vec3						suncolor;
	t_texture					sbox_texture;
	GLuint						sbox_fbo;
	float						sbox_farplane;
	t_mat4						sbox_proj;
	t_mat4						sbox_viewproj[6];

	t_bool						sunskin_autotess;
	int							sunskin_colormode;
	float						sunskin_tessout[3];
	float						sunskin_tessin;
	float						sunskin_rot;

	t_texture					land_tex1;
	t_texture					land_tex2;
	t_texture					land_tex3;
	float						land_d_range_tess;
	float						land_tesslevelin_range;
	
	double						time_start;
	double						time_cur;
	double						time_el;
	double						fps;
	double						fps_samples[FPS_NSAMPLESI];
	int							fps_sample_index;
}								t_env;

# define ITEND_VSHADERS(E)	((E)->vshaders + sp_num_vshaders)
# define ITEND_FSHADERS(E)	((E)->fshaders + sp_num_fshaders)
# define ITEND_GSHADERS(E)	((E)->gshaders + sp_num_gshaders)
# define ITEND_PROGRAMS(E)	((E)->programs + sp_num_programs)
# define ITEND_MESHES(E)	((E)->meshes + sp_num_meshes)
# define ITEND_TEXTURES(E)	((E)->textures + sp_num_textures)
# define ITEND_MODELS(E)	((E)->models + sp_num_models)
# define ITEND_OBS(E)		((E)->obs + sp_num_programs)

# define VSOFP(E, P)		(&(E)->vshaders[(P)->vshader])
# define FSOFP(E, P)		(&(E)->fshaders[(P)->fshader])
# define GSOFP(E, P)		(&(E)->gshaders[(P)->gshader])
# define TCSOFP(E, P)		(&(E)->tcshaders[(P)->tcshader])
# define TESOFP(E, P)		(&(E)->teshaders[(P)->teshader])

# define POFME(E, ME)		(&(E)->programs[(ME)->program])
# define VSOFME(E, ME)		VSOFP((E), POFME((E), ME))
# define FSOFME(E, ME)		FSOFP((E), POFME((E), ME))
# define GSOFME(E, ME)		GSOFP((E), POFME((E), ME))

# define TOFMO(E, MO)		(&(E)->textures[(MO)->texture])
# define MEOFMO(E, MO)		(&(E)->meshes[(MO)->mesh])
# define POFMO(E, MO)		POFME((E), MEOFMO((E), MO))
# define VSOFMO(E, MO)		VSOFME((E), MEOFMO((E), MO))
# define FSOFMO(E, MO)		FSOFME((E), MEOFMO((E), MO))
# define GSOFMO(E, MO)		GSOFME((E), MEOFMO((E), MO))

# define MOOFOB(E, OB)		(&(E)->models[(OB)->model])
# define TOFOB(E, OB)		TOFMO((E), MOOFOB((E), OB))
# define MEOFOB(E, OB)		MEOFMO((E), MOOFOB((E), OB))
# define POFOB(E, OB)		POFMO((E), MOOFOB((E), OB))
# define VSOFOB(E, OB)		VSOFMO((E), MOOFOB((E), OB))
# define FSOFOB(E, OB)		FSOFMO((E), MOOFOB((E), OB))
# define GSOFOB(E, OB)		GSOFMO((E), MOOFOB((E), OB))

#endif
