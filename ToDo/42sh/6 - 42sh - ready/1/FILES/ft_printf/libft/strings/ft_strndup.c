/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:14:45 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/14 15:10:36 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	length;
	char	*str;

	if (!s1)
		return (NULL);
	length = ft_strlen(s1);
	if (n < length)
		length = n;
	if (!(str = (char*)malloc(length + 1)))
		return (NULL);
	ft_strncpy(str, s1, length);
	return (str);
}
