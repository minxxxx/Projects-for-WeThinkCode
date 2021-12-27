/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:37:30 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:37:32 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_matrix	matrix_transpose(t_matrix source)
{
	t_matrix		new_mat;
	unsigned int	x;
	unsigned int	y;

	new_mat = matrix_create(source.y, source.x);
	x = 0;
	while (x < new_mat.x)
	{
		y = 0;
		while (y < new_mat.y)
		{
			new_mat.matrix[x][y] = source.matrix[y][x];
			y++;
		}
		x++;
	}
	return (new_mat);
}
