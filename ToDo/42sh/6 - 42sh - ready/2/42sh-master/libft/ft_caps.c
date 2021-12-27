/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:06:21 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:06:38 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupr(char *str)
{
	char	*temp;
	int		i;
	int		n;

	i = ft_strlen(str);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	i = -1;
	n = 0;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			temp[n] = str[i] - 32;
		else
			temp[n] = str[i];
		n++;
	}
	temp[n] = '\0';
	ft_strdel(&str);
	return (temp);
}
