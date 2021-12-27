/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:07:32 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/01 13:36:50 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!s1 || !s2 || n == 0)
		return (0);
	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (*ptr1 && *ptr2 && *ptr1 == *ptr2 && n > 0)
	{
		ptr1++;
		ptr2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*ptr1 - *ptr2);
}
