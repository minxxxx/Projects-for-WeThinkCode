/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 16:52:15 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 17:07:11 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "scop.h"

void		sp_kevent_toggle_mouse_state(t_env *e)
{
	GLFWwindow	*w;

	w = e->win;
	if (glfwGetInputMode(w, GLFW_CURSOR) == GLFW_CURSOR_NORMAL)
		glfwSetInputMode(w, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	else
		glfwSetInputMode(w, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	glfwGetCursorPos(w, e->mpos, e->mpos + 1);
	return ;
}

void		sp_kevent_reset_campos(t_env *e)
{
	e->cpos = DEFAULT_CPOS_V3;
	memcpy(&e->cangles, DEFAULT_CANGLES, sizeof(DEFAULT_CANGLES));
	sp_update_campos(e, true);
	return ;
}

void		sp_kevent_mix_item(t_env *e, int direction)
{
	t_ob		*ob;

	ob = e->mainob;
	ob->vali[0] = direction;
	return ;
}
