/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:29:00 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 16:32:35 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		++ptr;
	while (nb && (*ptr++ = *src++))
		--nb;
	if (nb <= 0)
		*ptr = '\0';
	return (dest);
}
