/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnwlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:32:54 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 14:57:10 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnwlen(wchar_t *s, size_t len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && len-- > 0)
	{
		if (s[i] <= 0x7F)
			count += 1;
		else if (s[i] <= 0x7FF)
			count += 2;
		else if (s[i] <= 0xFFFF)
			count += 3;
		else
			count += 4;
		i++;
	}
	return (count);
}
