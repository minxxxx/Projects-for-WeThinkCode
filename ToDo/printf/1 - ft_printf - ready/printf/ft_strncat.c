/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:03:44 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/09 16:10:21 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t len)
{
	int			i;
	int			j;
	size_t		a;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	a = 0;
	while (s2[j] && a < len)
	{
		s1[i] = s2[j];
		i++;
		j++;
		a++;
	}
	s1[i] = '\0';
	return (s1);
}
