/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:45:16 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/14 11:26:56 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = ft_strlen(s1);
	res = ft_strlen(s2) + j;
	if (size < j)
		return (ft_strlen(s2) + size);
	while (s2[i] && (size > j + 1))
		s1[j++] = s2[i++];
	s1[j] = '\0';
	return (res);
}
