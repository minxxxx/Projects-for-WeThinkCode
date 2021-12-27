/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:04:27 by dtedgui           #+#    #+#             */
/*   Updated: 2016/02/01 11:23:35 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_nbrlen(long nb, long base)
{
	long	length;

	length = 1;
	while (ft_power_long(base, length) <= nb)
		length++;
	return (length);
}
