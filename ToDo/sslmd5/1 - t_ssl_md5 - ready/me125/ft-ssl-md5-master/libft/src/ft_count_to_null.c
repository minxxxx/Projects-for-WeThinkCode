/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_to_null.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:03:51 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:03:51 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_to_null(void **data, int type)
{
	int		i;
	char	**str;
	int		**nbr;

	i = 0;
	str = NULL;
	nbr = NULL;
	if (type == 0)
	{
		str = (char**)data;
		while (str[i] != NULL)
			i++;
		return (i);
	}
	nbr = (int**)data;
	while (nbr[i] != NULL)
		i++;
	return (i);
}
