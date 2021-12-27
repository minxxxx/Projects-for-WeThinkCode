/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_scalarop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 18:25:52 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/09 18:26:00 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"
#include <math.h>

t_vec3	v3_div_scalar(t_vec3 a, float q)
{
	return (ATOV3(a.x / q, a.y / q, a.z / q));
}

t_vec3	v3_mul_scalar(t_vec3 a, float f)
{
	return (ATOV3(a.x * f, a.y * f, a.z * f));
}
