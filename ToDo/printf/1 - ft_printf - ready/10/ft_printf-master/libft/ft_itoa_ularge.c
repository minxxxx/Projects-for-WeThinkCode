/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ularge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 21:04:27 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/11 20:21:32 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		write_chars(char *first, char *now, uintmax_t number)
{
	while (now >= first)
	{
		*now = number % 10 + '0';
		number /= 10;
		now--;
	}
}

char			*ft_itoa_ularge(uintmax_t number)
{
	char	*new;
	int		length;

	if (number == 0)
		return (ft_strdup("0"));
	length = ft_count_digits_ularge(number);
	new = malloc(sizeof(char) * (length + 1));
	write_chars(new, new + length - 1, number);
	new[length] = '\0';
	return (new);
}
