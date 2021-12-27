/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_int_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:09:31 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:09:31 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**ft_new_int_arr(size_t size)
{
	int		**new;
	size_t	a;

	a = 0;
	if (!(new = (int**)malloc(sizeof(int*) * (size + 1))))
		return (NULL);
	while (a < size)
	{
		new[a] = NULL;
		a++;
	}
	new[a] = NULL;
	return (new);
}
