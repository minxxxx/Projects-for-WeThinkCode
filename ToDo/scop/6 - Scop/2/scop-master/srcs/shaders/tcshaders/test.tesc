// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test.tesc                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/09/12 09:58:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/15 10:41:00 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

layout						(vertices = 3) out;

uniform vec3				camPos;
uniform vec3				sunPos;
uniform float				tessLevelOut0;
uniform float				tessLevelOut1;
uniform float				tessLevelOut2;
uniform float				tessLevelIn;

in Po
{
	vec3					pos;
}							tec_in[];

out Po
{
	vec3					pos;
}							tec_out[];

void	main()
{
	float		dist;

	tec_out[gl_InvocationID].pos = tec_in[gl_InvocationID].pos;
	if (gl_InvocationID != 0)
		return ;
	gl_TessLevelOuter[0] = tessLevelOut0;
	gl_TessLevelOuter[1] = tessLevelOut1;
	gl_TessLevelOuter[2] = tessLevelOut2;
	gl_TessLevelInner[0] = tessLevelIn;
	return ;
}
