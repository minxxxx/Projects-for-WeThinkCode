/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 23:16:20 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/26 13:12:44 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*temp;
	unsigned char		*a;
	size_t				i;

	if (src == NULL || len == 0 || dst == NULL)
		return (dst);
	if ((temp = (unsigned char *)malloc(sizeof(temp) * len)) == NULL)
		return (NULL);
	i = 0;
	a = (unsigned char *)src;
	while (a[i] && i < len)
	{
		temp[i] = a[i];
		i++;
	}
	i = 0;
	a = (unsigned char *)dst;
	while (a[i] && i < len)
	{
		a[i] = temp[i];
		i++;
	}
	return (dst);
}
