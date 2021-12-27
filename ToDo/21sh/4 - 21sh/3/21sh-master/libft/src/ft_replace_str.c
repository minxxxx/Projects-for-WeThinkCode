/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 17:17:05 by fkoehler          #+#    #+#             */
/*   Updated: 2016/08/15 18:41:13 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace_str(const char *s1, unsigned int start, size_t len,
		const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(s3 = (char *)malloc(sizeof(*s3) * (s1_len - len + s2_len + 1))))
		return (NULL);
	ft_memcpy((void *)s3, (void *)s1, start);
	ft_memcpy((void *)&s3[start], (void *)s2, s2_len);
	ft_memcpy((void *)&s3[start + s2_len], (void *)&s1[start + len],
	s1_len - len - start + 1);
	s3[s1_len - len + s2_len] = 0;
	return (s3);
}
