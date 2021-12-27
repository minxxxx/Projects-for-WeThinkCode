/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:39:22 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/27 11:59:44 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

/*
** RED Diffused light, and infinite light location.
*/

GLfloat g_light_diffuse[] = L_DIFF;
GLfloat g_light_position[] = LIGHT_POS;

void	set_normal(t_face *face)
{
	normalise_point(VER2(x), VER2(y), VER2(z));
	glVertex3f(VER(x, x), VER(x, y), VER(x, z));
	glVertex3f(VER(y, x), VER(y, y), VER(y, z));
	glVertex3f(VER(z, x), VER(z, y), VER(z, z));
	if (face->w)
		glVertex3f(VER(w, x), VER(w, y), VER(w, z));
	if (face->w && face->u)
		glVertex3f(VER(u, x), VER(u, y), VER(u, z));
	if (face->w && face->u && face->v)
		glVertex3f(VER(v, x), VER(v, y), VER(v, z));
	if (face->w && face->u && face->v && face->o)
		glVertex3f(VER(o, x), VER(o, y), VER(o, z));
	if (face->w && face->u && face->v && face->o && face->p)
		glVertex3f(VER(p, x), VER(p, y), VER(p, z));
}

void	render_vertex(void)
{
	t_list		*k;
	t_face		*face;
	char		tmp;

	k = g_lst;
	while (k != NULL)
	{
		if (k->content)
			ft_memcpy(&tmp, k->content, 1);
		if (tmp == TYPE_FACE)
		{
			face = (t_face *)k->content;
			glBegin((g_keyhook.wire) ? REN_TYPE : GL_LINES);
			set_normal(face);
			glEnd();
		}
		k = k->next;
	}
}

/*
** To Restore the Hardcoded version, replace render_vertex with:
**	glBegin(GL_POLYGON);
**	glVertex3f(-2.0f, -2.0f, 0.0f);
**	glVertex3f(2.0f, 0.0f, 0.0f);
**	glVertex3f(0.0f, 2.0f, 0.0f);
**	glVertex3f(3.0f, 3.0f, 3.0f);
**	glVertex3f(2.0f, 0.0f, 0.0f);
**	glEnd();
*/

void	render_scene(void)
{
	if (g_delta_move)
		compute_pos(g_delta_move);
	if (g_delta_angle)
		compute_dir(g_delta_angle);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(g_keyhook.eyex, g_keyhook.eyey, g_keyhook.zoom,
		g_keyhook.centerx, g_keyhook.centery, g_keyhook.centerz,
		g_keyhook.up_x, g_keyhook.up_y, g_keyhook.up_z);
	glColor3f(g_red, g_blue, g_green);
	glRotatef(g_angle, g_centerpoint.center.x,
		g_centerpoint.center.y, g_centerpoint.center.z);
	render_vertex();
	g_angle += 0.5f;
	glutSwapBuffers();
}

void	init_gl(void)
{
	glLightfv(GL_LIGHT0, GL_DIFFUSE, g_light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, g_light_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
}
