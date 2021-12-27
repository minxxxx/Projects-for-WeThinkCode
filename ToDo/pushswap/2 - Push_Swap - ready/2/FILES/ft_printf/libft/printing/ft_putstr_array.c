/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:52:32 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/06 16:52:35 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_array(char **array, char sep)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_putstr(array[i]);
		if (array[i + 1] || sep == '\n')
			ft_putchar(sep);
		i++;
	}
}
