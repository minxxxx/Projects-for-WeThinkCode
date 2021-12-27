/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_justify_right.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 18:05:58 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/19 18:07:26 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr_justify_right(int number
											, size_t total
											, char fill)
{
	char			*string;

	string = ft_itoa(number);
	ft_putstr_justify_right(string, total, fill);
	free(string);
}
