/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 10:37:30 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/25 16:59:14 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		index;

	index = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[index])
	{
		(*f)(index, &s[index]);
		index++;
	}
}
