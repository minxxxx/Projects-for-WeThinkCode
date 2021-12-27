/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_strlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 21:09:36 by fkoehler          #+#    #+#             */
/*   Updated: 2016/08/26 21:38:28 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_multi_strlen(char **array)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}
