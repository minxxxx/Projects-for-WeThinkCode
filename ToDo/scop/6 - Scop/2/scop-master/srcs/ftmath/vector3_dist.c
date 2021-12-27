
#include "ftmath.h"
#include <math.h>

float	v3_sqrdist(t_vec3 a, t_vec3 b)
{
	float const		dx = a.x - b.x;
	float const		dy = a.y - b.y;
	float const		dz = a.z - b.z;

	return (dx * dx + dy * dy + dz * dz);
}

float	v3_dist(t_vec3 a, t_vec3 b)
{
	return (sqrt(v3_sqrdist(a, b)));
}
