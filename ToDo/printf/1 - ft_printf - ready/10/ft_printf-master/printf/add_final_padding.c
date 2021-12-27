/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_final_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 19:09:46 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/28 18:04:19 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				get_filler_char(t_conversion *conversion)
{
	if (conversion->flags.pad_with_zeros
		&& (conversion->specifier == HEX_LOWER
			|| conversion->specifier == HEX_UPPER))
		return ('0');
	return (' ');
}

void				add_final_padding(t_conversion *conversion
										, char **string)
{
	char			*new;
	char			*padding;
	intmax_t		needed;

	needed = conversion->width - ft_strlen(*string);
	if (needed > 0)
	{
		padding = ft_strnew(needed);
		ft_memset(padding, get_filler_char(conversion), needed);
		if (conversion->flags.left_justify)
			new = ft_strjoin(*string, padding);
		else
			new = ft_strjoin(padding, *string);
		free(*string);
		free(padding);
		*string = new;
	}
}
