/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_t_ls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:22:27 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:22:27 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wstr_to_print(wchar_t *s, int size, t_info *info)
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
	ft_putwstr(s);
	len += ft_char_print_right(info);
	return (len);
}

size_t			ft_print_wstr(va_list *arg, t_info *info)
{
	wchar_t		*s;
	size_t		len;
	int			size;

	len = 0;
	s = va_arg(*arg, wchar_t*);
	if (s == NULL && !IS_PRECISION)
	{
		ft_putstr("(null)");
		return (6);
	}
	size = ft_wstr_size(s);
	len += size;
	len += ft_wstr_to_print(s, size, info);
	return (len);
}
