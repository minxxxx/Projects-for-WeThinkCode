/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 11:42:41 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/24 08:07:58 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		index;
	char	*copy;

	index = -1;
	copy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (copy != NULL)
	{
		while (s1[++index])
			copy[index] = s1[index];
		copy[index] = '\0';
	}
	return (copy);
}
