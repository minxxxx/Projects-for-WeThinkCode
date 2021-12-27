/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 12:23:47 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/23 18:30:48 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	size;

	if (s1 == NULL || s2 == NULL || n == 0)
		return (s1);
	size = ft_strlen(s1);
	ft_strncpy(&s1[size], s2, n);
	return (s1);
}
