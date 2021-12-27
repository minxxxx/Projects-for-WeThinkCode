/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 17:46:20 by thou              #+#    #+#             */
/*   Updated: 2017/03/30 17:58:12 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_print_ll(va_list arg, char c)
{
	uintmax_t	n;
	intmax_t	i;

	if (ft_strchr("uUxXoO", c))
		n = (uintmax_t)va_arg(arg, unsigned long long);
	else
		i = (intmax_t)va_arg(arg, long long);
	if (c == 'u' || c == 'U')
		return (ft_uimtoa_base(n, 10, 'x'));
	if (c == 'x')
		return (ft_uimtoa_base(n, 16, 'x'));
	if (c == 'X')
		return (ft_uimtoa_base(n, 16, 'X'));
	if (c == 'o' || c == 'O')
		return (ft_uimtoa_base(n, 8, 'o'));
	if (c == 'd' || c == 'D' || c == 'i')
		return (ft_intmaxtoa_base(i, 10, 'x'));
	return (NULL);
}

static char	*ft_print_l(va_list arg, char c)
{
	uintmax_t	n;
	intmax_t	i;

	if (ft_strchr("uUxXoO", c))
		n = (uintmax_t)va_arg(arg, unsigned long);
	else
		i = (intmax_t)va_arg(arg, long);
	if (c == 'u' || c == 'U')
		return (ft_uimtoa_base(n, 10, 'x'));
	if (c == 'x')
		return (ft_uimtoa_base(n, 16, 'x'));
	if (c == 'X')
		return (ft_uimtoa_base(n, 16, 'X'));
	if (c == 'o' || c == 'O')
		return (ft_uimtoa_base(n, 8, 'o'));
	if (c == 'd' || c == 'D' || c == 'i')
		return (ft_intmaxtoa_base(i, 10, 'x'));
	return (NULL);
}

static char	*ft_print_h(va_list arg, char c)
{
	uintmax_t	n;
	intmax_t	i;

	if (ft_strchr("uUxXoO", c))
		n = (uintmax_t)(unsigned short)va_arg(arg, int);
	else
		i = (intmax_t)(short)va_arg(arg, int);
	if (c == 'u' || c == 'U')
		return (ft_uimtoa_base(n, 10, 'x'));
	if (c == 'x')
		return (ft_uimtoa_base(n, 16, 'x'));
	if (c == 'X')
		return (ft_uimtoa_base(n, 16, 'X'));
	if (c == 'o' || c == 'O')
		return (ft_uimtoa_base(n, 8, 'o'));
	if (c == 'd' || c == 'D' || c == 'i')
		return (ft_intmaxtoa_base(i, 10, 'x'));
	return (NULL);
}

static char	*ft_print_hh(va_list arg, char c)
{
	uintmax_t	n;
	intmax_t	i;

	if (ft_strchr("uUxXoO", c))
		n = (uintmax_t)(unsigned char)va_arg(arg, int);
	else
		i = (intmax_t)(signed char)va_arg(arg, int);
	if (c == 'u' || c == 'U')
		return (ft_uimtoa_base(n, 10, 'x'));
	if (c == 'x')
		return (ft_uimtoa_base(n, 16, 'x'));
	if (c == 'X')
		return (ft_uimtoa_base(n, 16, 'X'));
	if (c == 'o' || c == 'O')
		return (ft_uimtoa_base(n, 8, 'o'));
	if (c == 'd' || c == 'D' || c == 'i')
		return (ft_intmaxtoa_base(i, 10, 'x'));
	return (NULL);
}

char		*ft_printhl(va_list arg, t_h *h, char c)
{
	if (h->ll == 1)
		return (ft_print_ll(arg, c));
	else if (h->l == 1)
		return (ft_print_l(arg, c));
	else if (h->hh == 1)
		return (ft_print_hh(arg, c));
	else if (h->h == 1)
		return (ft_print_h(arg, c));
	return (NULL);
}
