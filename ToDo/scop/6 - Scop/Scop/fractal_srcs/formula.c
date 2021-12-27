/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 11:28:39 by khansman          #+#    #+#             */
/*   Updated: 2016/10/03 11:28:40 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			init_formula(t_env *env, char *formula)
{
	char	*s;
	int		k;
	int		num;

	s = &(formula[2]);
	k = -1;
	EXTRACT_NUM;
	env->position->f.z_const = (double)num / 100000;
	F_CHECK('z', 'Z');
	EXTRACT_NUM;
	env->position->f.z_pow = (num > 0) ? num : 1;
	POW_CHECK;
	OP_CHECK;
	env->position->f.op = s[k];
	EXTRACT_NUM;
	env->position->f.c_const = (double)num / 100000;
	F_CHECK('c', 'C');
	EXTRACT_NUM;
	env->position->f.c_pow = (num > 0) ? num : 1;
	POW_CHECK;
	return (1);
}

void		rotate_colour(int key, t_env *env)
{
	if (key == 18)
		env->position->f.colour = 1;
	else if (key == 19)
		env->position->f.colour = 2;
	else if (key == 20)
		env->position->f.colour = 3;
	else if (key == 21)
		env->position->f.colour = 4;
	else if (key == 23)
		env->position->f.colour = 5;
	else if (key == 15)
	{
		env->position->zoom = 1.;
		env->position->density = 1;
		env->position->offset_x = 0.;
		env->position->offset_y = 0.;
		env->position->julia_x_factor = 0;
		env->position->julia_y_factor = 0;
		env->position->f.colour = 1;
	}
}

static int	get_colour(t_env *env, double i, double max_i)
{
	if (env->position->f.colour == 2)
	{
		if (max_i == i)
			return (0xFFFFFF);
		if (i < max_i / 2)
			return (0x0000FF * ((0.5 + i) / max_i));
		return (0x0000FF + 0xFFFF00 * ((0.5 + i) / max_i));
	}
	else if (env->position->f.colour == 3)
	{
		if (max_i == i)
			return (0x00FF00);
		if (i < max_i / 2)
			return (0xFFFFFF * i / (max_i / 2));
		return (0xFFFFFF * i / max_i);
	}
	if (max_i == i)
		return (0);
	if (i < max_i / 2)
		return (0x0000FF * i / (max_i / 2));
	return (0x0000FF + 0xFFFF00 * i / max_i);
}

int			formula(t_env *env, t_complex *c1, t_complex *c2, t_coord *dot)
{
	int			max_i;
	int			i;

	max_i = 50 * env->position->density;
	i = 0;
	c1->real = dot->x;
	c1->imaginary = dot->y;
	while (i < max_i && (c1->real * c1->real + c1->imaginary
				* c1->imaginary) < 4)
	{
		c2->real = c1->real;
		c2->imaginary = c1->imaginary;
		c1->real = pow(c2->real, env->position->f.c_pow) - pow(c2->imaginary,
				env->position->f.z_pow) - env->position->f.c_const
				- env->position->julia_x_factor / 10.0;
		c1->imaginary = (pow((c2->real + c2->imaginary), env->position->f.z_pow)
				- pow(c2->real, env->position->f.c_pow) - pow(c2->imaginary,
				env->position->f.z_pow)) + env->position->f.z_const
				+ env->position->julia_y_factor / 10.0;
		i++;
	}
	return (get_colour(env, i, max_i));
}
