/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obs_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 08:57:03 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/22 12:18:51 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#define NORM_AT_42_IS_WTF(E, OB) (OB)->update((E), (OB))

static void		update_prog_obs(t_env *const e, t_ftlist *const prl)
{
	t_ob						*ob;
	t_ftlist_node const *const	end = ftl_cend(prl);
	t_ob						*next;

	ob = (t_ob*)prl->next;
	while ((t_ftlist_node*)ob != end)
	{
		next = (t_ob*)ob->list.next;
		if (ob->delete)
			ftl_erase_pos(prl, (t_ftlist_node*)ob, NULL);
		else if (ob->update != NULL)
			NORM_AT_42_IS_WTF(e, ob);
		ob = next;
	}
	return ;
}

static void		update_matrix_ob(t_env const *e, t_ob *ob)
{
	ob->mat = m4_translate_nonuniform(ob->position);
	ob->mat = m4_rotationref_axis(&ob->mat, z_axis, ob->rotation.x);
	ob->mat = m4_rotationref_axis(&ob->mat, y_axis, ob->rotation.y);
	ob->mat = m4_rotationref_axis(&ob->mat, x_axis, ob->rotation.z);
	ob->mat = m4_scaleref_nonuniform(&ob->mat, ob->scale);
	ob->moved = false;
	return ;
	(void)e;
}

void			sp_update_obs(t_env *e)
{
	t_program_index		i;

	i = -1;
	while (++i < sp_num_programs)
	{
		if (e->obs[i].size == 0)
			continue ;
		update_prog_obs(e, e->obs + i);
	}
	i = -1;
	while (++i < sp_num_programs)
	{
		ftl_foreach_if(e->obs + i, &update_matrix_ob, (void*)e
						, &sp_ob_get_moved);
	}
	return ;
}
