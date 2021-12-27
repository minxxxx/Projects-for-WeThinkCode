/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 07:41:18 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/21 11:30:07 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*re;
	int		i;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(re = (char *)malloc((sizeof(char) * size))))
		return (NULL);
	i = 0;
	while (*s1 && i < size)
		re[i++] = *s1++;
	while (*s2 && i < size)
		re[i++] = *s2++;
	re[i] = '\0';
	return (re);
}
