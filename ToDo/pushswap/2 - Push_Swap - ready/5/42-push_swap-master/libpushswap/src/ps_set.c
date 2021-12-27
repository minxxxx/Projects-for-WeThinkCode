/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 11:51:16 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/24 11:52:37 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void		ps_set(t_stack *s, int pos, int i)
{
	if (!s || pos < 0 || pos >= s->size)
		return ;
	s->values[ps_pos_to_array(s, pos)] = i;
}
