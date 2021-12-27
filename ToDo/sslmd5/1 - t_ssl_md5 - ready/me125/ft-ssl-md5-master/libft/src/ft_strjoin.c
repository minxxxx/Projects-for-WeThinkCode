/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:03:51 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:03:51 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (new == NULL)
			return (NULL);
		if (ft_strlen(s1) + ft_strlen(s2) + 1 != 1)
		{
			while (*s1)
				new[i++] = *(s1)++;
			while (*s2)
				new[i++] = *(s2)++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
