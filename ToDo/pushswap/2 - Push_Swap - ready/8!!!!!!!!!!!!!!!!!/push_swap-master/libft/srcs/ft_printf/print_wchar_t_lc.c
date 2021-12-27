/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_t_lc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:22:19 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:22:20 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wchar_to_print(wchar_t c, int size, t_info *info)
{
	size_t		len;
	int			add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	ft_char_flags_left(size, info);
	ft_char_flags_right(size, info);
	RIGHT_B -= add_precision;
	len += ft_char_print_left(info);
	len += add_precision;
	ft_putwchar(c);
	len += ft_char_print_right(info);
	return (len);
}

size_t			ft_print_wchar(va_list *arg, t_info *info)
{
	wchar_t		c;
	size_t		len;
	int			size;

	len = 0;
	c = va_arg(*arg, wchar_t);
	size = ft_wchar_size(c);
	len += size;
	len += ft_wchar_to_print(c, size, info);
	return (len);
}
