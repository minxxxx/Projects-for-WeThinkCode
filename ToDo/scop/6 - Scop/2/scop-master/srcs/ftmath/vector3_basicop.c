/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_basicop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 09:37:05 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/09 18:26:03 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"
#include <math.h>

#define CROSS_OP(A, B) (a.A * b.B - a.B * b.A)
#define DOT_OP(M) (a.M * b.M)

t_vec3	v3_cross(t_vec3 a, t_vec3 b)
{
	return (ATOV3(CROSS_OP(y, z), CROSS_OP(z, x), CROSS_OP(x, y)));
}

float	v3_dot_normed(t_vec3 a, t_vec3 b)
{
	return (DOT_OP(x) + DOT_OP(y) + DOT_OP(z));
}

t_vec3	v3_add(t_vec3 a, t_vec3 b)
{
	return (ATOV3(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec3	v3_sub(t_vec3 a, t_vec3 b)
{
	return (ATOV3(a.x - b.x, a.y - b.y, a.z - b.z));
}
