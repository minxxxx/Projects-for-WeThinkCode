/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_decode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:30:50 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:30:51 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#define BUFF_SIZE_BASE64 48

void		init_decode_params(t_params_base64 *params)
{
	int	i;

	ft_memset(params->alphabet, -1, 255);
	i = 'A';
	while (i <= 'Z')
	{
		params->alphabet[i] = i - 'A';
		i++;
	}
	i = 'a';
	while (i <= 'z')
	{
		params->alphabet[i] = 26 + i - 'a';
		i++;
	}
	i = '0';
	while (i <= '9')
	{
		params->alphabet[i] = 52 + i - '0';
		i++;
	}
	params->alphabet['+'] = 62;
	params->alphabet['/'] = 63;
}

static void	decode_four_chars_buff_no_equal(char buff[4],
	t_params_base64 *params, int output_fd, char decoded[3])
{
	buff[0] = params->alphabet[(int)buff[0]];
	buff[1] = params->alphabet[(int)buff[1]];
	buff[2] = params->alphabet[(int)buff[2]];
	buff[3] = params->alphabet[(int)buff[3]];
	decoded[0] = (buff[0] << 2) | ((buff[1] & 48) >> 4);
	decoded[1] = ((buff[1] & 15) << 4) | ((buff[2] & 60) >> 2);
	decoded[2] = ((buff[2] & 3) << 6) | ((buff[3]));
	ft_putchar_fd(decoded[0], output_fd);
	ft_putchar_fd(decoded[1], output_fd);
	ft_putchar_fd(decoded[2], output_fd);
}

void		decode_four_chars(char buff[4], t_params_base64 *params,
	int output_fd)
{
	char	decoded[3];

	if (buff[2] == '=')
	{
		buff[0] = params->alphabet[(int)buff[0]];
		buff[1] = params->alphabet[(int)buff[1]];
		decoded[0] = (buff[0] << 2) | ((buff[1] & 48) >> 4);
		ft_putchar_fd(decoded[0], output_fd);
	}
	else if (buff[3] == '=')
	{
		buff[0] = params->alphabet[(int)buff[0]];
		buff[1] = params->alphabet[(int)buff[1]];
		buff[2] = params->alphabet[(int)buff[2]];
		decoded[0] = (buff[0] << 2) | ((buff[1] & 48) >> 4);
		decoded[1] = ((buff[1] & 15) << 4) | ((buff[2] & 60) >> 2);
		ft_putchar_fd(decoded[0], output_fd);
		ft_putchar_fd(decoded[1], output_fd);
	}
	else
		decode_four_chars_buff_no_equal(buff, params, output_fd, decoded);
	ft_bzero(buff, 4);
}

/*
	** 012345 670123 456701 234567	(...)
	** 01234567 01234567 01234567		(...)
*/

void		fill_trad_buff(char buffer[BUFF_SIZE_BASE64], char trad_buff[4],
	int *i, int r)
{
	int				size_buf;
	char			tmp;
	t_params_base64	params;

	init_decode_params(&params);
	if (trad_buff[3] != '\0')
	{
		ft_bzero(trad_buff, 4);
		(*i)++;
	}
	size_buf = ft_strlen(trad_buff);
	while (*i < r && size_buf < 4)
	{
		tmp = params.alphabet[(int)buffer[*i]];
		if (tmp != -1 || buffer[*i] == '=')
		{
			trad_buff[size_buf] = buffer[*i];
			size_buf++;
		}
		(*i)++;
	}
}

void		base64_decode_from_fd(int fd, int output_fd)
{
	t_params_base64	params;
	int				r;
	char			buffer[BUFF_SIZE_BASE64];
	char			trad_buff[4];
	int				i;

	init_decode_params(&params);
	ft_bzero(trad_buff, 4);
	while ((r = read(fd, buffer, BUFF_SIZE_BASE64)) > 0)
	{
		i = 0;
		while (i < r)
		{
			fill_trad_buff(buffer, trad_buff, &i, r);
			if (trad_buff[3] != '\0')
				decode_four_chars(trad_buff, &params, output_fd);
		}
	}
}
