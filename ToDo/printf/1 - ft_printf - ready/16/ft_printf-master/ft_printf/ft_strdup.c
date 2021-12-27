/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:16:19 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/07 14:44:07 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(char *src)
{
	int		index;
	char	*line;

	index = 0;
	if (src == NULL)
		return (NULL);
	while (src[index] != '\0')
		index++;
	line = (char*)malloc(sizeof(char) * index + 1);
	if (line == NULL)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		line[index] = src[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}
