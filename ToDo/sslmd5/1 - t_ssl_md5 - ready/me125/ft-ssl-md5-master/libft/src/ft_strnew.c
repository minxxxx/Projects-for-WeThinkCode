/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:54:19 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 14:54:20 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	new = ft_memalloc(size + 1);
	if (new)
	{
		i = 0;
		while (size + 1 > i)
		{
			new[i] = '\0';
			i++;
		}
		return (new);
	}
	return (NULL);
}
