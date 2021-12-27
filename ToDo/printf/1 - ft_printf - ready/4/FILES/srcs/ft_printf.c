/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:21:20 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/29 11:10:47 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	specifier_not_handled(t_tag *tag)
{
	int		ret;

	if (tag->specifier)
		ft_putchar('%');
	else
	{
		ft_putcolor("\nft_printf: error: invalid specifier\n", "red");
		return (-1);
	}
	if (tag->width)
		print_width_pad(1, tag->width, ' ');
	ret = (tag->width ? tag->width - 1 : 0);
	return (ret);
}

static int	parse_tag(char **format, va_list *args)
{
	int			ret;
	t_tag		*tag_info;
	t_converter	converter;

	if (!(tag_info = (t_tag *)ft_memalloc(sizeof(t_tag))))
		return (-1);
	get_flags(format, tag_info);
	get_width(format, tag_info);
	get_precision(format, tag_info);
	get_length(format, tag_info);
	get_specifier(format, tag_info);
	adjust_format(tag_info);
	if ((converter = return_converter(tag_info->specifier)))
	{
		if ((ret = (*converter)(tag_info, args)) == -1)
			return (-1);
	}
	else
		ret = specifier_not_handled(tag_info);
	free(tag_info);
	return (ret);
}

static int	parse_format(const char *format, va_list *args)
{
	int		count;
	char	c;
	char	*ptr;
	int		tag_length;

	ptr = (char *)format;
	count = 0;
	while (*ptr)
	{
		c = *ptr++;
		if (c == '%')
		{
			if ((tag_length = parse_tag(&ptr, args)) == -1)
				return (-1);
			count += tag_length;
		}
		else if (c == '{' && add_color(&ptr) == 1)
			;
		else
		{
			count++;
			ft_putchar(c);
		}
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	if (*format == '\0')
		return (0);
	ret = parse_format(format, &args);
	va_end(args);
	return (ret);
}
