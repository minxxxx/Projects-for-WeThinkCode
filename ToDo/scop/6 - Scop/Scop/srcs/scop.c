/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:40:14 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/27 11:01:34 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAIN_FILE
#include "../includes/scop.h"

void	init_globals(void)
{
	ft_bzero(&g_keyhook, sizeof(t_keyhook));
	g_keyhook.zoom = 10.0f;
	g_keyhook.wire = 1;
	g_keyhook.up_y = 0.5;
	centerpoint();
}

int		main(int ac, char **av)
{
	read_obj(ac, av);
	if (av[2] && !ft_strcmp(av[2], "-v"))
		print_list(g_lst);
	set_vertix_arr();
	init_globals();
	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Scop");
	glutDisplayFunc(render_scene);
	glutReshapeFunc(change_size);
	glutIdleFunc(render_scene);
	init_gl();
	glutKeyboardFunc(process_normal_keys);
	glutSpecialFunc(process_special_keys);
	glutSpecialFunc(press_key);
	glutSpecialUpFunc(release_key);
	glutMouseFunc(mouse_button);
	glutMotionFunc(mouse_move);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return (1);
}
