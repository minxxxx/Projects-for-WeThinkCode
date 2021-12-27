/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:43:24 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/01 09:44:16 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_position(t_env *env)
{
	if (E_ZOOM < 1)
		E_ZOOM = 1;
	else if (E_ZOOM > 1000000)
		ZOOM_CHECK_OUT;
	if (E_OFF_X < 0)
		E_OFF_X = 0;
	else if (E_OFF_X > 4 - .5 / E_ZOOM)
		E_OFF_X = 4 - .5 / E_ZOOM;
	if (E_OFF_Y < 0)
		E_OFF_Y = 0;
	else if (E_OFF_Y > 4 - .5 / E_ZOOM)
		E_OFF_Y = 4 - .5 / E_ZOOM;
	env->position->min_x = (-2.) + E_OFF_X;
	env->position->max_x = 4. / E_ZOOM + env->position->min_x;
	env->position->min_y = (-2.) + E_OFF_Y;
	env->position->max_y = 4. / E_ZOOM + env->position->min_y;
	if (env->position->density < .1)
		env->position->density = .1;
}

int		expose_hook(void *param)
{
	t_env		*env;

	env = (t_env*)param;
	check_position(env);
	draw(env);
	return (0);
}

int		key_hook(int key, void *param)
{
	t_env		*env;

	env = (t_env*)param;
	if (key == 53)
		exit(1);
	else if (key == 69)
		ZOOM_CHECK_IN;
	if (key == 78)
		ZOOM_CHECK_OUT;
	if (key == 123)
		E_OFF_X -= .5 / E_ZOOM;
	else if (key == 124)
		E_OFF_X += .5 / E_ZOOM;
	else if (key == 125)
		E_OFF_Y += .5 / E_ZOOM;
	else if (key == 126)
		E_OFF_Y -= .5 / E_ZOOM;
	else if (key == 67)
		env->position->density *= 1.5;
	else if (key == 75)
		env->position->density /= 1.5;
	rotate_colour(key, env);
	check_position(env);
	draw(env);
	return (0);
}

int		mouse_hook(int x, int y, void *param)
{
	t_env		*env;

	env = (t_env*)param;
	if ((env->fractal == 2 || env->fractal == 4) && env->cap_mouse)
	{
		env->position->julia_x_factor = (double)x / (double)env->window->width;
		env->position->julia_y_factor = (double)y / (double)env->window->height;
		if (env->position->julia_x_factor < 0)
			env->position->julia_x_factor = 0;
		else if (env->position->julia_x_factor > 1)
			env->position->julia_x_factor = 1;
		if (env->position->julia_y_factor < 0)
			env->position->julia_y_factor = 0;
		else if (env->position->julia_y_factor > 1)
			env->position->julia_y_factor = 1;
		check_position(env);
		draw(env);
	}
	return (0);
}

int		mouse_hook2(int key, int x, int y, void *param)
{
	static int	k;
	t_env		*env;

	k++;
	env = (t_env*)param;
	if (key == 2)
		env->cap_mouse = (env->cap_mouse) ? 0 : 1;
	else if (key == 4 && (k & 0x01) == 0)
	{
		E_ZOOM *= 1.5;
		E_OFF_X += ((double)x / (double)(env->window->width) * 2) / E_ZOOM;
		E_OFF_Y += ((double)y / (double)(env->window->height) * 2) / E_ZOOM;
	}
	else if (key == 5 && (k & 0x01) == 0)
	{
		E_ZOOM /= 1.5;
		E_OFF_X -= ((double)x / (double)(env->window->width) * 2) / E_ZOOM;
		E_OFF_Y -= ((double)y / (double)(env->window->height) * 2) / E_ZOOM;
	}
	check_position(env);
	draw(env);
	return (0);
}
