/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_string_to_bytes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:32:00 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:32:02 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

#define ERROR -1
#define ZERO_BYTE -2

/*
** transforms an ASCII representation of bytes (e.g. the c string
**  "6061626360616263\0") into
** into its size bytes representation (e.g. the byte arrray
**  \x60\x61\x62\x63\x60\x61\x62\x63).
** If the str represents more than size bytes, it will be
** truncated so that out represents size bytes.
** If it represents less, it will be left-padded with zeros (\x00).
** out MUST be able to countains at least size bytes.
** returns one (1) if successful, zero (0) else.
*/

static uint8_t	compute_digit(char i)
{
	if (i >= 'a' && i <= 'f')
		return (i - 'a' + 10);
	else if (i >= 'A' && i <= 'F')
		return (i - 'A' + 10);
	else if (i >= '0' && i <= '9')
		return (i - '0');
	else if (i == '\0')
		return (ZERO_BYTE);
	else
		return (ERROR);
}

static uint8_t	compute_value(const char *str, unsigned char *out, size_t i,
	int8_t *ended)
{
	char	d1;
	char	d2;

	d1 = compute_digit(str[2 * i]);
	if (d1 == ERROR)
		return (0);
	else if (d1 == ZERO_BYTE)
	{
		out[i] = 0;
		*ended = 1;
		return (1);
	}
	d2 = compute_digit(str[2 * i + 1]);
	if (d2 == ERROR)
		return (0);
	else if (d2 == ZERO_BYTE)
	{
		d2 = 0;
		*ended = 1;
	}
	out[i] = d1 * 16 + d2;
	return (1);
}

int				hex_string_to_bytes(const char *str,
	unsigned char *out, size_t size)
{
	size_t	i;
	int8_t	ended;

	i = 0;
	ended = 0;
	while (i < size)
	{
		if (!ended)
		{
			if (!compute_value(str, out, i, &ended))
				return (0);
		}
		else
			out[i] = 0;
		i++;
	}
	return (1);
}
