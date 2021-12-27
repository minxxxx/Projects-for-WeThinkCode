/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:18:51 by pmartine          #+#    #+#             */
/*   Updated: 2015/11/29 18:04:12 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 || s2 || n)
	{
		while (n > 0)
		{
			if (*s1 != *s2)
			{
				if ((unsigned char)*s1 > (unsigned char)*s2)
					return (1);
				else
					return (-1);
			}
			if (*s1 == '\0')
				return (0);
			n--;
			s1++;
			s2++;
		}
	}
	return (0);
}
