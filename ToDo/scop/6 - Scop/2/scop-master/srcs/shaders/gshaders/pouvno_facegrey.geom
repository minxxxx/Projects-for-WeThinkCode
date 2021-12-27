// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   pouvno_facegrey.geom                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/09/12 07:01:40 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/15 14:10:59 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

layout					(triangles) in;
layout					(triangle_strip, max_vertices = 3) out;

in PoUvNo
{
	vec3				pos;
	vec2				tex;
	vec3				nor;
}						gs_in[];

out PoCoUvNo
{
	vec3				pos;
	vec3				col;
	vec2				tex;
	vec3				nor;
}						gs_out;

#define NSHADES 24
#define DELTA (125 / NSHADES)

void main()
{
	int			i;
	float		val = (50.f + (gl_PrimitiveIDIn % NSHADES) * DELTA) / 255.f;

	gs_out.col = vec3(val);
	for (i = 0; i < 3; i++)
	{
		gs_out.tex = gs_in[i].tex;
		gs_out.nor = gs_in[i].nor;
		gs_out.pos = gs_in[i].pos;
		gl_Position = gl_in[i].gl_Position;
		EmitVertex();
	}
	EndPrimitive();
}
