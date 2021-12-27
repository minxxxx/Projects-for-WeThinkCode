/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:44:00 by wide-aze          #+#    #+#             */
/*   Updated: 2015/08/13 22:24:06 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len_s1;
	size_t		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s2 == 0)
		return ((char*)s1);
	if (len_s1 < n)
		n = len_s1;
	while (*s1 && n && n >= len_s2)
	{
		if (ft_strncmp(s1, s2, len_s2) == 0)
			return ((char*)s1);
		s1++;
		n--;
	}
	return (NULL);
}
