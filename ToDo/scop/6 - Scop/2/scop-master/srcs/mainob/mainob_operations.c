/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainob_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 11:57:44 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:42:42 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <string.h>

void		sp_mainob_resetpos(t_env *e)
{
	t_ob		*ob;

	ob = e->mainob;
	ob->position = D_MAINOBPOS_V3;
	ob->rotation = D_MAINOBANGLES_V3;
	ob->moved = true;
	return ;
}
