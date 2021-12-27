/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:33:31 by thou              #+#    #+#             */
/*   Updated: 2017/03/30 14:41:23 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printj(va_list arg, char c)
{
	uintmax_t	n;
	intmax_t	i;

	if (ft_strchr("uUxXoO", c))
		n = va_arg(arg, uintmax_t);
	else
		i = va_arg(arg, intmax_t);
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

static char	*ft_printz(va_list arg, char c)
{
	uintmax_t	n;
	intmax_t	i;

	if (ft_strchr("uUxXoO", c))
		n = (uintmax_t)va_arg(arg, size_t);
	else
		i = (intmax_t)va_arg(arg, ssize_t);
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

static char	*ft_printn(va_list arg, char c)
{
	uintmax_t	n;
	intmax_t	i;

	if (ft_strchr("uUxXoO", c))
		n = (uintmax_t)va_arg(arg, unsigned int);
	else
		i = (intmax_t)va_arg(arg, int);
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

char		*ft_printh(va_list arg, t_h *h, char c)
{
	if (h->j == 1)
		return (ft_printj(arg, c));
	else if (h->z == 1)
		return (ft_printz(arg, c));
	else if (h->h == 1 || h->hh == 1 || h->l == 1 || h->ll == 1)
		return (ft_printhl(arg, h, c));
	else
		return (ft_printn(arg, c));
}
