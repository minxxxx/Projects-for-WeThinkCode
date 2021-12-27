/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:55:06 by jtranchi          #+#    #+#             */
/*   Updated: 2015/11/29 15:13:13 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (s1 && s2)
	{
		while (*s1 == *s2)
		{
			if (*s1 == '\0')
				return (0);
			s1++;
			s2++;
		}
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}
