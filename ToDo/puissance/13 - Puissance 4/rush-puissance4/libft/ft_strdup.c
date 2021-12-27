/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:13:38 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/03 14:17:00 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc(sizeof(*s2) * ft_strlen(s1) + 1);
	if (s2)
	{
		ft_strcpy(s2, s1);
		return (s2);
	}
	return (NULL);
}
