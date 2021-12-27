/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_char_hhd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:20:58 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:20:59 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_int_to_print(signed int nb, ssize_t i, int size,
		t_info *info)
{
	size_t			len;
	int				add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	ft_int_flags_left(nb, size, add_precision, info);
	ft_int_flags_right(size, info);
	LEFT_Z += add_precision;
	RIGHT_B -= add_precision;
	len += ft_int_print_left(nb, info);
	if (i == 128 || i == -127)
		ft_putstr("128");
	else
		(nb < 0) ? ft_putnbr_sst(-nb) : ft_putnbr_sst(nb);
	len += ft_int_print_right(info);
	return (len);
}

size_t				ft_print_signed_char(va_list *arg, t_info *info)
{
	signed char		nb;
	ssize_t			i;
	int				size;
	size_t			len;

	len = 0;
	i = va_arg(*arg, ssize_t);
	nb = (signed char)i;
	if (nb == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		return (len = WIDTH);
	}
	size = ft_int_size(nb);
	len += size;
	len += ft_int_to_print(nb, i, size, info);
	return (len);
}
