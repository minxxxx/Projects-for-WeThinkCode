/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 08:53:35 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/23 08:01:03 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	size_t			j;
	char			*s1;
	const	char	*s2;
	char			temp[n + 1];

	s1 = (char *)dest;
	s2 = (const char *)src;
	i = 0;
	while (i < n)
	{
		temp[i] = s2[i];
		i++;
	}
	j = 0;
	while (j < n)
	{
		s1[j] = temp[j];
		j++;
	}
	s1[j] = '\0';
	return (dest);
}
