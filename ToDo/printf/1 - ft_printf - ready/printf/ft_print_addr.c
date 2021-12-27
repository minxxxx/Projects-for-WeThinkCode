/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 10:39:43 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/24 11:12:11 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_print_addr(void **ptr)
{
	write(1, "0x", 2);
	write(1, "7fff", 4);
	ft_putstr(ft_uni_convert((unsigned int)&(*ptr), 16));
}
