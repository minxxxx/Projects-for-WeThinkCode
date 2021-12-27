/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:23:32 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:14:22 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!s2[i])
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		while (s1[i + j] == s2[j] && (i + j) < n && s1[i])
		{
			if (!s2[j + 1])
				return ((char *)&s1[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
