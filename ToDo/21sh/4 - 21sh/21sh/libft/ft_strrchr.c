/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 13:24:16 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/23 13:35:16 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (s[size] == (char)c)
		return ((char *)&s[size]);
	while (size > 0)
	{
		if (s[size - 1] == (char)c)
			return ((char *)&s[size - 1]);
		size--;
	}
	return (NULL);
}
