/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:32:36 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:32:55 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	change_size(int w, int h)
{
	float	ratio;

	if (h == 0)
		h = 1;
	ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 10000.0f);
	glMatrixMode(GL_MODELVIEW);
}
