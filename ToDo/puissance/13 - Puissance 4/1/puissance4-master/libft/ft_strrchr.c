/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:07:28 by telain            #+#    #+#             */
/*   Updated: 2015/12/02 18:44:10 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (c == '\0')
		return ((char*)str + i + 1);
	while (str[i])
	{
		if (str[i] == c)
			return ((char*)str + i);
		i--;
	}
	return (NULL);
}
