/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_invtranslate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 12:31:47 by ngoguey           #+#    #+#             */
/*   Updated: 2015/07/20 12:28:20 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

t_mat4	m4_invtranslate_uniform(float fact)
{
	t_mat4		ret;

	ret = M4_IDENTITY;
	ret.i[0].j[3] = -fact;
	ret.i[1].j[3] = -fact;
	ret.i[2].j[3] = -fact;
	return (ret);
}

t_mat4	m4_invtranslate_nonuniform(t_vec3 vect)
{
	t_mat4		ret;

	ret = M4_IDENTITY;
	ret.i[0].j[3] = -vect.x;
	ret.i[1].j[3] = -vect.y;
	ret.i[2].j[3] = -vect.z;
	return (ret);
}

t_mat4	m4_invtranslateref_uniform(t_mat4 const *ref, float fact)
{
	t_mat4 const		tmp = m4_invtranslate_uniform(fact);

	return (m4_dotprod(ref, &tmp));
}

t_mat4	m4_invtranslateref_nonuniform(t_mat4 const *ref, t_vec3 vect)
{
	t_mat4 const		tmp = m4_invtranslate_nonuniform(vect);

	return (m4_dotprod(ref, &tmp));
}
