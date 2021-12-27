/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_ularge.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 00:03:26 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/11 23:00:53 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digits_ularge(uintmax_t number)
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
