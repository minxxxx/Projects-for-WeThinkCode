/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_enc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:45 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:45 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

#define MASK 0x0000000F

static void	init_constants(uint32_t k[80], uint32_t h[5])
{
	int	i;

	i = 0;
	while (i < 80)
	{
		if (i < 20)
			k[i] = 0x5A827999;
		else if (i < 40)
			k[i] = 0x6ED9EBA1;
		else if (i < 60)
			k[i] = 0x8F1BBCDC;
		else if (i < 80)
			k[i] = 0xCA62C1D6;
		i++;
	}
	h[0] = 0x67452301;
	h[1] = 0xEFCDAB89;
	h[2] = 0x98BADCFE;
	h[3] = 0x10325476;
	h[4] = 0xC3D2E1F0;
}

static char	*sha_padding(const void *in, size_t original_len, size_t *size)
{
	char		*ret;

	(*size) = ((original_len / 64 + 1) * 64);
	if ((*size) - original_len <= 8)
		(*size) += 64;
	if (!(ret = malloc((*size) * sizeof(char))))
		return (NULL);
	ft_memcpy(ret, in, original_len);
	((uint8_t*)ret)[original_len] = 0x80;
	ft_bzero(ret + original_len + 1, (*size) - original_len - 8 - 1);
	*(uint64_t*)(ret + (*size) - 8) = end_conv_64(original_len << 3);
	return (ret);
}

void		fill_out(char out[41], uint32_t h[5])
{
	int	i;

	i = 0;
	h[0] = end_conv_32(h[0]);
	h[1] = end_conv_32(h[1]);
	h[2] = end_conv_32(h[2]);
	h[3] = end_conv_32(h[3]);
	h[4] = end_conv_32(h[4]);
	while (i < 20)
	{
		out[i * 2] = ((((char *)h)[i] & 0xf0) >> 4) + '0';
		out[i * 2] > '9' ? out[i * 2] = out[i * 2] - '9' - 1 + 'a' : 0;
		out[i * 2 + 1] = (((char *)h)[i] & 0xf) + '0';
		out[i * 2 + 1] > '9' ?
			out[i * 2 + 1] = out[i * 2 + 1] - '9' - 1 + 'a' : 0;
		i++;
	}
	out[40] = '\0';
}

uint32_t	*compute_sha1(void *in, size_t len)
{
	uint32_t			k[80];
	size_t				n;
	uint32_t			*h;

	h = (uint32_t*)malloc(5 * sizeof(uint32_t));
	init_constants(k, h);
	n = 0;
	while (n < len / 64)
	{
		compute_round(h, k, in + (n * 64));
		n++;
	}
	h[0] = end_conv_32(h[0]);
	h[1] = end_conv_32(h[1]);
	h[2] = end_conv_32(h[2]);
	h[3] = end_conv_32(h[3]);
	h[4] = end_conv_32(h[4]);
	free(in);
	return (h);
}

uint32_t	*sha1_encode(const void *in, size_t len)
{
	size_t	padded_size;
	void	*tmp;

	if (!(tmp = sha_padding(in, len, &padded_size)))
		return (NULL);
	return (compute_sha1(tmp, padded_size));
}
