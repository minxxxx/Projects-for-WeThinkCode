/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:14:09 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 13:14:09 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int ch)
{
	char	*r;
	char	*s;
	size_t	a;
	size_t	check;

	check = 0;
	a = 0;
	s = (char*)str;
	r = NULL;
	while (a < (ft_strlen(str) + 1))
	{
		if (s[a] == (char)ch)
		{
			r = &s[a];
			check++;
		}
		a++;
	}
	if (check != 0)
		return ((char *)r);
	return (NULL);
}
