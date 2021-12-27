/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 09:55:40 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/11 10:00:31 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && (unsigned char)s1[i] != '\0' && (unsigned char)s2 != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (0);
		i++;
	}
	return (1);
}
