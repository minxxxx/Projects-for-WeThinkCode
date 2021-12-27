/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:36:08 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:36:18 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_matrix	matrix_create(unsigned int x, unsigned int y)
{
	t_matrix		matrix;
	unsigned int	k;

	if (x < 1 || y < 1)
		error_quit("Error: Matrix can't have a zero size.");
	matrix.x = x;
	matrix.y = y;
	if (!(matrix.matrix = (int **)malloc(sizeof(int *) * x)))
		error_quit("Error: Failed to malloc memory for new matrix.");
	ft_bzero(matrix.matrix, sizeof(int *) * x);
	k = 0;
	while (k < x)
	{
		if (!(matrix.matrix[k] = (int *)malloc(sizeof(int) * y)))
			error_quit("Error: Failed to malloc memory for new matrix.");
		ft_bzero(matrix.matrix[k], sizeof(int) * y);
		k++;
	}
	return (matrix);
}
