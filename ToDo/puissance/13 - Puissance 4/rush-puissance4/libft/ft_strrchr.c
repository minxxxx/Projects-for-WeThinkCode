/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:23:47 by pmartine          #+#    #+#             */
/*   Updated: 2015/11/27 19:30:58 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen(s);
	while (i > 0 && (char)c != s[i])
		i--;
	if ((char)c == s[i])
		return ((char *)s + i);
	if ((char)c == s[0])
		return ((char *)s);
	return (NULL);
}
