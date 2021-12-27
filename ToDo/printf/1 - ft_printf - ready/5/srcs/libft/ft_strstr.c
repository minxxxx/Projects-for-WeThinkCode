/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:58:51 by thendric          #+#    #+#             */
/*   Updated: 2016/11/07 10:43:08 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*b;
	const char	*l;

	if (!*little && !little)
		return ((char *)big);
	if (*big == *little && *big == '\0')
		return ((char*)big);
	while (*big)
	{
		b = big;
		l = little;
		while (*b && (*b == *l))
		{
			b++;
			l++;
		}
		if (!*l)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
