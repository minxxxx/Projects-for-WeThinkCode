/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:07:41 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/10 12:55:46 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			i;

	i = 0;
	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str)
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
			return (str);
		}
	}
	return (0);
}
