/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary_char_hhb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:16:45 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:16:47 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_binary_to_print(unsigned char b, int size,
		t_info *info)
{
	size_t			len;
	int				add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	ft_oct_flags_left(size, add_precision, info);
	ft_oct_flags_right(size, info);
	LEFT_Z += add_precision;
	RIGHT_B -= add_precision;
	len += ft_oct_print_left(size, info);
	ft_print_binary(b);
	len += ft_oct_print_right(info);
	return (len);
}

size_t				ft_print_binary_char(va_list *arg, t_info *info)
{
	size_t			b;
	size_t			len;
	int				size;

	len = 0;
	b = va_arg(*arg, size_t);
	if (b == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		if (SHARP)
		{
			ft_putchar('0');
			len++;
		}
		return (len + WIDTH);
	}
	if (b == 0)
	{
		ft_putchar('0');
		return (len = 1);
	}
	size = ft_binary_size((unsigned char)b);
	len += size;
	len += ft_binary_to_print(b, size, info);
	return (len);
}
