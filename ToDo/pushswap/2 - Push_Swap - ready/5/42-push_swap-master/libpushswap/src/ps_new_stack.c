/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 08:55:04 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/24 12:48:45 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpushswap.h"

t_stack		*ps_new_stack(int size, int array_size, int *values)
{
	t_stack	*s;

	if ((s = (t_stack *)ft_memalloc(sizeof(t_stack))) == NULL)
		return (NULL);
	s->max = size;
	s->size = array_size;
	s->start = array_size - size;
	s->pos = 0;
	if ((s->values = (int *)ft_memalloc(sizeof(int) * size)) == NULL)
	{
		ft_memdel((void **)&s);
		return (NULL);
	}
	if (array_size > 0)
		ft_memmove(s->values + s->pos, values, array_size * sizeof(int));
	return (s);
}
