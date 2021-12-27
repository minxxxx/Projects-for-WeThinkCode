/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:58:33 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/08 20:12:19 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void    ft_init_fn(t_fn arr[65])
{
	arr['c' - 'A'] = &ft_get_char;
	arr['C' - 'A'] = &ft_get_char;
	arr['s' - 'A'] = &ft_get_str;
	arr['p' - 'A'] = &ft_make_pointer;
	arr['f' - 'A'] = &ft_dispatch_float;
	arr['F' - 'A'] = &ft_dispatch_float;
	arr['F' - 'A'] = &ft_dispatch_float;
	arr['d' - 'A'] = &ft_dispatch_int;
	arr['D' - 'A'] = &ft_upper_dispatch_int;
	arr['i' - 'A'] = &ft_dispatch_int;
	arr['x' - 'A'] = &ft_dispatch_uint;
	arr['X' - 'A'] = &ft_dispatch_uint;
	arr['o' - 'A'] = &ft_dispatch_uint;
	arr['O' - 'A'] = &ft_upper_dispatch_uint;
	arr['u' - 'A'] = &ft_dispatch_uint;
	arr['U' - 'A'] = &ft_upper_dispatch_uint;
	arr['b' - 'A'] = &ft_dispatch_uint;
	arr['r' - 'A'] = &ft_get_nstr;
	arr['e' - 'A'] = &ft_dispatch_e;
	arr['g' - 'A'] = &ft_dispatch_g;
}

void	dispatch_specifier(char	**fmt, int *counter, va_list *ap)
{
	t_specifier	*sp;

	(*fmt)++;
	if (**fmt && **fmt == '%')
	{
		ft_putchar('%');
		(*fmt)++;
		(*counter)++;
		return ;
	}
	if (!**fmt)
		return ;
	sp = create_specifier(fmt);
	if (!is_valid_spec(&sp, counter))
	{
		spec_del(&sp);
		return ;
	}
	ft_dispatch_spec(sp, ap, counter);
}

void    ft_init_colors(t_color arr[13])
{
	arr[0].color = "{red}";
	arr[0].replace = "\e[31m";
	arr[1].color = "{green}";
	arr[1].replace = "\e[32m";
	arr[2].color = "{yellow}";
	arr[2].replace = "\e[33m";
	arr[3].color = "{blue}";
	arr[3].replace = "\e[34m";
	arr[4].color = "{magenta}";
	arr[4].replace = "\e[35m";
	arr[5].color = "{eoc}";
	arr[5].replace = "\e[0m";
	arr[6].color = "{cyan}";
	arr[6].replace = "\e[36m";
	arr[7].color = "{black}";
	arr[7].replace = "\e[30m";
	arr[8].color = "{lgrey}";
	arr[8].replace = "\e[37m";
	arr[9].color = "{dgrey}";
	arr[9].replace = "\e[90m";
	arr[10].color = "{lred}";
	arr[10].replace = "\e[91m";
	arr[11].color = "{lgreen}";
	arr[11].replace = "\e[92m";
	arr[12].color = "{lyellow}";
	arr[12].replace = "\e[93m";
}

char    *ft_color_fmt(char *fmt)
{
	int     i;
	char    *tmp;
	t_color arr[13];

	i = 0;
	ft_init_colors(arr);
	tmp = ft_strnew(ft_strlen(fmt));
	tmp = ft_strcpy(tmp, fmt);
	while (i < 13)
	{
		while (ft_strstr(tmp, arr[i].color))
		{
			tmp = ft_strreplace(tmp, arr[i].color, arr[i].replace);
		}
		i++;
	}
	return (tmp);
}

int	ft_printf(char *fmt, ...)
{
	va_list ap;
	int		counter;
	char    *cfmt;
	char	*start;

	if (!fmt)
		return (-1);
	counter = 0;
	cfmt = ft_color_fmt(fmt);
	start = cfmt;
	va_start(ap, fmt);
	while (*cfmt)
	{
		if (*cfmt != '%')
		{
			ft_putchar(*cfmt);
			cfmt++;
			counter++;
		}
		else
			dispatch_specifier(&cfmt, &counter, &ap);
	}
	free(start);
	va_end(ap);
	return (counter);
}
