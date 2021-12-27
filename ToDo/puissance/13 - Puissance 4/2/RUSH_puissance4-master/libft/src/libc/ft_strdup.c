/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:20:00 by thou              #+#    #+#             */
/*   Updated: 2017/02/26 17:43:19 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*c;

	i = ft_strlen(s1) + 1;
	c = (char*)malloc(sizeof(char) * i);
	if (c == NULL)
		return (NULL);
	return ((char*)ft_memcpy(c, s1, i));
}
