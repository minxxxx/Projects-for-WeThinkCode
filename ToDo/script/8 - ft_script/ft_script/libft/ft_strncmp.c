/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:22:21 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/09 17:09:54 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 1;
	if (n == 0)
		return (0);
	while ((*str1 == *str2) && (*str1) && (*str2) && (i < n))
	{
		str1++;
		str2++;
		i++;
	}
	return (*str1 - *str2);
}
