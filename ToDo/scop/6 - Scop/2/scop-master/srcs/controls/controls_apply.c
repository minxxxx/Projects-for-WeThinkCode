/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_apply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 11:35:09 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 17:04:40 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <math.h>
#include "scop.h"

void			sp_update_states(t_env *e)
{
	sp_update_campos(e, false);
	sp_update_sunpos(e, false);
	sp_update_sunrot(e, false);
	sp_update_mainobpos(e);
	return ;
}
