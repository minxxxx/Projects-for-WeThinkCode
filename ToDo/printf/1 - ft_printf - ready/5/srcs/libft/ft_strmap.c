/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:30:43 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:31:18 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (0);
	str = ft_strnew(ft_strlen(s));
	if (str)
	{
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
	}
	return (str);
}
