/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_encode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:30:53 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:30:54 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#define BUFF_SIZE_BASE64 48

static void		init_params(t_params_base64 *params)
{
	int	i;

	i = 'A';
	while (i <= 'Z')
	{
		params->alphabet[i - 'A'] = i;
		i++;
	}
	i = 'a';
	while (i <= 'z')
	{
		params->alphabet[26 + i - 'a'] = i;
		i++;
	}
	i = '0';
	while (i <= '9')
	{
		params->alphabet[52 + i - '0'] = i;
		i++;
	}
	params->alphabet[62] = '+';
	params->alphabet[63] = '/';
}

/*
	** get_current_value
*/

int8_t			gcv(char buffer[BUFF_SIZE_BASE64], int i)
{
	int		index_debut;
	int		index_fin;
	char	c_debut;
	char	c_fin;

	index_debut = i * 6 / 8;
	index_fin = (((i + 1) * 6 - 1) / 8);
	c_debut = buffer[index_debut];
	c_fin = buffer[index_fin];
	if (i % 4 == 0)
		return ((c_debut & 252) >> 2);
	else if (i % 4 == 1)
		return (((c_debut & 3) << 4) | ((c_fin & 240)) >> 4);
	else if (i % 4 == 2)
		return (((c_debut & 15) << 2) | ((c_fin & 192) >> 6));
	else
		return (c_fin & 63);
}

void			print_last_bits(char buffer[BUFF_SIZE_BASE64], int i, int r,
	int output_fd)
{
	int8_t			tmp[4];
	t_params_base64	params;

	init_params(&params);
	ft_bzero(tmp, 4 * sizeof(int8_t));
	if (r * 8 - i * 6 == 16)
	{
		tmp[0] = buffer[i * 6 / 8];
		tmp[1] = buffer[i * 6 / 8 + 1];
		tmp[2] = 0;
		ft_putchar_fd(params.alphabet[gcv((char*)tmp, 0)], output_fd);
		ft_putchar_fd(params.alphabet[gcv((char*)tmp, 1)], output_fd);
		ft_putchar_fd(params.alphabet[gcv((char*)tmp, 2)], output_fd);
		ft_putchar_fd('=', output_fd);
	}
	else if (r * 8 - i * 6 == 8)
	{
		tmp[0] = buffer[i * 6 / 8];
		tmp[1] = 0;
		ft_putchar_fd(params.alphabet[gcv((char*)tmp, 0)], output_fd);
		ft_putchar_fd(params.alphabet[gcv((char*)tmp, 1)], output_fd);
		ft_putchar_fd('=', output_fd);
		ft_putchar_fd('=', output_fd);
	}
}

void			base64_enc_from_buf_to_fd(uint8_t *buffer, int buf_size,
	int output_fd)
{
	t_params_base64	params;
	char			trad_buff[4];
	int				i;

	init_params(&params);
	ft_bzero(trad_buff, 4);
	i = 0;
	while (1)
	{
		if (buf_size * 8 - i * 6 < 24)
			break ;
		else
			print_four_chars(&params, (char*)buffer, &i, output_fd);
	}
	if (buf_size * 8 - i * 6 < 24 && buf_size * 8 - i * 6 != 0)
		print_last_bits((char*)buffer, i, buf_size, output_fd);
	ft_putchar_fd('\n', output_fd);
}

void			base64_encode_from_fd(int fd, int output_fd)
{
	char	*buf;
	int		size;

	if (!(buf = get_file(fd, &size)))
	{
		ft_putendl_fd("Error - Memory error", 2);
		return ;
	}
	base64_enc_from_buf_to_fd((void*)buf, size, output_fd);
	free(buf);
}
