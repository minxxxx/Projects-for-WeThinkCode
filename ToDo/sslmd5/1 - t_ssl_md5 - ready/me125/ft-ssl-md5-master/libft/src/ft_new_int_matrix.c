/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_int_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:09:31 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:09:31 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**ft_new_int_matrix(size_t size)
{
	int		**new;
	size_t	a;

	a = 0;
	if (!(new = (int**)malloc(sizeof(int*) * (size + 1))))
		return (NULL);
	while (a < size)
	{
		if (!(new[a] = (int*)malloc(sizeof(int) * (size))))
			return (NULL);
		ft_bzero(new[a], sizeof(int) * size);
		a++;
	}
	new[a] = NULL;
	return (new);
}
