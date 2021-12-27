/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:13:25 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/22 15:31:51 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*tmp_s1;
	unsigned const char	*tmp_s2;

	tmp_s1 = s1;
	tmp_s2 = s2;
	while (n-- != 0)
	{
		if (*tmp_s2 != (unsigned char)c)
		{
			*tmp_s1++ = *tmp_s2++;
		}
		else
		{
			*tmp_s1++ = *tmp_s2++;
			return (tmp_s1);
		}
	}
	return (NULL);
}
