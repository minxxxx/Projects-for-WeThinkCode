/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:42:59 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/26 17:48:24 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
		if (!newstr)
			return (NULL);
		ft_strcpy(newstr, s1);
		ft_strcpy(newstr + s1_len, s2);
		newstr[s1_len + s2_len] = '\0';
		return (newstr);
	}
	return (NULL);
}
