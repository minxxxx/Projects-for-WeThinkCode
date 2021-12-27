/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:09:46 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/07 16:21:54 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_striteri(char *string, void (*func)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (string[i])
	{
		func(i, string + i);
		i++;
	}
}
