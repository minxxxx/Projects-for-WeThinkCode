/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:14:16 by fkoehler          #+#    #+#             */
/*   Updated: 2015/11/27 16:38:45 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	uc;
	char			*ptr;

	i = 0;
	uc = (char)c;
	ptr = (char *)b;
	while (len > 0)
	{
		ptr[i] = uc;
		len--;
		i++;
	}
	return (b);
}
