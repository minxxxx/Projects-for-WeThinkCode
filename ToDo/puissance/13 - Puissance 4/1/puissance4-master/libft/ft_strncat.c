/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:12:50 by telain            #+#    #+#             */
/*   Updated: 2015/12/02 15:07:34 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str, const char *str2, size_t n)
{
	char	*cur;

	cur = str;
	while (*cur != '\0')
	{
		cur++;
	}
	while (*str2 != '\0' && n > 0)
	{
		*cur = *str2;
		cur++;
		str2++;
		n--;
	}
	*cur = '\0';
	return (str);
}
