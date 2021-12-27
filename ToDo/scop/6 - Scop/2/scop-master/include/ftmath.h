/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 12:16:50 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/19 11:33:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTMATH_H
# define FTMATH_H

# include "libft.h"

/*
** Macroes
*/
# define FLOORF(A) ()
# define CEILF(A) ()
# define ROUND_FTOI(A) ((A) > 0.f ? (int)((A) + 0.5f) : (int)((A) - 0.5f))

/*
** ATOV3		Absolute to vector3
** ATOM4		Absolute to matrix4
*/
# define ATOV2(...) ((t_vec2){__VA_ARGS__})
# define ATOV2I(...) ((t_vec2i){__VA_ARGS__})
# define ATOV3(...) ((t_vec3){__VA_ARGS__})
# define OTOV3(VAL) ((t_vec3){(VAL), (VAL), (VAL)})
# define ATOM4(...) ((t_mat4){{__VA_ARGS__}})
# define M4_IDENTITY ATOM4([0] = 1.f, [5] = 1.f, [10] = 1.f, [15] = 1.f)

typedef enum	e_axis
{
	x_axis,
	y_axis,
	z_axis
}				t_axis;
/*
** VECTOR2
*/
typedef struct	t_vec2i
{
	int			x;
	int			y;
}				t_vec2i;
typedef struct	t_vec2
{
	float		x;
	float		y;
}				t_vec2;

/*
** VECTOR3
*/
typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

void			v3_print(t_vec3 v);
t_vec3			v3_normalize(t_vec3 v);
t_vec3			v3_frontnormed(float const angles[2]);
t_vec3			v3_cross(t_vec3 a, t_vec3 b);
float			v3_dot_normed(t_vec3 a, t_vec3 b);
t_vec3			v3_sub(t_vec3 a, t_vec3 b);
t_vec3			v3_add(t_vec3 a, t_vec3 b);
t_vec3			v3_inv(t_vec3 a);
t_vec3			v3_div_scalar(t_vec3 a, float q);
t_vec3			v3_mul_scalar(t_vec3 a, float q);
float			v3_sqrdist(t_vec3 a, t_vec3 b);
float			v3_dist(t_vec3 a, t_vec3 b);

/*
** MATRIX4
*/
typedef union	u_matrix4
{
	float		raw[16];
	struct
	{
		float	j[4];
	}			i[4];
}				t_mat4;
# define MAT4 t_mat4
# define VEC3 t_vec3

MAT4			m4_scale_nonuniform(VEC3 vect);
MAT4			m4_scale_uniform(float fact);
MAT4			m4_scaleref_nonuniform(MAT4 const *ref, VEC3 vect);
MAT4			m4_scaleref_uniform(MAT4 const *ref, float fact);

MAT4			m4_translate_nonuniform(VEC3 vect);
MAT4			m4_translate_uniform(float fact);
MAT4			m4_translateref_nonuniform(MAT4 const *ref, VEC3 vect);
MAT4			m4_translateref_uniform(MAT4 const *ref, float fact);

MAT4			m4_invtranslate_nonuniform(VEC3 vect);
MAT4			m4_invtranslate_uniform(float fact);
MAT4			m4_invtranslateref_nonuniform(MAT4 const *ref, VEC3 vect);
MAT4			m4_invtranslateref_uniform(MAT4 const *ref, float fact);

MAT4			m4_rotation_axis(t_axis a, float fact);
MAT4			m4_rotationref_axis(MAT4 const *ref, t_axis a, float fact);

MAT4			m4_dotprod(MAT4 const *mata, MAT4 const *matb);
MAT4			m4_fovprojection(float fov, float ratio, float near, float far);

void			m4_print(MAT4 mat);
MAT4			m4_lookat(t_vec3 eye, t_vec3 at, t_vec3 up);
MAT4			m4_identity(void);

# undef MAT4
# undef VEC3

#endif
