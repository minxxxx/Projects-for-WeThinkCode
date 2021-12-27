/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:09:41 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:31:00 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_printf("this is an error %m\n");
**            ~~~~~~~~~~~~~~~~~~^~~
*/

/*
** Note: the norme is why count_specials is like that...
*/

size_t				count_specials(char const *haystack, size_t length)
{
	size_t			blah;

	blah = ft_countchars(haystack, '\t', length)
			+ ft_countchars(haystack, '\n', length);
	return (blah);
}

void				print_format_error(t_format *format)
{
	intmax_t		tildes_before;
	intmax_t		tildes_after;

	ft_putstr_fd(PROGRAM_NAME, 2);
	ft_putstr_fd("(\"", 2);
	ft_putstr_literal_fd(format->string, 2);
	ft_putstr_fd("\")\n", 2);
	ft_putcharn_fd(' ', ft_strlen(PROGRAM_NAME) + 2, 2);
	tildes_before = format->location
		+ count_specials(format->string, format->location);
	if (tildes_before > 0)
		ft_putcharn_fd('~', tildes_before, 2);
	ft_putchar_fd('^', 2);
	tildes_after = ft_strlen(format->string) - tildes_before - 1;
	tildes_after += count_specials(format->string + format->location
									, tildes_after + 1);
	if (tildes_after > 0)
		ft_putcharn_fd('~', tildes_after, 2);
	ft_putchar_fd('\n', 2);
}
