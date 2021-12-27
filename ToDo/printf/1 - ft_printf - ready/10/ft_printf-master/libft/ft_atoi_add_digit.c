/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_add_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 15:24:51 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/08 15:24:53 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** adds a single digit to a number;  be used in atoi implementations
*/

void				ft_atoi_add_digit(const char c, int *number)
{
	if (*number)
		*number *= 10;
	*number += c - '0';
}
