/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_it_bro_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:15:42 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:15:43 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_handle_binary(va_list *arg, t_info *info)
{
	if (SPEC == 'b')
		return (ft_print_binary_b(arg, info));
	else if (MOD == MOD_HH && (SPEC == 'b'))
		return (ft_print_binary_char(arg, info));
	else if (MOD == MOD_H && (SPEC == 'b'))
		return (ft_print_binary_short(arg, info));
	else if (MOD == MOD_L && (SPEC == 'b'))
		return (ft_print_binary_long(arg, info));
	else if (MOD == MOD_LL && (SPEC == 'b'))
		return (ft_print_binary_long_long(arg, info));
	return (0);
}

static size_t	ft_handle_mod_hh(va_list *arg, t_info *info)
{
	if (MOD == MOD_HH)
	{
		if (SPEC == 'C')
			return (ft_print_wchar(arg, info));
		else if (SPEC == 'S')
			return (ft_print_wstr(arg, info));
		else if (SPEC == 'd')
			return (ft_print_signed_char(arg, info));
		else if (SPEC == 'D')
			return (ft_print_unsigned_short(arg, info));
		else if (SPEC == 'o')
			return (ft_print_oct_char(arg, info));
		else if (SPEC == 'O')
			return (ft_print_oct_short(arg, info));
		else if (SPEC == 'u')
			return (ft_print_unsigned_char(arg, info));
		else if (SPEC == 'U')
			return (ft_print_unsigned_short(arg, info));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_char(arg, info));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_char(arg, info));
	}
	return (ft_handle_binary(arg, info));
}

static size_t	ft_handle_mod_ll(va_list *arg, t_info *info)
{
	if (MOD == MOD_LL)
	{
		if (SPEC == 'd' || SPEC == 'D')
			return (ft_print_long_long(arg, info));
		else if (SPEC == 'u' || SPEC == 'U')
			return (ft_print_unsigned_long_long(arg, info));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_long_long(arg, info));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_long_long(arg, info));
		else if (SPEC == 'o' || SPEC == 'O')
			return (ft_print_oct_long_long(arg, info));
	}
	return (ft_handle_mod_hh(arg, info));
}

size_t			ft_handle_mod_z(va_list *arg, t_info *info)
{
	if (MOD == MOD_Z)
	{
		if (SPEC == 'd')
			return (ft_print_long_long(arg, info));
		else if (SPEC == 'D')
			return (ft_print_unsigned_short(arg, info));
		else if (SPEC == 'u')
			return (ft_print_unsigned_long_long(arg, info));
		else if (SPEC == 'U')
			return (ft_print_unsigned_short(arg, info));
		else if (SPEC == 'o')
			return (ft_print_oct_long_long(arg, info));
		else if (SPEC == 'O')
			return (ft_print_oct_short(arg, info));
		else if (SPEC == 'x')
			return (ft_print_hex_lower_long_long(arg, info));
		else if (SPEC == 'X')
			return (ft_print_hex_upper_long_long(arg, info));
	}
	return (ft_handle_mod_ll(arg, info));
}
