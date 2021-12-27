/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pos_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 09:28:00 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/24 13:09:59 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int		ps_pos_to_array(t_stack *s, int pos)
{
	if (!s || pos < 0 || pos >= s->size)
		return (-1);
	return ((s->start + (s->pos + pos) % s->size) % s->max);
}
