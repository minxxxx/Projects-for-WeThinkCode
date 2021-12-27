/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:58:36 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/06 16:27:08 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				next_target(int *st, int len, int target, char comp)
{
	int			i;

	i = -1;
	if (comp == 1)
	{
		while (++i < len)
			if (st[i] < target)
				return (i);
	}
	else if (comp == 2)
	{
		while (++i < len)
			if (st[i] == target)
				return (i);
	}
	else if (comp == 3)
	{
		while (++i < len)
			if (st[i] > target)
				return (i);
	}
	return (comp == 1 ? INT_MAX : INT_MIN);
}
