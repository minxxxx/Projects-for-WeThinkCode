/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:43:02 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/29 23:59:48 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*new;
	char	*ptr;

	len = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new = ft_strnew(len);
	ptr = new;
	if (!new)
		return (NULL);
	while (*s)
	{
		*ptr = f(*s);
		++s;
		++ptr;
	}
	return (new);
}
