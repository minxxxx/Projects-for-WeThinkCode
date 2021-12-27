/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_normal_keys.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:38:30 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/27 16:18:22 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

static void		process_normal_keys_3(unsigned char key)
{
	if (key == '8' || key == '7' || key == '9')
		g_keyhook.eyex += 0.7;
	if (key == '2' || key == '1' || key == '3')
		g_keyhook.eyex -= 0.7;
	if (key == '4' || key == '7' || key == '1')
		g_keyhook.eyey += 0.7;
	if (key == '6' || key == '9' || key == '3')
		g_keyhook.eyey -= 0.7;
	if (key == 'n')
		g_keyhook.eyez += 0.5;
	if (key == 'm')
		g_keyhook.eyez -= 0.5;
}

static void		process_normal_keys2(unsigned char key, int mod)
{
	if (mod & GLUT_ACTIVE_CTRL)
	{
		if (key == '8' || key == '7' || key == '9')
			g_keyhook.up_x += 0.7;
		if (key == '2' || key == '1' || key == '3')
			g_keyhook.up_x -= 0.7;
		if (key == '4' || key == '7' || key == '1')
			g_keyhook.up_y += 0.7;
		if (key == '6' || key == '9' || key == '3')
			g_keyhook.up_y -= 0.7;
		if (key == 'n')
			g_keyhook.up_z += 0.5;
		if (key == 'm')
			g_keyhook.up_z -= 0.5;
	}
	else
		process_normal_keys_3(key);
}

static void		process_normal_keys4(unsigned char key)
{
	key == 'm' && (g_keyhook.zoom -= 1.0);
	key == 'n' && (g_keyhook.zoom += 1.0);
	(key == '8' || key == '7' || key == '9') && (g_keyhook.centery -= .3);
	(key == '2' || key == '1' || key == '3') && (g_keyhook.centery += .3);
	(key == '4' || key == '1' || key == '7') && (g_keyhook.centerx += .3);
	(key == '6' || key == '9' || key == '3') && (g_keyhook.centerx -= .3);
}

void			process_normal_keys(unsigned char key, int x, int y)
{
	static int		mod;

	mod = glutGetModifiers();
	(void)x;
	(void)y;
	if (key == KEY_ESC)
		exit_prog();
	else if (mod & (GLUT_ACTIVE_CTRL | GLUT_ACTIVE_ALT))
	{
		process_normal_keys2(key, mod);
		return ;
	}
	else if (key == 'r')
		g_red = (mod == GLUT_ACTIVE_ALT) ? 0.0 : 1.0;
	key == 'a' && (g_centerpoint.center.x += .5);
	key == 'q' && (g_centerpoint.center.x -= .5);
	key == 'w' && (g_centerpoint.center.y += .5);
	key == 's' && (g_centerpoint.center.y -= .5);
	key == 'e' && (g_centerpoint.center.z += .5);
	key == 'd' && (g_centerpoint.center.z -= .5);
	if (key == 'f')
		g_keyhook.wire = (g_keyhook.wire) ? 0 : 1;
	if (key == 'b')
		glutFullScreen();
	process_normal_keys4(key);
}
