/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obs_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 09:02:18 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 17:31:24 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_ob		sp_default_ob(t_model_index moi)
{
	return ((t_ob){
		.list={NULL, NULL}, false, true, true, false, moi
		, OTOV3(0.f), OTOV3(0.f), OTOV3(1.f)
		, M4_IDENTITY, NULL, {0.f}, {0}
	});
}

void		sp_delete_obs(t_env *e)
{
	int		i;

	i = 0;
	while (i < sp_num_programs)
		ftl_release(e->obs + i++, NULL);
	return ;
}

int			sp_init_obs(t_env *e)
{
	int		i;

	i = 0;
	while (i < sp_num_programs)
		ftl_init_instance(e->obs + i++, sizeof(t_ob));
	sp_fill_obs(e);
	return (0);
}
