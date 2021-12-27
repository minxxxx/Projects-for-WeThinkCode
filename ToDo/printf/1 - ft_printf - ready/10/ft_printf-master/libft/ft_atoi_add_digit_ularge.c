/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_add_digit_ularge.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:39:06 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/12 14:39:18 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** adds a single digit to a number;  be used in atoi implementations
*/

void				ft_atoi_add_digit_ularge(const char c, uintmax_t *number)
{
	if (*number)
		*number *= 10;
	*number += c - '0';
}
