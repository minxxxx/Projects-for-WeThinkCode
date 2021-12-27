/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:03:51 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:03:51 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;
	char	*s1old;
	char	*s2old;
	size_t	i;

	i = 0;
	s1old = s1;
	s2old = s2;
	if (s1 != NULL && s2 != NULL)
	{
		if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		if (ft_strlen(s1) + ft_strlen(s2) + 1 != 1)
		{
			while (*s1)
				new[i++] = *(s1)++;
			while (*s2)
				new[i++] = *(s2)++;
		}
		new[i] = '\0';
		ft_strdel(&s1old);
		ft_strdel(&s2old);
		return (new);
	}
	return (NULL);
}
