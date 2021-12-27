/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_add_digit_large.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 15:25:00 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/12 14:37:51 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** adds a single digit to a number;  be used in atoi implementations
*/

void				ft_atoi_add_digit_large(const char c, intmax_t *number)
{
	if (*number)
		*number *= 10;
	*number += c - '0';
}
