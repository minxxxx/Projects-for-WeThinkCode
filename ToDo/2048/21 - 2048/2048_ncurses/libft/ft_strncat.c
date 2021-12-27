/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 11:54:27 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/24 08:20:19 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t		s1_index;
	size_t		s2_index;

	s1_index = ft_strlen(s1);
	s2_index = -1;
	while (s2[++s2_index] && s2_index < n)
	{
		s1[s1_index] = s2[s2_index];
		s1_index++;
	}
	s1[s1_index] = '\0';
	return (s1);
}
