/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descbc_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:18:29 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 17:18:29 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

unsigned long	cbc_get_iv(t_ssl *data)
{
	unsigned char	*str_iv;
	unsigned long	size;

	if (data->iv == NULL)
	{
		ft_printf("Enter initial vector: ");
		str_iv = input_read_line(&size);
		if (check_hex(str_iv))
		{
			data->master_iv = hex_to_ul64(str_iv);
			free(str_iv);
			return (data->master_iv);
		}
		else
			ecb_hex_error(str_iv);
	}
	else
	{
		if (check_hex((unsigned char *)data->iv))
			return (hex_to_ul64((unsigned char *)data->iv));
		else
			ecb_hex_error(NULL);
	}
	return (0);
}

void			cbc_encrypt_inp(t_ssl *data, UC **inp, UC **out, size_t *size)
{
	size_t			a;
	unsigned char	bit;
	unsigned char	*temp;

	a = ((*size / 8) + 1) * 8;
	bit = a - *size;
	if ((temp = ft_memalloc(a + 1)) == NULL)
		exit_error(errno, *inp);
	ft_memcpy(temp, *inp, *size);
	free(*inp);
	*inp = temp;
	while (*size < a)
		(*inp)[(*size)++] = bit;
	cbc_encrypt(inp, *size, data, DES_E);
	if (data->b64 == 1)
	{
		*out = base64encode(*inp, size);
		free(*inp);
	}
	else
		*out = *inp;
}

void			cbc_decrypt_inp(t_ssl *data, UC **inp, UC **out, size_t *size)
{
	size_t			a;
	unsigned char	bit;

	if (data->b64 == 1)
	{
		*out = base64decode(*inp, size);
		free(*inp);
		*inp = *out;
	}
	cbc_decrypt(inp, *size, data, DES_D);
	bit = (*inp)[(*size) - 1];
	if ((bit >= 1) && (bit <= 8))
	{
		a = *size - bit;
		while (((*inp)[a] == bit) && (a < *size))
			a++;
		if (a == *size)
			(*size) -= bit;
	}
	*out = *inp;
}
