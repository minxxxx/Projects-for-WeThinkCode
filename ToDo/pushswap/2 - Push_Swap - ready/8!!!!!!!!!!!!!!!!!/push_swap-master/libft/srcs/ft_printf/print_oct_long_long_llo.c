/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct_long_long_llo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:19:45 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:19:46 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_oct_to_print(unsigned long long int o, int size,
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
	ft_print_octal(o);
	len += ft_oct_print_right(info);
	return (len);
}

size_t				ft_print_oct_long_long(va_list *arg, t_info *info)
{
	size_t			o;
	size_t			len;
	int				size;

	len = 0;
	o = va_arg(*arg, size_t);
	if (o == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		if (SHARP)
		{
			ft_putchar('0');
			len++;
		}
		return (len + WIDTH);
	}
	if (o == 0)
		SHARP = 0;
	size = ft_oct_size((unsigned long long int)o);
	len += size;
	len += ft_oct_to_print(o, size, info);
	return (len);
}
