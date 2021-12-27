/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:46:27 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:46:30 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_colour(double i, double max_i)
{
	if (max_i == i)
		return (0);
	if (i < max_i)
		return (0x0000FF * i / max_i);
	return (0x0000FF + 0xFFFF00 * i / max_i / 1.5);
}

int			mandelbrot(t_env *env, t_complex *c1, t_complex *c2, t_coord *dot)
{
	int		max_i;
	int		i;

	max_i = 40 * env->position->density;
	i = 0;
	c1->real = 0;
	c1->imaginary = 0;
	while (i < max_i && (c1->real * c1->real + c1->imaginary
				* c1->imaginary) < 4)
	{
		c2->real = c1->real;
		c2->imaginary = c1->imaginary;
		c1->real = c2->real * c2->real - c2->imaginary * c2->imaginary + dot->x;
		c1->imaginary = 2. * c2->real * c2->imaginary + dot->y / 1.777777;
		i++;
	}
	return (get_colour(i, max_i));
}
