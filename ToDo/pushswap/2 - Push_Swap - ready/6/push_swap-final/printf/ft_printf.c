/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:00:49 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/13 15:27:01 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_letter(va_list *ap, t_flag *f)
{
	int i;

	i = 0;
	if (f->val_conv == 'd' || f->val_conv == 'D' || f->val_conv == 'i')
		i = ft_flag_d(ap, f);
	else if (f->val_conv == 'u' || f->val_conv == 'U')
		i = ft_flag_u(ap, f);
	else if (f->val_conv == 'x' || f->val_conv == 'X' || f->val_conv == 'p')
		i = ft_flag_x(ap, f);
	else if (f->val_conv == 'c' || f->val_conv == 'C')
		i = ft_flag_c(ap, f);
	else if (f->val_conv == 'o' || f->val_conv == 'O')
		i = ft_flag_o(ap, f);
	else if (f->val_conv == 's' || f->val_conv == 'S')
		i = ft_flag_s(ap, f);
	else
		i = ft_flag_c(ap, f);
	return (i);
}

static int	ft_boh(const char *format, int i)
{
	ft_putchar(*format);
	i++;
	return (i);
}

static int	ft_check(const char *format, va_list *ap)
{
	t_flag		*flag;
	int			i;

	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flag = get_list(flag);
			format = ft_fillstruct(format, flag);
			if (flag->conv == 0 && *format != 0 && *format != ' ')
				i = ft_boh(format, i);
			else if (flag->conv == 1)
				i += ft_letter(ap, flag);
			free(flag);
		}
		else
		{
			ft_putchar(*format);
			i++;
		}
		(*format) ? ++format : 0;
	}
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;

	va_start(ap, format);
	i = ft_check(format, &ap);
	va_end(ap);
	return (i);
}
