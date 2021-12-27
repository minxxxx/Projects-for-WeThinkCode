/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:31:30 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/26 17:40:40 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	char	*ptr;

	if (s)
	{
		newstr = (char *)malloc(sizeof(char) * (len + 1));
		ptr = newstr;
		if (!newstr)
			return (NULL);
		while (len)
		{
			*newstr = s[start];
			++start;
			++newstr;
			--len;
		}
		*newstr = '\0';
		return (ptr);
	}
	return (NULL);
}
