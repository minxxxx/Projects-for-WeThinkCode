/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 15:25:59 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/11 22:29:17 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** writes digits recursively, starting at the last digit of the number
*/

#include "libft.h"

static void			write_digits(char *current, uintmax_t number)
{
	while (number)
	{
		*current = number % 10 + '0';
		number /= 10;
		current--;
	}
}

void				ft_itoa_write(char *last_digit, uintmax_t number)
{
	if (number == 0)
		*last_digit = '0';
	else
		write_digits(last_digit, number);
}
