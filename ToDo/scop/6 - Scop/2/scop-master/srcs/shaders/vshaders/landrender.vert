// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   landrender.vert                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/09/19 08:51:18 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/19 17:52:40 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

layout (location = 0) in vec2	tex;

uniform sampler2D				ymap;
uniform sampler2D				normap;
uniform vec3					posfactors;

out StPoNo
{
	vec2						st;
	vec3						pos;
	vec3						nor;
}								vs_out;

void	main()
{
	// vs_out.st = tex;
	vs_out.st = tex;
	vs_out.pos = vec3(
		tex.st.x - 0.5f
		, texture(ymap, tex.st).x
		, tex.st.y - 0.5f
		) * posfactors;
	vs_out.nor = texture(normap, tex.st).xyz;
	// vs_out.pos = vec3(
	// 	st.x * posfactors.x
	// 	, texture(ymap, st)
	// 	, st.y * posfactors.z
	// 	);
	return ;
}
