/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:41:29 by jcamhi            #+#    #+#             */
/*   Updated: 2016/01/18 23:17:04 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_with_l(const t_arg arg, va_list list)
{
	char	*ret;

	if (arg.conv == 'd' || arg.conv == 'D' || arg.conv == 'i')
		ret = ft_itoa_base_ll((long long)va_arg(list, long), 10);
	else if (arg.conv == 'o' || arg.conv == 'O')
		ret = ft_itoa_base_ull((unsigned long long)
				va_arg(list, unsigned long), 8);
	else if (arg.conv == 'u' || arg.conv == 'U')
		ret = ft_itoa_base_ull((unsigned long long)
				va_arg(list, unsigned long), 10);
	else if (arg.conv == 'x')
		ret = ft_itoa_base_ull((unsigned long long)
				va_arg(list, unsigned long), 16);
	else if (arg.conv == 'X')
		ret = ft_strtoupper(ft_itoa_base_ull((unsigned long long)
					va_arg(list, unsigned long), 16));
	else if (arg.conv == 'c')
		ret = ft_wchart_to_char(va_arg(list, wchar_t));
	else if (arg.conv == 's')
		ret = ft_wchart_to_str(va_arg(list, wchar_t*));
	else
		ret = ft_alloc_str("Error");
	return (ret);
}

static char	*ft_with_ll(const t_arg arg, va_list list)
{
	char	*ret;

	if (arg.conv == 'd' || arg.conv == 'D' || arg.conv == 'i')
		ret = ft_itoa_base_ll((long long)va_arg(list, long long), 10);
	else if (arg.conv == 'o' || arg.conv == 'O')
		ret = ft_itoa_base_ull((unsigned long long)
				va_arg(list, unsigned long long), 8);
	else if (arg.conv == 'u' || arg.conv == 'U')
		ret = ft_itoa_base_ull((unsigned long long)
				va_arg(list, unsigned long long), 10);
	else if (arg.conv == 'x')
		ret = ft_itoa_base_ull((unsigned long long)
				va_arg(list, unsigned long long), 16);
	else if (arg.conv == 'X')
		ret = ft_strtoupper(ft_itoa_base_ull((unsigned long long)
					va_arg(list, unsigned long long), 16));
	else
		ret = ft_alloc_str("Error");
	return (ret);
}

static char	*ft_with_hh(const t_arg arg, va_list list)
{
	char	*ret;

	if (arg.conv == 'd' || arg.conv == 'i')
		ret = ft_itoa_base_ll((long long)(signed char)va_arg(list, int), 10);
	else if (arg.conv == 'o')
		ret = ft_itoa_base_ull((unsigned long long)
				(unsigned char)va_arg(list, int), 8);
	else if (arg.conv == 'u')
		ret = ft_itoa_base_ull((unsigned long long)
				(unsigned char)va_arg(list, int), 10);
	else if (arg.conv == 'x')
		ret = ft_itoa_base_ull((unsigned long long)
				(unsigned char)va_arg(list, int), 16);
	else if (arg.conv == 'X')
		ret = ft_strtoupper(ft_itoa_base_ull((unsigned long long)
					(unsigned char)va_arg(list, int), 16));
	else
		ret = ft_alloc_str("Error");
	return (ret);
}

static char	*ft_with_h(const t_arg arg, va_list list)
{
	char	*ret;

	if (arg.conv == 'd' || arg.conv == 'D' || arg.conv == 'i')
		ret = ft_itoa_base_ll((long long)va_arg(list, int), 10);
	else if (arg.conv == 'o' || arg.conv == 'O')
		ret = ft_itoa_base_ull((unsigned long long)
				(unsigned short)va_arg(list, int), 8);
	else if (arg.conv == 'u' || arg.conv == 'U')
		ret = ft_itoa_base_ull((unsigned long long)
				va_arg(list, int), 10);
	else if (arg.conv == 'x')
		ret = ft_itoa_base_ull((unsigned long long)
				va_arg(list, int), 16);
	else if (arg.conv == 'X')
		ret = ft_strtoupper(ft_itoa_base_ull((unsigned long long)
					va_arg(list, int), 16));
	else
		ret = ft_alloc_str("Error");
	return (ret);
}

char		*init_ret(const t_arg arg, va_list list)
{
	char *ret;

	if (!is_conv(arg.conv))
		return (ft_with_no_lm(arg, list));
	if (ft_strequ(arg.lm, "ll"))
		ret = ft_with_ll(arg, list);
	else if (ft_strequ(arg.lm, "l"))
		ret = ft_with_l(arg, list);
	else if (ft_strequ(arg.lm, "hh"))
		ret = ft_with_hh(arg, list);
	else if (ft_strequ(arg.lm, "h"))
		ret = ft_with_h(arg, list);
	else if (ft_strequ(arg.lm, "j"))
		ret = ft_with_l(arg, list);
	else if (ft_strequ(arg.lm, "z"))
		ret = ft_with_z(arg, list);
	else
		ret = ft_with_no_lm(arg, list);
	return (ret);
}
