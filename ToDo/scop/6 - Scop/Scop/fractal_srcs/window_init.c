/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:46:42 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:46:43 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window	*window_init(void)
{
	t_window	*window;

	if (!(window = malloc(sizeof(*window))))
		return (NULL);
	window->width = 1920;
	window->height = 1080;
	if (!(window->mlx = mlx_init()))
	{
		free(window);
		return (NULL);
	}
	if (!(window->mlx_window = mlx_new_window(window->mlx, window->width
					, window->height, "ggroener's fract'ol")))
	{
		free(window);
		return (NULL);
	}
	return (window);
}
