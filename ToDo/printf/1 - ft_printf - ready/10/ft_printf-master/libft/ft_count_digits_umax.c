/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_umax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 00:03:26 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/22 00:05:03 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digits_umax(uintmax_t number)
{
	int	count;

	if (number == 0)
		return (1);
	count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}
