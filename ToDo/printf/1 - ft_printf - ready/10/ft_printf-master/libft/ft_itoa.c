/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:13:02 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/19 18:24:36 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		write_chars(char *first, char *now, int number)
{
	while (now >= first)
	{
		*now = number % 10 + '0';
		number /= 10;
		now--;
	}
}

char			*ft_itoa(int number)
{
	char	*new;
	int		length;

	if (number == -2147483648)
		return (ft_strdup("-2147483648"));
	if (number == 0)
		return (ft_strdup("0"));
	length = ft_count_digits(number);
	new = malloc(sizeof(char) * (length + (number < 0) + 1));
	if (number < 0)
	{
		new[0] = '-';
		write_chars(new + 1, new + length, 0 - number);
		new[length + 1] = '\0';
	}
	else
	{
		write_chars(new, new + length - 1, number);
		new[length] = '\0';
	}
	return (new);
}
