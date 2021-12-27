/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:42:45 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:42:46 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		put_pixel(t_env *env, t_complex *c1, t_complex *c2,
				t_coord *dot)
{
	int		fractol_colour;

	if (0 < env->fractal && env->fractal < 5)
	{
		fractol_colour = 0;
		if (env->fractal == 1)
			fractol_colour = mandelbrot(env, c1, c2, dot);
		else if (env->fractal == 2)
			fractol_colour = julia(env, c1, c2, dot);
		else if (env->fractal == 3)
			fractol_colour = burningship(env, c1, c2, dot);
		else if (env->fractal == 4)
			fractol_colour = formula(env, c1, c2, dot);
		pixel_put(env, (dot->x - env->position->min_x)
				/ (env->position->max_x - env->position->min_x)
				* env->window->width
				, (dot->y - env->position->min_y)
				/ (env->position->max_y - env->position->min_y)
				* env->window->height
				, fractol_colour);
	}
}

static void		render(t_env *env, t_complex *c1, t_complex *c2, t_coord *dot)
{
	env->position->y = env->position->min_y;
	while (env->position->y <= env->position->max_y)
	{
		env->position->x = env->position->min_x;
		while (env->position->x <= env->position->max_x)
		{
			dot->x = env->position->x;
			dot->y = env->position->y;
			put_pixel(env, c1, c2, dot);
			env->position->x += (env->position->max_x - env->position->min_x)
				/ env->window->width / 1.1;
		}
		env->position->y += (env->position->max_y - env->position->min_y)
			/ env->window->height / 1.1;
	}
}

void			draw(t_env *env)
{
	t_complex	*c1;
	t_complex	*c2;
	t_coord		*dot;

	if (!(dot = malloc(sizeof(*dot))))
		return ;
	if (!(c1 = malloc(sizeof(*c1))))
	{
		free(dot);
		return ;
	}
	if (!(c2 = malloc(sizeof(*c2))))
	{
		free(dot);
		free(c1);
		return ;
	}
	render(env, c1, c2, dot);
	mlx_put_image_to_window(env->window->mlx, env->window->mlx_window
			, env->window->img, 0, 0);
	free(dot);
	free(c1);
	free(c2);
}
