/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 18:52:45 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/26 14:33:22 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				index;
	unsigned char	*s1c;
	unsigned char	*s2c;

	index = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (s1c[index] && s2c[index] && s1c[index] == s2c[index])
		index++;
	return (s1c[index] - s2c[index]);
}
