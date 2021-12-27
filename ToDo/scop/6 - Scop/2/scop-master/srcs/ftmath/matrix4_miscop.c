/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_miscop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 10:07:41 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 17:19:46 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"
#include <math.h>

#define MULT(A,B,F,G,H,I,M,N,O,P) A[F]*B[M]+A[G]*B[N]+A[H]*B[O]+A[I]*B[P]

t_mat4	m4_dotprod(t_mat4 const *mata, t_mat4 const *matb)
{
	t_mat4	ret;

	ret.i[0].j[0] = MULT(mata->raw, matb->raw, 0, 1, 2, 3, 0, 4, 8, 12);
	ret.i[0].j[1] = MULT(mata->raw, matb->raw, 0, 1, 2, 3, 1, 5, 9, 13);
	ret.i[0].j[2] = MULT(mata->raw, matb->raw, 0, 1, 2, 3, 2, 6, 10, 14);
	ret.i[0].j[3] = MULT(mata->raw, matb->raw, 0, 1, 2, 3, 3, 7, 11, 15);
	ret.i[1].j[0] = MULT(mata->raw, matb->raw, 4, 5, 6, 7, 0, 4, 8, 12);
	ret.i[1].j[1] = MULT(mata->raw, matb->raw, 4, 5, 6, 7, 1, 5, 9, 13);
	ret.i[1].j[2] = MULT(mata->raw, matb->raw, 4, 5, 6, 7, 2, 6, 10, 14);
	ret.i[1].j[3] = MULT(mata->raw, matb->raw, 4, 5, 6, 7, 3, 7, 11, 15);
	ret.i[2].j[0] = MULT(mata->raw, matb->raw, 8, 9, 10, 11, 0, 4, 8, 12);
	ret.i[2].j[1] = MULT(mata->raw, matb->raw, 8, 9, 10, 11, 1, 5, 9, 13);
	ret.i[2].j[2] = MULT(mata->raw, matb->raw, 8, 9, 10, 11, 2, 6, 10, 14);
	ret.i[2].j[3] = MULT(mata->raw, matb->raw, 8, 9, 10, 11, 3, 7, 11, 15);
	ret.i[3].j[0] = MULT(mata->raw, matb->raw, 12, 13, 14, 15, 0, 4, 8, 12);
	ret.i[3].j[1] = MULT(mata->raw, matb->raw, 12, 13, 14, 15, 1, 5, 9, 13);
	ret.i[3].j[2] = MULT(mata->raw, matb->raw, 12, 13, 14, 15, 2, 6, 10, 14);
	ret.i[3].j[3] = MULT(mata->raw, matb->raw, 12, 13, 14, 15, 3, 7, 11, 15);
	return (ret);
}

t_mat4	m4_lookat(t_vec3 eye, t_vec3 at, t_vec3 up)
{
	t_vec3 const		z = v3_normalize(v3_sub(eye, at));
	t_vec3 const		x = v3_normalize(v3_cross(up, z));
	t_vec3 const		y = v3_cross(z, x);

	return (ATOM4(
	x.x, x.y, x.z, -(x.x * eye.x + x.y * eye.y + x.z * eye.z)
	, y.x, y.y, y.z, -(y.x * eye.x + y.y * eye.y + y.z * eye.z)
	, z.x, z.y, z.z, -(z.x * eye.x + z.y * eye.y + z.z * eye.z)
	, 0.f, 0.f, 0.f, 1.f));
}

t_mat4	m4_fovprojection(float fov, float ratio, float near, float far)
{
	float const		tmp1 = 1.f / tan(0.5f * fov);
	float const		tmp2 = -far / (far - near);
	t_mat4			result;

	result = M4_IDENTITY;
	result.i[0].j[0] = tmp1 / ratio;
	result.i[1].j[1] = tmp1;
	result.i[2].j[2] = tmp2;
	result.i[2].j[3] = tmp2 * near * 2.f;
	result.i[3].j[2] = -1.f;
	result.i[3].j[3] = 0;
	return (result);
}
