/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 17:35:02 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:37:20 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_flag: returns pointer to the flag
*/

static t_bool		*get_flag(char c, t_flags *flags)
{
	if (c == '-')
		return (&flags->left_justify);
	if (c == '0')
		return (&flags->pad_with_zeros);
	if (c == '+')
		return (&flags->show_sign);
	if (c == ' ')
		return (&flags->positive_values_begin_blank);
	if (c == '#')
		return (&flags->hashtag);
	return (NULL);
}

static int			repeated_flag(char offending_flag, t_format *format)
{
	ft_putstr_fd("ft_printf: repeated flag '", 2);
	ft_putchar_fd(offending_flag, 2);
	ft_putstr_fd("' in format\n", 2);
	print_format_error(format);
	return (1);
}

int					parse_flags(t_conversion *conversion, t_format *format)
{
	t_bool			*flag;
	char			current;

	while (((current = *get_current(format)))
			&& ((flag = get_flag(current, &conversion->flags))))
	{
		if (*flag)
			return (repeated_flag(current, format));
		*flag = 1;
		format->location++;
	}
	return (0);
}
