/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:16:20 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/08 19:41:31 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	print_flags(t_specifier *spec, int *counter)
{
	char	*f_str;
	int		len;
	int 	i;
	t_flags	*flags;

	flags = spec->flags;
	len = flags->cage + flags->zero + flags->space + flags->plus + flags->minus;
	if (!(f_str = ft_strnew(len)))
		handle_error(0, &spec);
	i = 0;
	if (flags->cage)
		f_str[i++] = '#';
	if (flags->plus)
		f_str[i++] = '+';
	if (flags->minus)
		f_str[i++] = '-';
	if (flags->space)
		f_str[i++] = ' ';
	if (flags->zero)
		f_str[i++] = '0';
	ft_putstr(f_str);
	*counter += ft_strlen(f_str);
	free(f_str);
}

void	ft_print_precition(int prec, int *counter)
{
	char	*str;
	ft_putstr(".");
	str = ft_itoa(prec);
	ft_putstr(str);
	*counter += ft_strlen(str) + 1;
	free(str);
}

void	print_specifier(t_specifier *sp, int *counter)
{
	char	*width;

		if (sp->width > 0 || (sp->precition > 0 && sp->specifier != '%'))
		{
			if (sp->flags->zero)
				width = ft_fillstr(sp->width > sp->precition ? sp->width: sp->precition, '0');
			else
				width = ft_fillstr(sp->width > sp->precition ? sp->width: sp->precition, ' ');
			if (sp->flags->minus)
				width[0] = sp->specifier;
			else
				width[ft_strlen(width) - 1] = sp->specifier;
			ft_putstr(width);
			*counter += ft_strlen(width);
			free(width);
		}
		else
		{
			ft_putchar(sp->specifier);
			*counter += 1;
		}
}
