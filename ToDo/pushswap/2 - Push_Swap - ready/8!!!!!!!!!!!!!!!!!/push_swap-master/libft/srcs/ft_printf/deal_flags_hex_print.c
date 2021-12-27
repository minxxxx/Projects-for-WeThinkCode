/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_flags_hex_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:14:39 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:14:41 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_hex_print_flag(t_info *info)
{
	size_t		len;

	len = 0;
	if (HEX_UPPER)
	{
		ft_putstr("0X");
		len += 2;
	}
	else
	{
		ft_putstr("0x");
		len += 2;
	}
	return (len);
}

size_t			ft_hex_print_right(t_info *info)
{
	size_t		len;

	len = 0;
	if (RIGHT_B > 0)
	{
		ft_print_blanks(RIGHT_B);
		len += RIGHT_B;
	}
	return (len);
}

static size_t	ft_hex_print_left_end(t_info *info)
{
	size_t		len;

	len = 0;
	if (!SHARP && LEFT_B > 0)
	{
		ft_print_blanks(LEFT_B);
		len += LEFT_B;
	}
	if (!SHARP && LEFT_Z > 0)
	{
		ft_print_zeros(LEFT_Z);
		len += LEFT_Z;
	}
	return (len);
}

size_t			ft_hex_print_left(t_info *info)
{
	size_t		len;

	len = 0;
	if (SHARP)
	{
		if ((ZERO || LEFT_Z) && !MINUS)
		{
			ft_print_blanks(LEFT_B);
			len += ft_hex_print_flag(info);
			ft_print_zeros(LEFT_Z);
			len += LEFT_Z + LEFT_B;
		}
		else if (MINUS)
		{
			len += ft_hex_print_flag(info);
			ft_print_blanks(LEFT_B);
			len += LEFT_B;
		}
		else
		{
			ft_print_blanks(LEFT_B);
			len += ft_hex_print_flag(info) + LEFT_B;
		}
	}
	return (len + ft_hex_print_left_end(info));
}
