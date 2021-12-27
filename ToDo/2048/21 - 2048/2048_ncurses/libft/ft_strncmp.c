/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 18:52:45 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/26 14:35:31 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*s1c;
	unsigned char	*s2c;

	index = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	if (!n)
		return (0);
	while (s1c[index] == s2c[index] && s1c[index]
					&& s2c[index] && (index < (n - 1)))
		index++;
	return (s1c[index] - s2c[index]);
}
