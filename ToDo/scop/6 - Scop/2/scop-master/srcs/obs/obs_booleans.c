/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obs_booleans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 17:31:16 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 17:31:21 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_bool		sp_ob_getnot_hidden(t_env const *e, t_ob const *ob)
{
	return (!ob->hidden);
	(void)e;
}

t_bool		sp_ob_get_moved(t_env const *e, t_ob const *ob)
{
	return (ob->moved);
	(void)e;
}

t_bool		sp_ob_get_shadow(t_env const *e, t_ob const *ob)
{
	return (ob->shadow);
	(void)e;
}
