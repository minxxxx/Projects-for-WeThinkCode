// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   debug_print_sampler.frag                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/09/17 16:07:08 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/19 13:33:30 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

uniform sampler2D			tex;
//uniform vec2				viewport;

out vec4                    color;

void	main()
{
	vec2	tex_size = textureSize(tex, 0);

//	if (gl_FragCoord.x > tex_size.x || gl_FragCoord.y > tex_size.y)
//		discard;



	// color = texture(tex, vec2((gl_FragCoord.x) / (tex_size.x)
	// 						  , (gl_FragCoord.y) / (tex_size.y)));


	// color.w = texture(tex, vec2(
	// 					  (gl_FragCoord.x) / (tex_size.x)
	// 					  , (gl_FragCoord.y) / (tex_size.y))).x;
	// color = vec4(1.f - (-color.w - 3.f) / 25.f, 0.f, 0.f, 1.f);


	color = vec4(texture(tex, vec2((gl_FragCoord.x) / (tex_size.x)
								   , (gl_FragCoord.y) / (tex_size.y))).xyz, 1.f);
	// color.xyz = (color.xyz + 1.f) / 2.f;
	// color.y = 0.f;
	// color.z = 0.f;
	
	// if (abs(color.x) > abs(color.z))
	// {
	// 	if (color.x < 0.f)
	// 		color = vec4(1., 0., 0., 1.);
	// 	else
	// 		color = vec4(0., 1., 0., 1.);
	// }
	// else
	// 	color = vec4(0., 0., 0., 1.);
	// color.x = abs(color.x) * 5.f;
	// // color.y = abs(color.y) / 1.5f;
	// color.y = 0.f;
	color.z = abs(color.z);
	color.y = abs(color.y);
	color.x = abs(color.x);
	
	return ;
}
