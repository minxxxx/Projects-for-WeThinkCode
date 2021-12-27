/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:42:34 by thendric          #+#    #+#             */
/*   Updated: 2016/11/02 14:46:32 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = s1;
	while (*s1)
		s1++;
	while (*s2 && i < n)
	{
		*s1++ = *s2++;
		i++;
	}
	*s1 = '\0';
	return (dst);
}
