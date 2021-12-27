/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes_to_key_md5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:30:57 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:30:57 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static int	do_round(int i, uint8_t *buffer, uint8_t *rez,
	t_btk_md5_params *params)
{
	int		offset;
	size_t	size_buffer;

	offset = 0;
	if (i != 0)
	{
		offset = 16;
		ft_memcpy(buffer, rez + (i - 1) * 16, 16);
	}
	ft_memcpy(buffer + offset, params->data, params->data_len);
	if (params->salt != NULL)
	{
		ft_memcpy(buffer + offset + params->data_len, params->salt, 8);
		size_buffer = offset + params->data_len + 8;
	}
	else
		size_buffer = offset + params->data_len;
	if (!ft_md5(buffer, size_buffer, rez + i * 16))
	{
		free(rez);
		free(buffer);
		return (0);
	}
	return (1);
}

int			calculate_required_rounds(t_btk_md5_params *params)
{
	int		required_rounds;

	required_rounds = (params->key_len + params->iv_len) / (16);
	if ((size_t)required_rounds * 16 != params->key_len + params->iv_len)
		required_rounds++;
	return (required_rounds);
}

int			bytes_to_key_md5(t_btk_md5_params *params)
{
	uint8_t	*buffer;
	int		required_rounds;
	int		i;
	uint8_t	*rez;

	if (!(rez = malloc(params->key_len + params->iv_len)))
		return (0);
	if (!(buffer = malloc(16 + params->data_len + 8)))
	{
		free(rez);
		return (0);
	}
	required_rounds = calculate_required_rounds(params);
	i = 0;
	while (i < required_rounds)
	{
		if (!do_round(i, buffer, rez, params))
			return (0);
		i++;
	}
	ft_memcpy(params->key, rez, params->key_len);
	ft_memcpy((void*)params->iv, rez + params->key_len, params->iv_len);
	free(rez);
	free(buffer);
	return (1);
}
