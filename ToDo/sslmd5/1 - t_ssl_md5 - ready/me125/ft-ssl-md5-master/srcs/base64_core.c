/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 09:46:32 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 09:46:33 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

UC		b64manage(UC c, UC *inp, UC *out)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (c - 'A');
	else if ((c >= 'a') && (c <= 'z'))
		return (c - 'a' + 26);
	else if ((c >= '0') && (c <= '9'))
		return (c - '0' + 52);
	else if (c == '+')
		return (62);
	else if (c == '/')
		return (63);
	else if (c == '=')
		return (0);
	ft_printf("ERROR! Invalid charcter.\n");
	free(out);
	free(inp);
	exit(1);
}

size_t	b64decode(UC *inp, UC *out, size_t size)
{
	size_t	a;
	size_t	b;
	UC		c;

	a = 0;
	b = 0;
	while (a < size)
	{
		out[b] = b64manage(inp[a++], inp, out) << 2;
		c = b64manage(inp[a++], inp, out);
		out[b++] += (c >> 4) & 0x3;
		out[b] = (c & 0xf) << 4;
		c = b64manage(inp[a++], inp, out);
		out[b++] += (c >> 2) & 0xf;
		out[b] = (c & 0x3) << 6;
		out[b++] += b64manage(inp[a++], inp, out) & 0x3f;
	}
	if ((inp[a - 1] == '=') && (inp[a - 2] == '='))
		out[--b] = 0;
	if (inp[a - 1] == '=')
		out[--b] = 0;
	return (b);
}

UC		*base64decode(UC *inp, size_t *size)
{
	UC		*out;
	UC		*edit;
	size_t	a;

	edit = b64_remove_newlines(inp, size);
	a = (*size / 4) * 3;
	if ((out = ft_memalloc(a + 6)) == NULL)
	{
		free(edit);
		exit_error(errno, inp);
	}
	*size = b64decode(edit, out, *size);
	free(edit);
	return (out);
}

void	b64encode(UC *inp, UC *out, size_t size)
{
	size_t		a;
	size_t		b;
	UC			c;
	static char	*b64;

	a = 0;
	b = 0;
	b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	while (a < size)
	{
		out[b++] = b64[inp[a] >> 2];
		c = inp[a++] << 6;
		out[b++] = b64[(c >> 2) + (inp[a] >> 4)];
		c = inp[a++] << 4;
		out[b++] = b64[(c >> 2) + (inp[a] >> 6)];
		c = ((inp[a++]) << 2);
		out[b++] = b64[c >> 2];
	}
	if (a - 2 == size)
		out[b - 2] = '=';
	if (a - 1 >= size)
		out[b - 1] = '=';
}

UC		*base64encode(UC *inp, size_t *size)
{
	UC		*temp;
	UC		*out;
	size_t	size_temp;

	if ((out = ft_memalloc(*size + 6)) == NULL)
		exit_error(errno, inp);
	ft_memcpy(out, inp, *size);
	size_temp = *size;
	while (size_temp % 3)
		size_temp++;
	size_temp /= 3;
	size_temp *= 4;
	if ((temp = ft_memalloc(size_temp + 1)) == NULL)
	{
		free(out);
		exit_error(errno, inp);
	}
	b64encode(out, temp, *size);
	free(out);
	(*size) = size_temp;
	out = b64_insert_newlines(temp, size);
	free(temp);
	return (out);
}
