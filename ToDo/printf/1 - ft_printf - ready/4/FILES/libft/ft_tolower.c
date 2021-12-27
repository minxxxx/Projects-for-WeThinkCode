/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:15 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/27 16:31:55 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tolower(char *str)
{
	char	*lowered;
	int		i;

	lowered = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			lowered[i] = str[i] + 32;
		else
			lowered[i] = str[i];
		i++;
	}
	return (lowered);
}
