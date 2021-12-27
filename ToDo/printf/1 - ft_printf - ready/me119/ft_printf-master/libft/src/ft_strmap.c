/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:45:04 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/10 11:53:28 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				str[i] = f(s[i]);
				i++;
			}
			return (str);
		}
	}
	return (0);
}
