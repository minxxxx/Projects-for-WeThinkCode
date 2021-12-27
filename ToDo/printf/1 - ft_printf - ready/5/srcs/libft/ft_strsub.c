/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:36:19 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:36:15 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	str = ft_strnew(len);
	if (str)
	{
		while (len > 0)
		{
			str[i] = s[start++];
			i++;
			len--;
		}
		str[i] = '\0';
	}
	return (str);
}
