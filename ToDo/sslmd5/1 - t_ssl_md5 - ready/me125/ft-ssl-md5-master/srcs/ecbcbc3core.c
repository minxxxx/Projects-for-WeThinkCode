/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecbcbc3core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:37:22 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 15:37:23 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

void	get_triple_key(unsigned char *str, t_ssl *data)
{
	if ((ft_strlen((char *)str)) > 32)
		data->des3_key3 = hex_to_ul64(&str[32]);
	if ((ft_strlen((char *)str)) > 16)
		data->des3_key2 = hex_to_ul64(&str[16]);
	if ((ft_strlen((char *)str)) > 0)
		data->des3_key1 = hex_to_ul64(str);
}

void	des3_get_key(t_ssl *data)
{
	unsigned char	*str;
	unsigned long	size;

	if (data->key == NULL)
	{
		ft_printf("enter des key in hex: ");
		str = input_read_line(&size);
		if (check_hex(str))
		{
			get_triple_key(str, data);
			free(str);
			return ;
		}
		else
			ecb_hex_error(str);
	}
	else
	{
		if (check_hex((unsigned char *)data->key))
			return (get_triple_key((unsigned char *)data->key, data));
		else
			ecb_hex_error(NULL);
	}
}

void	des3_print_key(t_ssl *data, int show_iv)
{
	ft_printf("key=");
	cbc_showkey(data->des3_key1);
	cbc_showkey(data->des3_key2);
	cbc_showkey(data->des3_key3);
	ft_printf("\n");
	if (show_iv == 1)
	{
		ft_printf("iv =");
		cbc_showkey(data->master_iv);
		ft_printf("\n");
	}
}

void	start_des3ecb(int argc, char **argv, int i)
{
	t_ssl			data;
	size_t			size;
	unsigned char	*inp;
	unsigned char	*out;

	i = 0;
	size = i;
	handle_flags(2, argc, argv, &data);
	des3_get_key(&data);
	if (data.print == 1)
		des3_print_key(&data, 0);
	read_input(&data, &inp, &size);
	if (data.dec == 1)
		des3ecb_d_inp(&data, &inp, &out, &size);
	else
		des3ecb_e_inp(&data, &inp, &out, &size);
	if ((data.out == NULL) || ((data.out) && (ft_strequ(data.out, "-"))))
		write(1, out, size);
	else
		printinfile(data.out, out, size);
	free(out);
}

void	start_des3cbc(int argc, char **argv, int i)
{
	t_ssl			data;
	size_t			size;
	unsigned char	*inp;
	unsigned char	*out;

	i = 0;
	size = i;
	handle_flags(2, argc, argv, &data);
	des3_get_key(&data);
	data.master_iv = cbc_get_iv(&data);
	if (data.print == 1)
		des3_print_key(&data, 1);
	read_input(&data, &inp, &size);
	if (data.dec == 1)
		des3cbc_d_inp(&data, &inp, &out, &size);
	else
		des3cbc_e_inp(&data, &inp, &out, &size);
	if ((data.out == NULL) || ((data.out) && (ft_strequ(data.out, "-"))))
		write(1, out, size);
	else
		printinfile(data.out, out, size);
	free(out);
}
