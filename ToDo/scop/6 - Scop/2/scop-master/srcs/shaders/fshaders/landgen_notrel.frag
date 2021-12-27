// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   landgen_notrel.frag                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/09/16 11:32:06 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/19 16:14:24 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

uniform int						level_stride;
uniform int						phase_startoffset[2];
uniform vec2					random_seeds;
uniform float					land_range_y;
uniform float					land_average_y;

uniform float					land_min_y;
uniform float					land_magnitude_y;

layout(location = 0) out float	point_y;
layout(location = 1) out vec4	color;

ColType							g_colors[G_NLANDCOLORSI] = ColType[](
	ColType(G_LAND_COL(240.f, 240.f, 240.f, 50.f), 0.925f, 0.076f), //snow
    ColType(G_LAND_COL(94.f, 71.f, 64.f, 10.f), 0.8f, 0.10f),      //rock
	ColType(G_LAND_COL(13.f, 55.f, 13.f, 10.f), 0.675f, 0.125f),   //dark forest
	ColType(G_LAND_COL(55.f, 170.f, 80.f, 10.f), 0.400f, 0.225f),  //grass1
	ColType(G_LAND_COL(34.f, 106.f, 13.f, 10.f), 0.300f, 0.1f),    //disneyland
	ColType(G_LAND_COL(109.f, 61.f, 39.f, 10.f), 0.4f, 0.05f),     //earth
	ColType(G_LAND_COL(237.f, 200.f, 85.f, 30.f), 0.175f, 0.025f), //sand
	ColType(G_LAND_COL(94.f, 97.f, 186.f, 50.f), 0.075f, 0.076f)  //water
);

float	ft_rand0(vec2 co)
{
	return fract(sin(dot(co.xy, vec2(12.9898f, 78.233f))) * 43758.5453f) - 0.5f;
}

void	main()
{
	if ((int(gl_FragCoord.x) - phase_startoffset[0]) % level_stride != 0
		|| (int(gl_FragCoord.y) - phase_startoffset[1]) % level_stride != 0)
	{
		discard;
	}
	// color = vec4(1.f, 0.f, 0.f, 1.f);
  	point_y = ft_rand0(gl_FragCoord.xy + random_seeds) * land_range_y
		+ land_average_y;
	color.rgb = vec3(0.f);
	color.x = (point_y - land_min_y) / land_magnitude_y;
	color.x = max(color.x, 0.f);
	color.x = min(color.x, 1.f);
	color = input_color(color.x, g_colors);
	return ;
}
