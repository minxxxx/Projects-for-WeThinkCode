/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 12:01:22 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/17 15:32:04 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <sys/time.h>

void					sp_delete_meshes(t_env *e)
{
	t_mesh			*me;
	t_mesh const	*end = ITEND_MESHES(e);

	me = e->meshes;
	while (me < end)
	{
		glDeleteBuffers(1, me->handles + 1);
		glDeleteBuffers(1, me->handles + 2);
		glDeleteVertexArrays(1, me->handles + 0);
		me++;
	}
	return ;
}

int						sp_init_meshes(t_env *e)
{
	t_mesh			*me;
	t_mesh const	*end = ITEND_MESHES(e);
	struct timeval	t;

	me = e->meshes;
	while (me < end)
	{
		gettimeofday(&t, NULL);
		qprintf("\033[32mGenerating mesh...\033[0m\n");
		if (sp_new_mesh(e, me))
			return (1);
		lprintf("in \033[32m%.6fs\033[0m", ft_timeval_elapsed(t));
		me++;
	}
	return (0);
}
