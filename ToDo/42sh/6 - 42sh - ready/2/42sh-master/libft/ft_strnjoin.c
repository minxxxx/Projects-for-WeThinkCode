/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:31:02 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:31:04 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*dst;
	int		i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dst = ft_strnew(ft_strlen(s1) + n);
	if (dst)
	{
		i = 0;
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] && j < n)
			dst[i++] = s2[j++];
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
