/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 11:07:20 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/23 12:26:37 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	if (!(ret = (char*)malloc(size + 1)))
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
