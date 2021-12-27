// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   pocono_to_co_nomodel.vert                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/08/16 17:15:39 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/15 10:30:27 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

layout (location = 0) in vec3	pos;
layout (location = 1) in vec3	col;
layout (location = 2) in vec3	nor;

uniform mat4					viewproj;

out PoCoNo
{
	vec3                        pos;
	vec3						col;
	vec3                        nor;
}                               vs_out;

void main()
{
	vs_out.nor = nor;
	vs_out.col = col;
	vs_out.pos = pos;
	gl_Position = viewproj * vec4(pos, 1.f);
}
