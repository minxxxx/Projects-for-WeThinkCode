/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:31:11 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/08 15:21:57 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		index;

	index = 0;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	while (index < size)
	{
		str[index] = '\0';
		index++;
	}
	str[index] = '\0';
	return (str);
}
