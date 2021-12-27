/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 14:09:03 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 17:25:57 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"
#include "ft_debug.h"
#include <math.h>

void	v3_print(t_vec3 v)
{
	qprintf("% 5.2f % 5.2f % 5.2f\n", v.x, v.y, v.z);
	return ;
}

t_vec3	v3_normalize(t_vec3 v)
{
	float const		coef = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

	v.x /= coef;
	v.y /= coef;
	v.z /= coef;
	return (v);
}

t_vec3	v3_frontnormed(float const a[2])
{
	return (v3_normalize(ATOV3(
		cos(a[0]) * cos(a[1])
		, sin(a[1])
		, sin(a[0]) * cos(a[1]))));
}

t_vec3	v3_inv(t_vec3 a)
{
	return (ATOV3(-a.x, -a.y, -a.z));
}
