/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:12:18 by ngoguey           #+#    #+#             */
/*   Updated: 2015/07/20 12:23:41 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"
#include <math.h>

t_mat4		m4_rotation_axis(t_axis a, float fact)
{
	t_mat4		ret;

	ret = M4_IDENTITY;
	if (a == x_axis)
	{
		ret.i[1].j[1] = cos(fact);
		ret.i[1].j[2] = -sin(fact);
		ret.i[2].j[1] = sin(fact);
		ret.i[2].j[2] = cos(fact);
	}
	else if (a == y_axis)
	{
		ret.i[0].j[0] = cos(fact);
		ret.i[0].j[2] = sin(fact);
		ret.i[2].j[0] = -sin(fact);
		ret.i[2].j[2] = cos(fact);
	}
	else
	{
		ret.i[0].j[0] = cos(fact);
		ret.i[0].j[1] = -sin(fact);
		ret.i[1].j[0] = sin(fact);
		ret.i[1].j[1] = cos(fact);
	}
	return (ret);
}

t_mat4		m4_rotationref_axis(t_mat4 const *ref, t_axis a, float fact)
{
	t_mat4 const		tmp = m4_rotation_axis(a, fact);

	return (m4_dotprod(ref, &tmp));
}
