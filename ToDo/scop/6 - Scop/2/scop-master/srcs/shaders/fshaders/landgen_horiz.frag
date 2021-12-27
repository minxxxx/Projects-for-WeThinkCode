// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   landgen_horiz.frag                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/09/19 07:51:36 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/19 15:57:54 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

uniform int						level_stride;
uniform int						phase_startoffset[2];
uniform vec2					random_seeds;
uniform float           	    land_average_y;
uniform float					land_range_y;
uniform sampler2D				tex;
uniform float                   land_min_y;
uniform float                   land_magnitude_y;

layout(location = 0) out float	point_y;
layout(location = 1) out vec4	color;

ColType                         g_colors[G_NLANDCOLORSI] = ColType[](
	ColType(G_LAND_COL(220.f, 220.f, 220.f, 100.f), 0.925f, 0.076f), //snow
	ColType(G_LAND_COL(94.f, 71.f, 64.f, 10.f), 0.8f, 0.10f),      //rock
	ColType(G_LAND_COL(13.f, 55.f, 13.f, 10.f), 0.675f, 0.125f),   //dark forest
	ColType(G_LAND_COL(55.f, 170.f, 80.f, 20.f), 0.400f, 0.225f),  //grass1
	ColType(G_LAND_COL(34.f, 106.f, 13.f, 22.f), 0.300f, 0.1f),    //disneyland
	ColType(G_LAND_COL(109.f, 61.f, 39.f, 25.f), 0.4f, 0.05f),     //earth
	ColType(G_LAND_COL(237.f, 200.f, 85.f, 30.f), 0.175f, 0.025f), //sand
	ColType(G_LAND_COL(94.f, 97.f, 186.f, 300.f), 0.075f, 0.076f)  //water
	);
float	ft_rand0(vec2 co)
{
	return fract(sin(dot(co.xy, vec2(12.9898f, 78.233f))) * 43758.5453f) - 0.5f;
}

void	main()
{
	if ((int(gl_FragCoord.x) - phase_startoffset[0]) % level_stride != 0
		|| (int(gl_FragCoord.y) - phase_startoffset[1]) % level_stride != 0)
		discard;
	vec2    tex_size = textureSize(tex, 0);
	

	int		stridehalf = level_stride / 2;
	// color = vec4(0.f, 1.f, 0.f, 1.f);
	
	point_y =
		ft_rand0(gl_FragCoord.xy + random_seeds) * land_range_y
		+ texture(tex, vec2((int(gl_FragCoord.x) - stridehalf) / tex_size.x
							, (int(gl_FragCoord.y)) / tex_size.y)).x
		/ 4.f
		+ texture(tex, vec2((int(gl_FragCoord.x) + stridehalf) / tex_size.x
							, (int(gl_FragCoord.y)) / tex_size.y)).x
		/ 4.f
		+ texture(tex, vec2((int(gl_FragCoord.x)) / tex_size.x
							, (int(gl_FragCoord.y) + stridehalf) / tex_size.y)).x
		/ 4.f
		+ texture(tex, vec2((int(gl_FragCoord.x)) / tex_size.x
							, (int(gl_FragCoord.y) - stridehalf) / tex_size.y)).x
		/ 4.f
		;
	color.rgb = vec3(0.f);
	color.x = (point_y - land_min_y) / land_magnitude_y;
	// color.x = 1.f - (point_y) / (land_average_y * 2);
	// color.x = (point_y - land_average_y * 2) / (land_average_y * 2);
	color.x = max(color.x, 0.f);
	color.x = min(color.x, 1.f);
	color = input_color(color.x, g_colors);
//	color = 1.f;
/*  	color =
		ft_rand0(gl_FragCoord.xy + random_seeds) * land_range_y
		+ land_average_y;
*/	return ;
}
