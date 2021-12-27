/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:16:15 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 13:16:16 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char*)s1;
	if (*s2 == '\0')
		return (word);
	if (*s1 == '\0')
	{
		if (*s2 == '\0')
			return (word);
		return (NULL);
	}
	while (i < len && *(word + i) != '\0')
	{
		if (*(word + i) == *s2 && ft_strlen(s2) + i <= len)
			if (ft_strncmp(word + i, s2, ft_strlen(s2)) == 0)
				return (word + i);
		i++;
	}
	return (NULL);
}
