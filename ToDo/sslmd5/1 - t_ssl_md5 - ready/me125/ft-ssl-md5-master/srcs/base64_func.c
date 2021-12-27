/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:20:38 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 12:20:38 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

UC	*b64_insert_newlines(UC *inp, size_t *size)
{
	size_t			a;
	size_t			b;
	unsigned char	*out;

	a = 0;
	b = 0;
	if ((*size == 0) || (BASE64_LINE == 0))
		return (NULL);
	*size = *size + (*size / BASE64_LINE);
	if ((out = ft_memalloc(*size + 3)) == NULL)
		exit_error(errno, (inp));
	while (a < *size)
	{
		out[a++] = (inp)[b++];
		if (b % BASE64_LINE == 0)
			out[a++] = '\n';
	}
	if (out[(*size) - 1] != '\n')
		out[(*size)++] = '\n';
	return (out);
}

UC	*b64_remove_newlines(UC *inp, size_t *size)
{
	size_t			a;
	size_t			b;
	unsigned char	*out;

	a = 0;
	b = 0;
	if (*size == 0)
		return (NULL);
	if ((out = ft_memalloc(*size + 3)) == NULL)
		exit_error(errno, inp);
	while (b < *size)
	{
		if (inp[b] == '\n')
			b++;
		else
			out[a++] = inp[b++];
	}
	(*size) = a;
	return (out);
}
