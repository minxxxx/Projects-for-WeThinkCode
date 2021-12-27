/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 19:07:44 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/23 19:07:51 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size == 0 || (ptr = (void *)malloc(sizeof(ptr) * size)) == NULL)
		return (NULL);
	ptr = ft_memset(ptr, 0, size);
	return (ptr);
}
