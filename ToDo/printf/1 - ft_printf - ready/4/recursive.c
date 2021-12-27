/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:21:20 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/10 15:22:38 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tag		*init_tag_struct(void)
{
	t_tag	*tag_struct;

	if (!(tag_struct = (t_tag *)malloc(sizeof(t_tag))))
		return (NULL);
	tag_struct->specifier = 0;
	tag_struct->flag_minus = 0;
	tag_struct->flag_plus = 0;
	tag_struct->flag_space = 0;
	tag_struct->flag_sharp = 0;
	tag_struct->flag_zero = 0;

	tag_struct->has_width = 0;
	tag_struct->width = 0;
	tag_struct->has_precision = 0;
	tag_struct->precision = 0;
	tag_struct->length = 0;
	return (tag_struct);
}



/*
 * A
 * SUPPRIMER
 *
*/
#include <stdio.h>
void print_struct(t_tag *tag)
{
	printf("specifier %c\n", tag->specifier);
	printf("flags:\n minus %d, plus %d, space %d, sharp %d, zero %d\n", tag->flag_minus, tag->flag_plus, tag->flag_space, tag->flag_sharp, tag->flag_zero);
	printf("has_width? %d, width %d\n", tag->has_width, tag->width);
	printf("has_precision? %d, precision: %d\n", tag->has_precision, tag->precision);
	printf("length : %d\n", tag->length);
}
/*
 * A
 * SUPPRIMER
 *
*/


static int	parse_tag(char **format, va_list *args)
{
	int		ret;
	t_tag	*tag_info;
	void (*handler)(t_tag *, va_list *);

	tag_info = init_tag_struct();

	get_flags(format, tag_info);
	get_width(format, tag_info);
	get_precision(format, tag_info);
	get_length(format, tag_info);
	get_specifier(format, tag_info);

//	print_struct(tag_info);

	handler = return_handler(tag_info->specifier);
	(*handler)(tag_info, args);
	
	free(tag_info);
	ret = 0;
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
		else
		{
			count++;
			ft_putchar(c);
		}
	}
	return (count);
}

/*
** RECURSIVE

static int	parse_format(const char *format, va_list *args, int ret)
{
	char	*next_tag;
	int		tag_length;

	next_tag = ft_strchr(format, '%');
	if (next_tag == NULL)
	{
		ft_putstr(format);
		return (ret + ft_strlen(format));
	}
	else if (next_tag > format)
	{
		ft_putnstr(format, next_tag - format);	
		return (parse_format(next_tag, args, ret + (next_tag - format)));
	}
	else
	{
		if ((tag_length = process_tag((char **)&format, args)) == -1)
			return (-1);
		ret += tag_length;
		return (parse_format(format, args, ret));
	}
}
*/

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	if (*format == '\0')
		return (0);
	ret = parse_format(format, &args);
	va_end(args);
	return (ret);
}
