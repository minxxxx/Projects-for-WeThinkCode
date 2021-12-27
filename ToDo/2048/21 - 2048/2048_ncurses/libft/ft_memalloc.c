/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 11:01:14 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/23 12:16:45 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	if (size == 0)
		return (NULL);
	if (!(ret = (void*)(malloc(size))))
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
