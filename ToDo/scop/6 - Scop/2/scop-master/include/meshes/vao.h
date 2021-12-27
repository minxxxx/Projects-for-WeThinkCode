/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vao.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 13:55:22 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/03 17:43:20 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAO_H
# define VAO_H

# include "ftmath.h"

enum							e_location_type
{
	sp_pos_loc,
	sp_col_loc,
	sp_tex_loc,
	sp_nor_loc,
	sp_num_locs,
};
typedef struct					s_location
{
	enum e_location_type		type:8;
	t_byte						size;
}								t_location;
typedef struct					s_locations_backup_fill
{
	t_byte						noff;
	void						(*fun)();
}								t_locations_backup_fill;

typedef struct					s_location_info
{
	char						*str;
	t_byte						vertex_basic_offset;
	t_byte						vbo_basic_offset;
}								t_location_info;

# define V4Z {0.f, 0.f, 0.f, 0.f}
# define V3Z {0.f, 0.f, 0.f}
# define V2Z {0.f, 0.f}

# define BVERT_POS(X, Y, Z) {{(X), (Y), (Z)}, V4Z, V2Z, V3Z}
# define BVERT_POSCOL(X,Y,Z,R,G,B) {{(X),(Y),(Z)}, {(R),(G),(B),0.f}, V2Z, V3Z}
# define EMPTY_BVBO (t_vbo_basic){ftv_uninitialized(), 0, 0, 0, 0}

typedef struct					s_vertex_basic
{
	struct
	{
		float					x;
		float					y;
		float					z;
	}							pos;
	struct
	{
		float					r;
		float					g;
		float					b;
		float					a;
	}							col;
	struct
	{
		float					u;
		float					v;
	}							tex;
	struct
	{
		float					x;
		float					y;
		float					z;
	}							nor;
}								t_vertex_basic;

typedef struct					s_vbo_basic
{
	t_ftvector					vertices;
	t_byte						npos;
	t_byte						ncol;
	t_byte						ntex;
	t_byte						nnor;
}								t_vbo_basic;

typedef struct					s_faces_basic
{
	t_ui						indices[3];
	t_vec3						vec[3];
	t_vec3						nor;
	int							group;
	int							vali[1];
	float						valf[1];
}								t_face_basic;

typedef struct					s_ebo_basic
{
	t_ftvector					faces;
}								t_ebo_basic;

typedef struct					s_vao_basic
{
	t_vbo_basic					vbo;
	t_ebo_basic					ebo;
}								t_vao_basic;

typedef struct					s_vertex_transp
{
	t_ui						nfaces;
	t_ui						*faces;
}								t_vertex_transp;

typedef struct					s_transp_ebo
{
	t_ftvector					tvertices;
	t_ui						*field;
}								t_transp_ebo;

#endif
