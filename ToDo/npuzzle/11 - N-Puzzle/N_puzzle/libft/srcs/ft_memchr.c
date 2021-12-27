/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 07:21:50 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/14 08:02:05 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*temp;

	temp = s;
	while (n-- != 0)
	{
		if (*temp == (unsigned char)c)
			return ((void *)temp);
		else
			temp++;
	}
	return (NULL);
}
