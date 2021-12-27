/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managetypes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 10:07:36 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 10:07:37 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

void	handle_flags(int i, int argc, char **argv, t_ssl *data)
{
	ft_bzero(data, sizeof(t_ssl));
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-e"))
			data->enc = 1;
		else if (ft_strequ(argv[i], "-d"))
			data->dec = 1;
		else if (ft_strequ(argv[i], "-p"))
			data->print = 1;
		else if (ft_strequ(argv[i], "-a"))
			data->b64 = 1;
		else if ((ft_strequ(argv[i], "-i")) && (argv[i + 1]))
			data->inp = argv[++i];
		else if ((ft_strequ(argv[i], "-o")) && (argv[i + 1]))
			data->out = argv[++i];
		else if ((ft_strequ(argv[i], "-v")) && (argv[i + 1]))
			data->iv = argv[++i];
		else if ((ft_strequ(argv[i], "-k")) && (argv[i + 1]))
			data->key = argv[++i];
		else
			error_flags(argv[i]);
		i++;
	}
}

void	start_base64(int argc, char **argv, int i)
{
	t_ssl			data;
	size_t			size;
	unsigned char	*inp;
	unsigned char	*out;

	i = 0;
	size = i;
	handle_flags(2, argc, argv, &data);
	read_input(&data, &inp, &size);
	if (data.dec == 1)
		out = base64decode(inp, &size);
	else
		out = base64encode(inp, &size);
	free(inp);
	if ((data.out == NULL) || ((data.out) && (ft_strequ(data.out, "-"))))
		write(1, out, size);
	else
		printinfile(data.out, out, size);
	free(out);
}

void	start_ecb(int argc, char **argv, int i)
{
	t_ssl			data;
	size_t			size;
	unsigned char	*inp;
	unsigned char	*out;

	i = 0;
	size = i;
	handle_flags(2, argc, argv, &data);
	data.master_key = ecb_read_key(&data);
	if (data.print == 1)
		ecb_show_key(data.master_key);
	read_input(&data, &inp, &size);
	if (data.dec == 1)
		ecb_d_inp(&data, &inp, &out, &size);
	else
		ecb_e_inp(&data, &inp, &out, &size);
	if ((data.out == NULL) || ((data.out) && (ft_strequ(data.out, "-"))))
		write(1, out, size);
	else
		printinfile(data.out, out, size);
	free(out);
}

void	start_cbc(int argc, char **argv, int i)
{
	t_ssl			data;
	size_t			size;
	unsigned char	*inp;
	unsigned char	*out;

	i = 0;
	size = i;
	handle_flags(2, argc, argv, &data);
	data.master_key = ecb_read_key(&data);
	data.master_iv = cbc_get_iv(&data);
	if (data.print == 1)
		cbc_print_key(data);
	read_input(&data, &inp, &size);
	if (data.dec == 1)
		cbc_decrypt_inp(&data, &inp, &out, &size);
	else
		cbc_encrypt_inp(&data, &inp, &out, &size);
	if ((data.out == NULL) || ((data.out) && (ft_strequ(data.out, "-"))))
		write(1, out, size);
	else
		printinfile(data.out, out, size);
	free(out);
}
