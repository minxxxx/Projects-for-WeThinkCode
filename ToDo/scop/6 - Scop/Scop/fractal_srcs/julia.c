/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:46:17 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:46:19 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_colour(double i, double max_i)
{
	if (max_i == i)
		return (0);
	if (i < max_i / 2)
		return (0x0000FF * i / (max_i / 2));
	return (0x0000FF + 0xFFFF00 * i / max_i);
}

int			julia(t_env *env, t_complex *c1, t_complex *c2, t_coord *dot)
{
	int			max_i;
	int			i;

	max_i = 100 * env->position->density;
	i = 0;
	c1->real = dot->x;
	c1->imaginary = dot->y;
	while (i < max_i && (c1->real * c1->real + c1->imaginary
				* c1->imaginary) < 4)
	{
		c2->real = c1->real;
		c2->imaginary = c1->imaginary;
		c1->real = c2->real * c2->real - c2->imaginary * c2->imaginary - 0.7
			- env->position->julia_x_factor / 10.0;
		c1->imaginary = 2 * c2->real * c2->imaginary + 0.27
			+ env->position->julia_y_factor / 10.0;
		i++;
	}
	return (get_colour(i, max_i));
}
