/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:37:54 by dtedgui           #+#    #+#             */
/*   Updated: 2015/11/25 15:17:49 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	temp;

	i = 0;
	length = ft_strlen(str);
	while (i < (length / 2))
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		i++;
	}
	str[length] = '\0';
	return (str);
}
