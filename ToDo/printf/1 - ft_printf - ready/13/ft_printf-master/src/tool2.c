/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:37:01 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/10 11:12:22 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char a)
{
	if (a == '#' || a == '0' || a == '-' || a == '+' || a == ' ')
		return (1);
	return (0);
}

int	is_number(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int	is_precision(char a)
{
	if (a == '.')
		return (1);
	return (0);
}

int	is_lmodifier(char a)
{
	if (a == 'h' || a == 'l' || a == 'j' || a == 'z')
		return (1);
	return (0);
}

int	is_conversion(char a)
{
	if (a == 's' || a == 'S' || a == 'p' || a == 'd'
	|| a == 'D' || a == 'o' || a == 'O' || a == 'u'
	|| a == 'U' || a == 'x' || a == 'X' || a == 'c'
	|| a == 'C' || a == '%' || a == 'i')
		return (1);
	return (0);
}
