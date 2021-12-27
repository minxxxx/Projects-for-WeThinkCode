/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:43:07 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:43:08 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	window_init(t_env *env)
{
	int		temp;

	if (!(env->window = malloc(sizeof(*(env->window)))))
		error_quit("Failed to malloc window struct");
	env->window->width = 640;
	env->window->height = 640;
	if (!(env->window->mlx = mlx_init()))
		error_quit("Failed to init mlx context");
	if (!(env->window->mlx_window = mlx_new_window(env->window->mlx
					, env->window->width, env->window->height
					, "ggroener's fract'ol")))
		error_quit("Failed to create window");
	env->window->bpp = 3 * 8;
	env->window->endian = 1;
	temp = env->window->width * env->window->bpp / 8;
	if (!(env->window->img = mlx_new_image(env->window->mlx
					, env->window->width, env->window->height)))
		error_quit("Failed to create image");
	if (!(env->window->data = mlx_get_data_addr(env->window->img
					, &(env->window->bpp), &temp
					, &(env->window->endian))))
		error_quit("Failed to get image data");
}

static void	position_init(t_env *env)
{
	if (!(env->position = malloc(sizeof(*(env->position)))))
		error_quit("Failed to malloc position struct");
	env->position->zoom = 1.;
	env->position->density = 1;
	env->position->offset_x = 0.;
	env->position->offset_y = 0.;
	env->position->julia_x_factor = 0;
	env->position->julia_y_factor = 0;
	env->position->f.colour = 1;
}

void		env_init(t_env *env, char *type)
{
	window_init(env);
	position_init(env);
	if (ft_strcmp(type, "mandelbrot") == 0)
		env->fractal = 1;
	else if (ft_strcmp(type, "julia") == 0)
		env->fractal = 2;
	else if (ft_strcmp(type, "burningship") == 0)
		env->fractal = 3;
	else if (!ft_strncmp("f=", type, 2) && init_formula(env, type))
		env->fractal = 4;
	else
		error_quit("Use: ./fractal [mandelbrot, julia, burningship]");
	env->cap_mouse = 0;
}
