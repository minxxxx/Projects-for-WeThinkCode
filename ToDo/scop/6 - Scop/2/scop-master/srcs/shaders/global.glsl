// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   global.glsl                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/09/15 09:28:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/19 19:03:10 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#version 410 core

#define G_USE_SUN_COLOR 1
#define G_USE_PATCH_COLOR 2
#define G_USE_TRIANGLE_COLOR 3
#define G_GAMMA 2.2f
#define G_GAMMAV3 vec3(G_GAMMAF)

#define G_AMBIENT_STRENGTH 0.1f
#define G_DIFFUSE_STRENGTH 1.75f
#define G_SPECULAR_STRENGTH 1.0f
#define G_SPECULAR_POWER 32.f

#define G_SBOX_RESOLUTIONF 1024.f
#define G_SHADOW_BIAS 0.05f
#define G_SHADOW_DECAY 1.5f
#define G_SHADOW_NUM_SAMPLING_LOOPS 3

#define G_NLANDCOLORSI 8

struct ColType
{
	vec4            color;
	float           center;
	float           halfrange;
};

/*
** CONFIG MACROES
** INITIAL_RADIUS       -> Initial sampling radius at max distance.
*/

#define G_SHADOW_INITIAL_RADIUS (200.f / G_SBOX_RESOLUTIONF)

#define G_SHADOW_NSAMPLESF float(NSAMPLESI)

#define G_COL_TO_SRGB(COL) pow((COL), vec3(G_GAMMA))
#define G_COL_TO_LINEAR(COL) pow((COL), vec3(1.f / G_GAMMA))

#define G_LAND_COL(R, G, B, S) vec4(R / 255.f, G / 255.f, B / 255.f, S)

void		normalize_prop(float proportions[G_NLANDCOLORSI])
{
	int		i;
	float   sum;

	i = 0;
	sum = 0.f;
	while (i < G_NLANDCOLORSI)
		sum += proportions[i++];
	i = 0;
	while (i < G_NLANDCOLORSI)
		proportions[i++] /= sum;
	return ;
}

void		calc_color_ratio(float proportions[G_NLANDCOLORSI], float ratio
							 , ColType g_colors[G_NLANDCOLORSI])
{
	for (int i = 0; i < G_NLANDCOLORSI; i++)
	{
		// if (ratio < g_colors[i].center + g_colors[i].halfrange
		// 	&& ratio > g_colors[i].center - g_colors[i].halfrange)
		// 	// proportions[i] = 1.f;
		// 	proportions[i] = 1.f - abs((ratio - g_colors[i].center)
		// 							   / g_colors[i].halfrange);
		// else
		// 	proportions[i] = 0.f;
		proportions[i] = 1.f;
	}
	return ;
}

vec4		input_color(float ratio, ColType g_colors[G_NLANDCOLORSI])
{
	vec4	result;
	float	proportions[G_NLANDCOLORSI];
	int		i;
	// calc_color_ratio(proportions, ratio, g_colors);
	// normalize_prop(proportions);

	for (int i = 0; i < G_NLANDCOLORSI; i++)
	{
		if (ratio < g_colors[i].center + g_colors[i].halfrange
			&& ratio > g_colors[i].center - g_colors[i].halfrange)
			// proportions[i] = 1.f;
			proportions[i] = 1.f - abs((ratio - g_colors[i].center)
									   / g_colors[i].halfrange);
		else
			proportions[i] = 0.f;
		// proportions[i] = 1.f;
	}

	float   sum;

	i = 0;
	sum = 0.f;
	while (i < G_NLANDCOLORSI)
		sum += proportions[i++];
	i = 0;
	while (i < G_NLANDCOLORSI)
		proportions[i++] /= sum;





	
	// return (vec4(ratio));//deb
	// return (g_colors[0].color);//deb
	// return (vec4(proportions[2]));//deb
	result = vec4(0.f);
	for (i = 0; i < G_NLANDCOLORSI; i++)
		if (proportions[i] > 0.f)
			result += g_colors[i].color * proportions[i];
			// result += g_colors[i].color / 8.f;
	return (result);
}
