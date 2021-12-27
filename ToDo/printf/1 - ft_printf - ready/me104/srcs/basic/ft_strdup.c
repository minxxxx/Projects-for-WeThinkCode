/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:26:35 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 16:32:26 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = 0;
	if (!src)
	{
		if ((str = malloc(sizeof(char) * (2))) == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	while (src[i] != '\0')
		++i;
	if ((str = malloc(sizeof(char) * (i + 2))) == NULL)
		return (NULL);
	i = -1;
	while (src[++i] != '\0')
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
