/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:07:04 by khansman          #+#    #+#             */
/*   Updated: 2016/11/26 14:07:05 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	compute_pos(float g_delta_move)
{
	g_x += g_delta_move * g_lx * 0.1f;
	g_z += g_delta_move * g_lz * 0.1f;
}

void	compute_dir(float g_delta_angle)
{
	g_angle += g_delta_angle;
	g_lx = sin(g_angle);
	g_lz = -cos(g_angle);
}

int		count_elements(char type)
{
	int		k;
	char	tmp;
	t_list	*l;

	l = g_lst;
	k = 0;
	while (l != NULL)
	{
		if (l->content)
		{
			ft_memcpy(&tmp, l->content, 1);
			if (tmp == type)
				k++;
		}
		l = l->next;
	}
	return (k);
}
