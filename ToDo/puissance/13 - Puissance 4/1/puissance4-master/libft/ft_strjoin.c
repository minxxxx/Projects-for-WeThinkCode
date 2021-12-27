/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:45:29 by telain            #+#    #+#             */
/*   Updated: 2015/12/17 17:40:13 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len1;
	int		len2;
	int		i;

	i = 0;
	len2 = ft_strlen(s2);
	len1 = ft_strlen(s1);
	if (!(new = malloc(sizeof(char) * (len1 + len2))))
		return (NULL);
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len1 + len2)
	{
		new[i + len1] = s2[i];
		i++;
	}
	return (new);
}
