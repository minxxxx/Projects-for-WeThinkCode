/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 14:35:20 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/24 17:21:51 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"
#include "ft_debug.h"

void			m4_print(t_mat4 mat)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 4 == 3)
			qprintf("% 5.2f\n", mat.raw[i]);
		else
			qprintf("% 5.2f, ", mat.raw[i]);
		i++;
	}
	return ;
}
