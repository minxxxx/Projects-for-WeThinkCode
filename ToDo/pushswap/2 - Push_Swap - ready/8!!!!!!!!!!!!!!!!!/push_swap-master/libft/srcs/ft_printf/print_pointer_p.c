/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:20:47 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:20:48 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_pointer_to_print(size_t p, int size, t_info *info)
{
	size_t			len;
	int				add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	SHARP = 1;
	ft_hex_flags_left(size, add_precision, info);
	ft_hex_flags_right(size, info);
	LEFT_Z += add_precision;
	RIGHT_B -= add_precision;
	len += ft_hex_print_left(info);
	ft_print_hex(p, HEX_UPPER);
	len += ft_hex_print_right(info);
	return (len);
}

size_t				ft_print_pointer(va_list *arg, t_info *info)
{
	size_t			p;
	size_t			len;
	int				size;

	len = 0;
	p = va_arg(*arg, size_t);
	if (p == 0 && IS_PRECISION)
	{
		ft_print_blanks(LEFT_B);
		ft_putstr("0x");
		ft_print_zeros(PRECISION);
		return (len = LEFT_B + PRECISION + 2);
	}
	size = ft_hex_size(p);
	len += size;
	len += ft_pointer_to_print(p, size, info);
	return (len);
}
