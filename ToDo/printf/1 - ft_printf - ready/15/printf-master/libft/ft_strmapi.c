/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:43:02 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/29 23:59:57 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*new;
	unsigned int	index;

	len = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new = ft_strnew(len);
	index = 0;
	if (!new)
		return (NULL);
	while (s[index])
	{
		new[index] = f(index, s[index]);
		++index;
	}
	return (new);
}
