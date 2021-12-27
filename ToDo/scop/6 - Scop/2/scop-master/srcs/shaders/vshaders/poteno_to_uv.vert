// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   poteno_to_uv.vert                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/07/30 09:09:23 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/15 13:38:01 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

layout (location = 0) in vec3	pos;
layout (location = 1) in vec2	tex;
layout (location = 2) in vec3	nor;

out PoUvNo
{
	vec3						pos;
	vec2						tex;
	vec3						nor;
}								vs_out;

uniform mat4					model;
uniform mat4					viewproj;

void main()
{
	vs_out.tex = tex;
	vs_out.nor = mat3(transpose(inverse(model))) * nor;
	gl_Position = model * vec4(pos, 1.f);
	vs_out.pos = vec3(gl_Position);
	gl_Position = viewproj * gl_Position;
}
