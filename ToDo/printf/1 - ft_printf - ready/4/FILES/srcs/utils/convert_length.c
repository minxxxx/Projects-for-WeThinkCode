/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 16:58:51 by antoinebungert    #+#    #+#             */
/*   Updated: 2016/01/26 16:55:45 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		get_unsigned_length(uintmax_t nbr, t_tag *tag)
{
	if (tag->length == 1)
		nbr = (unsigned short int)nbr;
	else if (tag->length == 2)
		nbr = (unsigned char)nbr;
	else if (tag->length == 3)
		nbr = (unsigned long int)nbr;
	else if (tag->length == 4)
		nbr = (unsigned long long int)nbr;
	else if (tag->length == 5)
		nbr = (uintmax_t)nbr;
	else if (tag->length == 6)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

intmax_t		get_signed_length(intmax_t nbr, t_tag *tag)
{
	if (tag->length == 1)
		nbr = (short int)nbr;
	else if (tag->length == 2)
		nbr = (char)nbr;
	else if (tag->length == 3)
		nbr = (long int)nbr;
	else if (tag->length == 4)
		nbr = (long long int)nbr;
	else if (tag->length == 5)
		nbr = (intmax_t)nbr;
	else if (tag->length == 6)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}
