/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:21:58 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/26 15:27:09 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_long(t_tag *tag, va_list *args)
{
	tag->length = 3;
	if (tag->specifier == 'D')
		return (convert_int(tag, args));
	else if (tag->specifier == 'O')
		return (convert_octal(tag, args));
	else if (tag->specifier == 'U')
		return (convert_unsigned_int(tag, args));
	else
		return (-1);
}
