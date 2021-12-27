/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_char_hhx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:17:31 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:17:33 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_hex_to_print(unsigned char x, int size, t_info *info)
{
	size_t			len;
	int				add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	ft_hex_flags_left(size, add_precision, info);
	ft_hex_flags_right(size, info);
	LEFT_Z += add_precision;
	RIGHT_B -= add_precision;
	len += ft_hex_print_left(info);
	ft_print_hex(x, HEX_UPPER);
	len += ft_hex_print_right(info);
	return (len);
}

size_t				ft_print_hex_upper_char(va_list *arg, t_info *info)
{
	size_t			x;
	size_t			len;
	int				size;

	len = 0;
	HEX_UPPER = 1;
	x = va_arg(*arg, size_t);
	if (x == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		return (len = WIDTH);
	}
	if (x == 0)
		SHARP = 0;
	size = ft_hex_size((unsigned char)x);
	len += size;
	len += ft_hex_to_print(x, size, info);
	return (len);
}

size_t				ft_print_hex_lower_char(va_list *arg, t_info *info)
{
	size_t			x;
	size_t			len;
	int				size;

	len = 0;
	x = va_arg(*arg, size_t);
	if (x == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		return (len = WIDTH);
	}
	if (x == 0)
		SHARP = 0;
	size = ft_hex_size((unsigned char)x);
	len += size;
	len += ft_hex_to_print(x, size, info);
	return (len);
}
