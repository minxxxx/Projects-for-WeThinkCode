/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_identity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:36:44 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:36:45 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_matrix	matrix_identity(unsigned int size)
{
	t_matrix		iden_mat;
	unsigned int	k;

	iden_mat = matrix_create(size, size);
	k = 0;
	while (k < size)
	{
		iden_mat.matrix[k][k] = 1;
		k++;
	}
	return (iden_mat);
}
