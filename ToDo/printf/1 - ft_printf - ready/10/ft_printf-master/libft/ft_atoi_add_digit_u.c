/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_add_digit_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:47:04 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/26 18:49:00 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** adds a single digit to a number;  be used in atoi implementations
*/

void				ft_atoi_add_digit_u(const char c, unsigned int *number)
{
	if (*number)
		*number *= 10;
	*number += c - '0';
}
