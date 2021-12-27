
layout (location = 0) in vec2	tex;

uniform sampler2D               ymap;
uniform vec3                    posfactors;

void main()
{
	gl_Position = vec4(
		vec3(
			tex.x - 0.5f
			, texture(ymap, tex).x
			, tex.y - 0.5f
			) * posfactors
		, 1.f);
}
