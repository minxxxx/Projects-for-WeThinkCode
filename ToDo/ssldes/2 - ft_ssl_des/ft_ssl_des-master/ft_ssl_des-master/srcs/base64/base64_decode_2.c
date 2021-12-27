/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64_decode_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:30:52 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:34:05 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#define BUFF_SIZE_BASE64 48

/*
** Returns the content of the file opened on fd decoded as base64,
**  placed in buf.
** If buf is NULL, This function uses malloc to allocate one, and return
**  its size.
** The returned buf then has to be free'd.
** If a buf is provided, it must be able to countain at least the size of
**  the decoded output (input_size * 3 / 4).
*/

static uint8_t	*init_buf(int fd)
{
	struct stat	buf_stat;
	uint8_t		*buf;

	if (fstat(fd, &buf_stat) == -1)
		return (NULL);
	if (!(buf = malloc(buf_stat.st_size)))
	{
		ft_putendl_fd("Error : Memory error.", 2);
		return (NULL);
	}
	return (buf);
}

static void		no_equal_sign(char enc_buff[4], t_params_base64 *params,
	uint8_t *buf, int *j)
{
	enc_buff[0] = params->alphabet[(int)enc_buff[0]];
	enc_buff[1] = params->alphabet[(int)enc_buff[1]];
	enc_buff[2] = params->alphabet[(int)enc_buff[2]];
	enc_buff[3] = params->alphabet[(int)enc_buff[3]];
	buf[*j] = (enc_buff[0] << 2) | ((enc_buff[1] & 48) >> 4);
	buf[*j + 1] = ((enc_buff[1] & 15) << 4) | ((enc_buff[2] & 60) >> 2);
	buf[*j + 2] = ((enc_buff[2] & 3) << 6) | ((enc_buff[3]));
	(*j) += 3;
}

void			decode_n_store_four_chars(char enc_buff[4],
	t_params_base64 *params, uint8_t *buf, int *j)
{
	if (enc_buff[2] == '=')
	{
		enc_buff[0] = params->alphabet[(int)enc_buff[0]];
		enc_buff[1] = params->alphabet[(int)enc_buff[1]];
		buf[*j] = (enc_buff[0] << 2) | ((enc_buff[1] & 48) >> 4);
		(*j)++;
	}
	else if (enc_buff[3] == '=')
	{
		enc_buff[0] = params->alphabet[(int)enc_buff[0]];
		enc_buff[1] = params->alphabet[(int)enc_buff[1]];
		enc_buff[2] = params->alphabet[(int)enc_buff[2]];
		buf[*j] = (enc_buff[0] << 2) | ((enc_buff[1] & 48) >> 4);
		buf[*j + 1] = ((enc_buff[1] & 15) << 4) | ((enc_buff[2] & 60) >> 2);
		(*j) += 2;
	}
	else
		no_equal_sign(enc_buff, params, buf, j);
	ft_bzero(enc_buff, 4);
}

static int		inside_loop(int r, char *buffer, char trad_buff[4],
	uint8_t *buf)
{
	int				i;
	t_params_base64	params;
	int				j;

	j = 0;
	init_decode_params(&params);
	i = 0;
	while (i < r)
	{
		fill_trad_buff(buffer, trad_buff, &i, r);
		if (trad_buff[3] != '\0')
			decode_n_store_four_chars(trad_buff, &params, buf, &j);
	}
	return (j);
}

uint8_t			*base64_dec_to_buff_from_fd(int fd, uint8_t *buf,
	size_t *buf_size)
{
	t_params_base64	params;
	char			trad_buff[4];
	int				r;
	char			buffer[BUFF_SIZE_BASE64];
	int				j;

	if (!buf && !(buf = init_buf(fd)))
		return (NULL);
	init_decode_params(&params);
	ft_bzero(trad_buff, 4);
	(*buf_size) = 0;
	j = 0;
	while ((r = read(fd, buffer, BUFF_SIZE_BASE64)) > 0)
		j += inside_loop(r, buffer, trad_buff, buf);
	*buf_size = j;
	return (buf);
}
