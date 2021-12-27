/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 05:18:05 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/04 21:49:33 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				erase_char(char **str, char c, int start)
{
	char	*tmp;
	char	*tmp2;
	int		i;
	int		k;

	i = 0;
	k = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1));
	tmp2 = ft_strdup(*str);
	while (tmp2[k])
	{
		if (tmp2[k] == c && k != start)
			k++;
		else
		{
			tmp[i] = tmp2[k];
			i++;
			k++;
		}
	}
	tmp[i] = '\0';
	ft_memdel((void **)str);
	ft_memdel((void **)&tmp2);
	*str = tmp;
}
