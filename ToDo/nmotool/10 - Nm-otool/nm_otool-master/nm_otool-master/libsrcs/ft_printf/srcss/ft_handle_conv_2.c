/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:14:44 by jcamhi            #+#    #+#             */
/*   Updated: 2016/01/18 23:11:09 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_with_no_lm_2(const t_arg arg, va_list list)
{
	char	*ret;

	if (arg.conv == 'c')
		ret = ft_alloc_str_with_char(va_arg(list, int));
	else if (arg.conv == 's')
		ret = ft_alloc_str(va_arg(list, char *));
	else if (arg.conv == 'p')
		ret = ft_itoa_ptr(va_arg(list, void *));
	else if (arg.conv == 'C')
		ret = ft_wchart_to_char(va_arg(list, wchar_t));
	else if (arg.conv == 'S')
		ret = ft_wchart_to_str(va_arg(list, wchar_t*));
	else
		ret = ft_alloc_str("Error");
	return (ret);
}

static char	*ft_with_no_lm_3(const t_arg arg, va_list list)
{
	char	*ret;

	if (arg.conv == 'd' || arg.conv == 'i')
		ret = ft_itoa_base_ll((long long)(va_arg(list, int)), 10);
	else if (arg.conv == 'o')
		ret = ft_itoa_base_ll((long long)(va_arg(list, unsigned int)), 8);
	else if (arg.conv == 'x')
		ret = ft_itoa_base_ll((long long)(va_arg(list, unsigned int)), 16);
	else if (arg.conv == 'u')
		ret = ft_itoa_base_ull((long long)(va_arg(list, unsigned int)), 10);
	else
		ret = ft_alloc_str("Error");
	return (ret);
}

char		*ft_with_no_lm(const t_arg arg, va_list list)
{
	char	*ret;

	if (arg.conv == 'c' || arg.conv == 'C' || arg.conv == 's'
			|| arg.conv == 'S' || arg.conv == 'p')
		return (ft_with_no_lm_2(arg, list));
	else if (arg.conv == 'd' || arg.conv == 'o' || arg.conv == 'u' ||
			arg.conv == 'x' || arg.conv == 'i')
		return (ft_with_no_lm_3(arg, list));
	else if (arg.conv == 'X')
		ret = ft_strtoupper(ft_itoa_base_ll((long long)
					(va_arg(list, unsigned int)), 16));
	else if (arg.conv == 'D')
		ret = ft_itoa_base_ll((long long)
				(va_arg(list, long int)), 10);
	else if (arg.conv == 'O')
		ret = ft_itoa_base_ull((unsigned long long)
				(va_arg(list, unsigned long)), 8);
	else if (arg.conv == 'U')
		ret = ft_itoa_base_ull((long long)
				(va_arg(list, unsigned long int)), 10);
	else
		ret = ft_alloc_str_with_char(arg.conv);
	return (ret);
}
