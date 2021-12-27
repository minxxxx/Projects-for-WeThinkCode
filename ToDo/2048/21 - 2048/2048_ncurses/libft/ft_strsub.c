/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:35:19 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/27 14:30:19 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	index;

	index = 0;
	if (s == NULL)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (index < len)
	{
		ret[index] = s[start];
		start++;
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
