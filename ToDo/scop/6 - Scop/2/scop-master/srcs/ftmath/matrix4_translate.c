/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_translate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 14:36:19 by ngoguey           #+#    #+#             */
/*   Updated: 2015/07/28 15:58:52 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

t_mat4		m4_translate_uniform(float fact)
{
	t_mat4		ret;

	ret = M4_IDENTITY;
	ret.i[0].j[3] = fact;
	ret.i[1].j[3] = fact;
	ret.i[2].j[3] = fact;
	return (ret);
}

t_mat4		m4_translate_nonuniform(t_vec3 vect)
{
	t_mat4		ret;

	ret = M4_IDENTITY;
	ret.i[0].j[3] = vect.x;
	ret.i[1].j[3] = vect.y;
	ret.i[2].j[3] = vect.z;
	return (ret);
}

t_mat4		m4_translateref_uniform(t_mat4 const *ref, float fact)
{
	t_mat4 const		tmp = m4_translate_uniform(fact);

	return (m4_dotprod(ref, &tmp));
}

t_mat4		m4_translateref_nonuniform(t_mat4 const *ref, t_vec3 vect)
{
	t_mat4 const		tmp = m4_translate_nonuniform(vect);

	return (m4_dotprod(ref, &tmp));
}
