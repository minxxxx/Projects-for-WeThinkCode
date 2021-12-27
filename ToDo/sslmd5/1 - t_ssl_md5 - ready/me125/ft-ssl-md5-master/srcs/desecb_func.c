/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desecb_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:10:05 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 14:10:06 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

void	ecb_show_key(unsigned long master_key)
{
	int				a;
	unsigned char	c;

	a = 0;
	ft_printf("key=");
	while (a < 16)
	{
		c = (master_key >> (60 - (a * 4))) & 0xf;
		if (c < 10)
			c += '0';
		else
			c += ('a' - 10);
		write(1, &c, 1);
		a++;
	}
	ft_printf("\n");
}

void	ecb_e_inp(t_ssl *data, UC **inp, UC **out, size_t *size)
{
	unsigned char	*temp;
	unsigned char	bit;
	size_t			a;

	a = ((*size / 8) + 1) * 8;
	bit = a - *size;
	if ((temp = ft_memalloc(a + 1)) == NULL)
		exit_error(errno, *inp);
	ft_memcpy(temp, *inp, *size);
	free(*inp);
	*inp = temp;
	while (*size < a)
		(*inp)[(*size)++] = bit;
	ecb_core(inp, *size, data->master_key, DES_E);
	if (data->b64 == 1)
	{
		*out = base64encode(*inp, size);
		free(*inp);
	}
	else
		*out = *inp;
}

void	ecb_d_inp(t_ssl *data, UC **inp, UC **out, size_t *size)
{
	unsigned char	bit;
	size_t			a;

	if (data->b64 == 1)
	{
		*out = base64decode(*inp, size);
		free(*inp);
		*inp = *out;
	}
	ecb_core(inp, *size, data->master_key, DES_D);
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

void	ecb_hex_error(void *memory)
{
	if (memory != NULL)
		free(memory);
	ft_printf("ERROR! Non-hex digit\nInvalid hex key value\n");
	exit(1);
}

UL		ecb_read_key(t_ssl *data)
{
	unsigned char	*str_key;
	unsigned long	size;

	if (data->key == NULL)
	{
		ft_printf("Type DES key in hex: ");
		str_key = input_read_line(&size);
		if (check_hex(str_key))
		{
			data->master_key = hex_to_ul64(str_key);
			free(str_key);
			return (data->master_key);
		}
		else
			ecb_hex_error(str_key);
	}
	else
	{
		if (check_hex((unsigned char *)data->key))
			return (hex_to_ul64((unsigned char *)data->key));
		else
			ecb_hex_error(NULL);
	}
	return (0);
}
