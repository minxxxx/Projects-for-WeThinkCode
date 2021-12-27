/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_special_keys.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:38:44 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:38:54 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	process_special_keys2(int key, float fraction)
{
	if (key == GLUT_KEY_LEFT)
	{
		g_angle -= 0.01f;
		g_lx = sin(g_angle);
		g_lz = -cos(g_angle);
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		g_angle -= 0.01f;
		g_lx = sin(g_angle);
		g_lz = -cos(g_angle);
	}
	else if (key == GLUT_KEY_UP)
	{
		g_x += g_lx * fraction;
		g_z += g_lz * fraction;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		g_x -= g_lx * fraction;
		g_z -= g_lz * fraction;
	}
}

void	process_special_keys(int key, int x, int y)
{
	static int		mod;
	static float	fraction;

	fraction = 0.1f;
	mod = glutGetModifiers();
	(void)x;
	(void)y;
	if (key == GLUT_KEY_F1)
		set_colour(1.0, 0.0, 0.0);
	else if (key == GLUT_KEY_F2)
		set_colour(0.0, 1.0, 0.0);
	else if (key == GLUT_KEY_F3)
		set_colour(0.0, 0.0, 1.0);
	else if (key == GLUT_KEY_F4)
		set_colour(1.0, 1.0, 1.0);
	else if (key == GLUT_KEY_F5)
		set_colour(0.0, 0.0, 0.0);
	else
		process_special_keys2(key, fraction);
}

void	press_key(int key, int xx, int yy)
{
	(void)xx;
	(void)yy;
	if (key == GLUT_KEY_LEFT)
		g_delta_angle += -0.1f;
	else if (key == GLUT_KEY_RIGHT)
		g_delta_angle += 0.1f;
	else if (key == GLUT_KEY_UP)
		g_delta_move += 0.5f;
	else if (key == GLUT_KEY_DOWN)
		g_delta_move += -0.5f;
}

void	release_key(int key, int x, int y)
{
	(void)x;
	(void)y;
	if (key == GLUT_KEY_LEFT)
		g_delta_angle += -0.1f;
	else if (key == GLUT_KEY_RIGHT)
		g_delta_angle += 0.1f;
	else if (key == GLUT_KEY_UP)
		g_delta_move += 0.5f;
	else if (key == GLUT_KEY_DOWN)
		g_delta_move += -0.5f;
}
