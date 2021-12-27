/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:35:53 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:36:02 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_matrix	matrix_add(t_matrix first, t_matrix second)
{
	t_matrix		sum;
	unsigned int	x;
	unsigned int	y;

	if (first.x != second.x || first.y != second.y)
		error_quit("Error: Can't add matricies of diffrent sizes.");
	sum = matrix_create(first.x, first.y);
	x = 0;
	while (x < sum.x)
	{
		y = 0;
		while (y < sum.y)
		{
			sum.matrix[x][y] = first.matrix[x][y] + second.matrix[x][y];
			y++;
		}
		x++;
	}
	return (sum);
}
