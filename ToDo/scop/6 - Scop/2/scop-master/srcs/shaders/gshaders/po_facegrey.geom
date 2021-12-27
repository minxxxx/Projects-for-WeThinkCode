// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   po_facegrey.geom                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/09/12 07:32:38 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/15 11:42:44 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#define NSHADESI int(6)
#define FIRST_COLORF float(50.f)
#define LAST_COLORF float(230.f)

#define NSHADES_THIRDI int(NSHADESI / 3)
#define NSHADESF float(NSHADESI)
#define NSHADES_THIRDF float(NSHADESI / 3)
#define DELTA ((LAST_COLORF - FIRST_COLORF) / NSHADES_THIRDF)

layout					(triangles) in;
layout					(triangle_strip, max_vertices = 3) out;

uniform mat4            viewproj;
uniform mat4            model;
uniform int				colorUsing;

in Po
{
	vec3				pos;
	vec3				bpos;
}						gs_in[];

out Co
{
	vec3				col;
}						gs_out;

void main()
{
	int			i;
	int			col_index = gl_PrimitiveIDIn % NSHADESI;
	float		val = (FIRST_COLORF + (col_index % NSHADES_THIRDI) * DELTA)
		/ 255.f;

	if (col_index < NSHADES_THIRDI)
		gs_out.col = vec3(val, 0.f, 0.f);
	else if (col_index < NSHADES_THIRDI * 2)
		gs_out.col = vec3(0.f, val, 0.f);
	else
		gs_out.col = vec3(0.f, 0.f, val);
	if (colorUsing == G_USE_TRIANGLE_COLOR)
		gs_out.col += (gs_in[0].bpos + gs_in[1].bpos + gs_in[2].bpos) / 3.f;
	for (i = 0; i < 3; i++)
	{
		gl_Position = viewproj * model * vec4(gs_in[i].pos, 1.f);
		EmitVertex();
	}
	EndPrimitive();
}
