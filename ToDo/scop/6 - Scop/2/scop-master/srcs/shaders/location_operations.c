/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:34:33 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/12 08:34:53 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_byte		sp_location_size(t_vshader const *vs, enum e_location_type type)
{
	t_location const		*loc;
	t_location const *const	end = vs->locations + vs->n_locations;

	loc = vs->locations;
	while (loc < end)
	{
		if (type == loc->type)
			return (loc->size);
		loc++;
	}
	return (0);
}

t_byte		sp_locations_nbytes(t_vshader const *vs)
{
	t_location const		*loc;
	t_location const *const	end = vs->locations + vs->n_locations;
	t_byte					tot;

	tot = 0;
	loc = vs->locations;
	while (loc < end)
	{
		tot += loc->size * sizeof(float);
		loc++;
	}
	return (tot);
}
