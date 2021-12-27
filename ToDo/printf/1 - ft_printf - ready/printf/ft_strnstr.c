/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:11:41 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/23 09:52:57 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (s2 == NULL)
		return ((char *)&s1[0]);
	while (s1[i] && i < len)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i] && s2[j] && s1[i] == s2[j] && i < len)
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return ((char *)&s1[i - j]);
		}
		i++;
	}
	return (NULL);
}
