/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:06:46 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:06:50 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_delarray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_strdel(&array[i]);
		i++;
	}
	free(array);
}
