/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 11:34:53 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/24 12:13:33 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "libft.h"

void		ps_rotate(t_stack *s, int direction)
{
	if (!s || s->size == 0 || direction == 0)
		return ;
	direction %= s->size;
	if (direction < 0)
		direction += s->size;
	s->pos = (s->pos + direction) % s->size;
}
