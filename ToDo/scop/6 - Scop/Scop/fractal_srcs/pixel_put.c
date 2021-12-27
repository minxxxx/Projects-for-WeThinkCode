/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:46:37 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:46:38 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_env *env, int x, int y, unsigned int colour)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (colour & 0xFF0000) >> 16;
	g = (colour & 0x00FF00) >> 8;
	b = (colour & 0x0000FF);
	if (x >= 0 && x <= env->window->width
			&& y >= 0 && y <= env->window->height)
	{
		env->window->data[y * env->window->width * (env->window->bpp >> 3)
			+ (env->window->bpp >> 3) * x] = b;
		env->window->data[y * env->window->width * (env->window->bpp >> 3)
			+ (env->window->bpp >> 3) * x + 1] = g;
		env->window->data[y * env->window->width * (env->window->bpp >> 3)
			+ (env->window->bpp >> 3) * x + 2] = r;
	}
}
