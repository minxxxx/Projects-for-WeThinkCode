/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:01:05 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:01:05 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	b;

	b = 0;
	if (s && f)
	{
		new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (new == NULL)
			return (NULL);
		while (b < ft_strlen(s))
		{
			new[b] = f(b, s[b]);
			b++;
		}
		new[b] = '\0';
		return (new);
	}
	return (NULL);
}
