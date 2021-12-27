/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uintmax_t_ju.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:21:23 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:21:24 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_to_print(uintmax_t nb, int size, t_info *info)
{
	size_t		len;
	int			add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	ft_uint_flags_left(size, add_precision, info);
	ft_uint_flags_right(size, info);
	LEFT_Z += add_precision;
	RIGHT_B -= add_precision;
	len += ft_uint_print_left(info);
	ft_putnbr_st(nb);
	len += ft_uint_print_right(info);
	return (len);
}

size_t			ft_print_uintmax_t(va_list *arg, t_info *info)
{
	uintmax_t	nb;
	int			size;
	size_t		len;

	len = 0;
	nb = va_arg(*arg, uintmax_t);
	if (nb == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		return (len = WIDTH);
	}
	size = ft_uint_size(nb);
	len += size;
	len += ft_int_to_print(nb, size, info);
	return (len);
}
