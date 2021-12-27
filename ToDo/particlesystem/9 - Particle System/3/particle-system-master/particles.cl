/*
 * Brett Fedack
 * CS475E Spring 2015
 * Project 6 - OpenGL/OpenCL Particle System
 * NOTE: Bounce, BounceSphere, and IsInsideSphere functions were provided by
 *       Professor Mike Bailey.
 */

typedef float4 point;
typedef float4 vector;
typedef float4 color;
typedef float4 sphere;
typedef float4 rgba;
typedef float4 hsva;

// EasyRGB (http://www.easyrgb.com/index.php?X=MATH) has some great color
// conversion algorithms. The following function is my OpenCL implementation
// of the pseudo-code on that web page.
rgba
HSVAtoRGBA(hsva in)
{
	float h, s, v, r, g, b;

	h = in.x;
	s = in.y;
	v = in.z;

	if (s == 0)
	{
		r = g = b = v;
	}
	else
	{
		float var_h, var_i, var_1, var_2, var_3;

		var_h = h * 6;
		if (var_h == 6)
		{
			var_h = 0;
		}
		var_i = floor(var_h);
		var_1 = v * (1 - s);
		var_2 = v * (1 - s * (var_h - var_i));
		var_3 = v * (1 - s * (1 - (var_h - var_i)));

		switch ((int) var_i)
		{
			case 0:
				r = v;
				g = var_3;
				b = var_1;
				break;
			case 1:
				r = var_2;
				g = v;
				b = var_1;
				break;
			case 2:
				r = var_1;
				g = v;
				b = var_3;
				break;
			case 3:
				r = var_1;
				g = var_2;
				b = v;
				break;
			case 4:
				r = var_3;
				g = var_1;
				b = v;
				break;
			default:
				r = v;
				g = var_1;
				b = var_2;
				break;
		}
	}

	return (rgba) (r, g, b, 1.f);
}

rgba
RGBAfromVelocity(vector v)
{
	// Determine the particle's relative speed.
	float max_speed = 125.f;                   // Matches VMAX in cpp file
	float relative_speed = fast_length(v) / max_speed;

	// Clamp the upper bound of speed.
	if (relative_speed > 1.f)
	{
		relative_speed = 1.f;
	}

	// Encode the fastest particles as red.
	float red_h = 0.f;

	// Encode the slowest particles as blue.
	float blue_h = 0.667f;

	// Interpolate hues based on the given velocity.
	float h = blue_h - relative_speed * (blue_h - red_h);

	// Desaturate slightly for aesthetic reasons.
	float s = 0.8;

	// Convert the interpolated color to rgba.
	return HSVAtoRGBA((hsva) (h, s, 1.f, 1.f));
}


vector
Bounce( vector in, vector n )
{
	if (dot(in.xyz, n.xyz) < 0)
	{
		n *= -1;
	}
	vector out = 0.9 * (in - 2.*n*dot(in->xyz, n.xyz));
	out.w = 0.;
	return out;
}

vector
BounceSphere( point p, vector in, sphere s )
{
	vector n;
	n.xyz = fast_normalize( p.xyz - s.xyz );
	n.w = 0.;
	return Bounce( in, n );
}

bool
IsInsideSphere( point p, sphere s )
{
	float r = fast_length( p.xyz - s.xyz );
	return  ( r < s.w );
}

kernel
void
Particle( global point *dPobj, global vector *dVel, global color *dCobj )
{
	const float4 G       = (float4) ( 0., -9.8, 0., 0. );
	const float  DT      = 0.1;
	const sphere Sphere1 = (sphere)( 0., -1400., 0.,  1000. ); // Internal sphere
	const sphere Sphere2 = (sphere)( 0., 0., 0.,  2400. ); // Bounding sphere
	int gid = get_global_id( 0 );

	point  p = dPobj[gid];
	vector v = dVel[gid];

	point  pp = p + v*DT + .5*DT*DT*G;
	vector vp = v + G*DT;
	pp.w = 1.;
	vp.w = 0.;

	// Detect collision with the smalller, internal sphere.
	if( IsInsideSphere( pp, Sphere1 ) )
	{
		vp = BounceSphere( p, v, Sphere1 );
		pp = p + vp*DT + .5*DT*DT*G;
	}

	// Detect collision with the larger, bounding sphere.
	if( !IsInsideSphere( pp, Sphere2 ) )
	{
		vp = BounceSphere( p, v, Sphere2 );
		pp = p + vp*DT + .5*DT*DT*G;
	}

	// Update the particle's position and velocity.
	dPobj[gid] = pp;
	dVel[gid]  = vp;

	// Set the particle's color based on it's speed.
	dCobj[gid] = RGBAfromVelocity(vp);
}
