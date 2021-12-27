/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:16:15 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/22 19:04:01 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s12;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	len2 = 0;
	if (s1 != NULL)
		k = ft_strlen(s1);
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	len1 = k + len2 + 1;
	if (!(s12 = ft_strnew(len1)))
		return (NULL);
	len1 = 0;
	while (k--)
		s12[i++] = s1[len1++];
	k = 0;
	while (len2--)
		s12[i++] = s2[k++];
	s12[i] = '\0';
	return (s12);
}
