/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:18:48 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:31:42 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (0);
	i = 0;
	str = ft_strnew(ft_strlen(s));
	if (str)
	{
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
	}
	return (str);
}
