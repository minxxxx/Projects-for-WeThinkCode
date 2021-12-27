/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_encoding_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:00 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:01 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void			do_xor(uint64_t *ret, uint64_t last_block, uint64_t *in,
	size_t n)
{
	if (n == 0)
		ret[n] ^= last_block;
	else
		ret[n] ^= in[n - 1];
}

void			*des_end(t_des *des, uint64_t *ret, size_t datalen,
	const uint8_t *data)
{
	if (des->encode == 0)
		remove_padding((void*)ret, &datalen, (uint8_t*)ret);
	if (des->to_base64 && des->encode == 1)
	{
		if (!des_print_result_b64(des, datalen, ret))
			return (NULL);
	}
	else
	{
		if (des->salted && des->encode == 1)
		{
			write(des->out_fd, "Salted__", 8);
			write(des->out_fd, des->salt, 8);
		}
		write(des->out_fd, ret, datalen);
	}
	free(ret);
	if (des->encode)
		free((void*)data);
	return (NULL);
}

uint64_t		*prepare_ks_and_ret(t_des *des, t_uint48 ks[16], size_t datalen)
{
	uint64_t *ret;

	compute_key_schedule(ks, *(uint64_t*)des->key);
	if (des->encode == 0)
		swap_ks(ks);
	if (!(ret = malloc(datalen * sizeof(char))))
	{
		ft_putendl_fd("Error : Could not allocate enough space.", 2);
		return (NULL);
	}
	return (ret);
}

const uint8_t	*prepare_data(t_des *des, const uint8_t *data, size_t *datalen)
{
	if (des->encode)
		data = pkcs5_padding(data, datalen, 8);
	else if ((*datalen / 8) * 8 != *datalen)
	{
		ft_putstr_fd("Error : The size of the data to decrypt", 2);
		ft_putendl_fd(" isn't a multiple 64 bit.", 2);
		return (NULL);
	}
	return (data);
}

int				des_print_result_b64(t_des *des, size_t datalen, uint64_t *ret)
{
	uint8_t	*temp;
	size_t	size;

	size = 0;
	if (des->salted && des->encode == 1)
		size = 16 + datalen;
	else
		size = datalen;
	if (!(temp = malloc(size)))
	{
		ft_putendl_fd("Error : Memory error (181).", 2);
		return (0);
	}
	if (size != datalen)
	{
		ft_memcpy(temp, "Salted__", 8);
		ft_memcpy(temp + 8, des->salt, 8);
		ft_memcpy(temp + 16, ret, datalen);
	}
	else
		ft_memcpy(temp, ret, datalen);
	base64_enc_from_buf_to_fd(temp, size, des->out_fd);
	free(temp);
	return (1);
}
