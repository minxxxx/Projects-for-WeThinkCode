/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 20:02:27 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:33:58 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_wint function thanks to tgauvrit (github.com/sploadie)
*/

static void			print_chars(void *memory, int size, size_t *written)
{
	write(1, memory, size);
	*written += size;
}

static void			print_wint(wint_t wint, size_t *written)
{
	char	str[4];

	if (wint <= 0x7F)
		print_chars(&wint, 1, written);
	else if (wint <= 0x7FF)
	{
		str[0] = (((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = ((wint & 0x003F) + 0x80);
		print_chars(str, 2, written);
	}
	else if (wint <= 0xFFFF)
	{
		str[0] = (((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wint & 0x003F) + 0x80);
		print_chars(str, 3, written);
	}
	else if (wint <= 0x10FFFF)
	{
		str[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((wint & 0x003F) + 0x80);
		print_chars(str, 4, written);
	}
}

static size_t		count_wide_chars(t_conversion *conversion
										, wchar_t *string, size_t *length)
{
	size_t			i;
	size_t			total_bytes;
	int				add;

	i = 0;
	add = 0;
	total_bytes = 0;
	while (i < *length)
	{
		if (string[i] <= 0x7F)
			add = 1;
		else if (string[i] <= 0x7FF)
			add = 2;
		else if (string[i] <= 0xFFFF)
			add = 3;
		else if (string[i] <= 0x10FFFF)
			add = 4;
		if (conversion->precision_set
			&& (total_bytes + add) > conversion->precision)
			break ;
		total_bytes += add;
		i++;
	}
	*length = i;
	return (total_bytes);
}

static void			place_padding(char padder, size_t width, size_t *written)
{
	ft_putcharn(padder, width);
	*written += width;
}

void				print_wide_chars(t_conversion *conversion
										, wchar_t *string, size_t length
										, size_t *written)
{
	size_t		i;
	size_t		total_bytes;

	total_bytes = count_wide_chars(conversion, string, &length);
	if (!conversion->flags.left_justify && conversion->width > total_bytes)
		place_padding((conversion->flags.pad_with_zeros ? '0' : ' ')
						, conversion->width - total_bytes, written);
	i = 0;
	while (i < length)
	{
		print_wint(string[i], written);
		i++;
	}
	if (conversion->flags.left_justify && conversion->width > total_bytes)
		place_padding(' ', conversion->width - total_bytes, written);
}
