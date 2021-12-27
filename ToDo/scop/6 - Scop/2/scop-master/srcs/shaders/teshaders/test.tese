// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test.tese                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/09/12 09:58:28 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/19 18:18:45 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

layout						(triangles, equal_spacing, cw) in;

in Po
{
	vec3					pos;
}							tec_in[]; //rename tec to te

out Po
{
	vec3					pos;
	vec3					bpos;
}							tec_out;

vec3	interpolate3D(vec3 v0, vec3 v1, vec3 v2)
{
	return vec3(gl_TessCoord.x) * v0
		+ vec3(gl_TessCoord.y) * v1
		+ vec3(gl_TessCoord.z) * v2;
}

void	main()
{
	vec3	vLpos = interpolate3D(tec_in[0].pos, tec_in[1].pos, tec_in[2].pos);
	float	radius = length(vLpos);

	vLpos /= radius * 2.f;
	tec_out.pos = vLpos;
	tec_out.bpos = gl_TessCoord;
	return ;
}
