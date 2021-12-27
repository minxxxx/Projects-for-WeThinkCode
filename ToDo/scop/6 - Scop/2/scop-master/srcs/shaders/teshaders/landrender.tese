// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   landrender.tese                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/09/19 17:29:31 by ngoguey           #+#    #+#             //
//   Updated: 2015/09/19 18:48:07 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

layout						(triangles, fractional_odd_spacing, cw) in;
//layout						(triangles, equal_spacing, cw) in;

in St
{
	vec2                    st;
}                           te_in[];

out St
{
	vec2                    st;
	vec3					bpos;
}                           te_out;

vec2    interpolate2D(vec2 v0, vec2 v1, vec2 v2)
{
	return vec2(gl_TessCoord.x) * v0
		+ vec2(gl_TessCoord.y) * v1
		+ vec2(gl_TessCoord.z) * v2;
}

void	main()
{
	te_out.st = interpolate2D(te_in[0].st, te_in[1].st, te_in[2].st);
	te_out.bpos = gl_TessCoord;
	return ;
}
