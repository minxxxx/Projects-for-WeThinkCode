// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   landrender.frag                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/09/19 08:51:15 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/19 16:39:07 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

in StPoCoNo
{
	vec2						st;
	vec3						pos;
	vec3						col;
	vec3						nor;
}                               fs_in;

// uniform sampler2D                normap;
uniform sampler2D                colmap;
uniform samplerCube         depthMap;
uniform float               far;
uniform vec3                viewPos;
uniform struct Light {
	vec3 pos;
	vec3 col;
}                           l;

out vec4						color;


#define NSAMPLESI 20
#define NSAMPLESF float(NSAMPLESI)
#define GN ((1.f + sqrt(5.f)) / 2.f)
#define GN2 (GN * GN)
#define GN3 (GN2 * GN)
#define NORMALIZE_FACT (1 / sqrt(GN2 * GN2 * 3))
#define V0 (GN * NORMALIZE_FACT)
#define V1 (GN2 * NORMALIZE_FACT)
#define V2 (GN3 * NORMALIZE_FACT)

vec3                        SAMPLES[NSAMPLESI] = vec3[](
	vec3(-V1, -V1, V1), vec3(V2, V0, 0),    vec3(V2, -V0, 0),
	vec3(-V2, V0, 0),   vec3(-V2, -V0, 0),  vec3(0, V2, V0),
	vec3(0, V2, -V0),   vec3(V0, 0, -V2),   vec3(-V0, 0, -V2),
	vec3(0, -V2, -V0),  vec3(0, -V2, V0),   vec3(V0, 0, V2),
	vec3(-V0, 0, V2),   vec3(V1, V1, -V1),  vec3(V1, V1, V1),
	vec3(-V1, V1, -V1), vec3(-V1, V1, V1),  vec3(V1, -V1, -V1),
	vec3(V1, -V1, V1),  vec3(-V1, -V1, -V1)
);

float                   sample_shadows(
	float dFraLi, vec3 vLiToFra, float weight, float radius)
{
	float   shadow;

	shadow = 0.f;
	for (int i = 0; i < NSAMPLESI; ++i)
	{
		if (dFraLi - G_SHADOW_BIAS
			> texture(depthMap, vLiToFra + SAMPLES[i] * radius).r * far)
		{
			shadow += weight;
		}
	}
	return (shadow);
}

float                   compute_shadows(
	float dnFraLi, float dFraLi, vec3 vLiToFra)
{
	float   shadow;
	float   samples;
	float   weight;
	float   radius;

	shadow = 0.f;
	samples = 0.f;
	weight = 1.f;
	radius = G_SHADOW_INITIAL_RADIUS * sqrt(dnFraLi);
	for (int i = 0; i < G_SHADOW_NUM_SAMPLING_LOOPS; i++)
	{
		shadow += sample_shadows(dFraLi, vLiToFra, weight, radius);
		samples += NSAMPLESF * weight;
		weight /= G_SHADOW_DECAY * G_SHADOW_DECAY;
		radius *= G_SHADOW_DECAY;
	}
	return (shadow / samples);
}

void	main()
{
	color = texture(colmap, fs_in.st);
	
	
	// color = vec4(fs_in.col, 1.f);
	// color = vec4(1.f, 1.f, 0.f, 1.f);
	vec3    vLiToFra = fs_in.pos - l.pos;
	vec3    vFraToLi = -vLiToFra;
	vec3    vnFraToLi = normalize(vFraToLi);
	vec3    vFraToCam = viewPos - fs_in.pos;
	vec3    vnFraToCam = normalize(vFraToCam);
	vec3    vFraNormal = fs_in.nor;
	// vFraNormal = texture(normap, fs_in.st, 10.1f).xyz;
	vec3    vnFraNormal = normalize(vFraNormal);
	float   dFraLi = length(vLiToFra);
	float   dnFraLi = dFraLi / far;
	float   dFraCam = length(vFraToCam);
	float   attenuation = 1.f - (dFraLi / far);
	float   ambient = G_AMBIENT_STRENGTH;
	float   diffuse = max(dot(vnFraNormal, vnFraToLi), 0.f)
		* G_DIFFUSE_STRENGTH;
	vec3    vnLiCamHalfway = normalize(vnFraToLi + vnFraToCam);
	float   specular =
			pow(max(dot(vnFraNormal, vnLiCamHalfway), 0.0), color.a)
		* G_SPECULAR_STRENGTH;
	float   shadow = compute_shadows(dnFraLi, dFraLi, vLiToFra);

	 //f loat   shadow = 0.f;
	vec3    cLight = G_COL_TO_SRGB(l.col);

	// color = vec4(fs_in.col, 1.f);
	// color.rgb = vnFraNormal;
	// color.r = abs(color.r);
	// color.g = abs(color.g);
	// color.b = abs(color.b);
	
	color.rgb = G_COL_TO_SRGB(color.rgb);
	color = vec4(
		(ambient + (
			// vec3(0.f)
			diffuse
					+ specular
			) * (1.f - shadow) * attenuation)
			        * cLight * color.xyz
		, color.w);
	color.rgb = G_COL_TO_LINEAR(color.rgb);




	
	// color.rgb = (-vnFraNormal);;
	// color.rgb = vnFraNormal;
	// color.r = abs(color.r);
	// color.g = abs(color.g);
	// color.b = abs(color.b);
	
	return ;
}
