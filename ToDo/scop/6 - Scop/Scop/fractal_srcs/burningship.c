/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:42:26 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:42:28 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	d_abs(double n)
{
	return (n < 0 ? -n : n);
}

static int		get_colour(double i, double max_i)
{
	if (max_i == i)
		return (0x336600);
	return ((int)(0xFF0000 * i / max_i) / 0x010000);
}

int				burningship(t_env *env, t_complex *c1, t_complex *c2
		, t_coord *dot)
{
	int			max_i;
	int			i;

	max_i = 50 * env->position->density;
	i = 0;
	c1->real = 0;
	c1->imaginary = 0;
	while (i < max_i && (c1->real * c1->real + c1->imaginary
				* c1->imaginary) < 4)
	{
		c2->real = d_abs(c1->real);
		c2->imaginary = d_abs(c1->imaginary);
		c1->real = c2->real * c2->real - c2->imaginary * c2->imaginary
			+ dot->x;
		c1->imaginary = 2. * c2->real * c2->imaginary + dot->y / 1.777777;
		i++;
	}
	return (get_colour(i, max_i));
}
