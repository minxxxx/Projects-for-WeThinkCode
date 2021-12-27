/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_it_bro.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:15:31 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:15:33 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_handle_mod_j(va_list *arg, t_info *info)
{
	if (MOD == MOD_J)
	{
		if (SPEC == 'd')
			return (ft_print_intmax_t(arg, info));
		else if (SPEC == 'D')
			return (ft_print_unsigned_short(arg, info));
		else if (SPEC == 'o')
			return (ft_print_oct_long_long(arg, info));
		else if (SPEC == 'O')
			return (ft_print_oct_short(arg, info));
		else if (SPEC == 'u')
			return (ft_print_uintmax_t(arg, info));
		else if (SPEC == 'U')
			return (ft_print_unsigned_short(arg, info));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_long_long(arg, info));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_long_long(arg, info));
	}
	return (ft_handle_mod_z(arg, info));
}

static size_t	ft_handle_mod_h(va_list *arg, t_info *info)
{
	if (MOD == MOD_H)
	{
		if (SPEC == 'd')
			return (ft_print_short(arg, info));
		else if (SPEC == 'D' || SPEC == 'u')
			return (ft_print_unsigned_short(arg, info));
		else if (SPEC == 'U')
			return (ft_print_unsigned_long(arg, info));
		else if (SPEC == 'o')
			return (ft_print_oct_short(arg, info));
		else if (SPEC == 'O')
			return (ft_print_oct_long(arg, info));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_short(arg, info));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_short(arg, info));
	}
	return (ft_handle_mod_j(arg, info));
}

static size_t	ft_handle_mod_l(va_list *arg, t_info *info)
{
	if (MOD == MOD_L || (MOD == NO_MOD && (SPEC == 'C' || SPEC == 'S' ||
					SPEC == 'D' || SPEC == 'U' || SPEC == 'O')))
	{
		if (SPEC == 'c' || SPEC == 'C')
			return (ft_print_wchar(arg, info));
		else if (SPEC == 's' || SPEC == 'S')
			return (ft_print_wstr(arg, info));
		else if (SPEC == 'd' || SPEC == 'D')
			return (ft_print_long(arg, info));
		else if (SPEC == 'u' || SPEC == 'U')
			return (ft_print_unsigned_long(arg, info));
		else if (SPEC == 'o' || SPEC == 'O')
			return (ft_print_oct_long(arg, info));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_long(arg, info));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_long(arg, info));
	}
	return (ft_handle_mod_h(arg, info));
}

size_t			ft_handle_spec(va_list *arg, t_info *info)
{
	SPEC == 'i' ? SPEC = 'd' : SPEC;
	if (MOD == NO_MOD)
	{
		if (SPEC == 'p')
			return (ft_print_pointer(arg, info));
		if (SPEC == '%')
			return (ft_print_percent(info));
		else if (SPEC == 'c')
			return (ft_print_char(arg, info));
		else if (SPEC == 's')
			return (ft_print_str(arg, info));
		else if (SPEC == 'd')
			return (ft_print_int(arg, info));
		else if (SPEC == 'u')
			return (ft_print_unsigned_int(arg, info));
		else if (SPEC == 'x')
			return (ft_print_hex_lower(arg, info));
		else if (SPEC == 'X')
			return (ft_print_hex_upper(arg, info));
		else if (SPEC == 'o')
			return (ft_print_oct(arg, info));
	}
	return (ft_handle_mod_l(arg, info));
}
