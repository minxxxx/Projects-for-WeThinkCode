/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbkdf2_hmac_sha1_main.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:42 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:43 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

#define HLEN 20

static void				deuxieme_partie(int iter, unsigned char **blocks)
{
	int	j;
	int	i;

	i = 1;
	while (i < iter)
	{
		j = 0;
		while (j < HLEN / 4)
		{
			((uint32_t*)blocks[0])[j] ^= ((uint32_t*)blocks[i])[j];
			j += 1;
		}
		free(blocks[i]);
		i++;
	}
}

static void				premiere_iteration(t_pbkdf2_params *p,
	int cur, unsigned char **blocks)
{
	void	*first_buffer;

	first_buffer = malloc(p->salt_len + 4);
	ft_memcpy(first_buffer, p->salt, p->salt_len);
	*(uint32_t*)(first_buffer + p->salt_len) =
		end_conv_32((uint32_t)cur);
	blocks[0] = (unsigned char*)hmac_sha1_encode(first_buffer,
		p->salt_len + 4, p->password, p->pass_len);
	free(first_buffer);
}

static unsigned char	*f(t_pbkdf2_params *p, int cur)
{
	int				i;
	unsigned char	**blocks;
	unsigned char	*ret;

	blocks = malloc(sizeof(unsigned char *) * p->iter);
	i = 1;
	while (i <= p->iter)
	{
		if (i == 1)
			premiere_iteration(p, cur, blocks);
		else
			blocks[i - 1] = hmac_sha1_encode(blocks[i - 2], HLEN,
				p->password, p->pass_len);
		i++;
	}
	deuxieme_partie(p->iter, blocks);
	ret = blocks[0];
	free(blocks);
	return (ret);
}

int						pbkdf2_hmac_sha1(t_pbkdf2_params *params)
{
	int				l;
	int				r;
	int				i;
	char			*out;
	unsigned char	*tmp;

	out = malloc(sizeof(char) * params->dklen + 1);
	l = (int)ceil(params->dklen / (double)HLEN);
	r = params->dklen - (l - 1) * HLEN;
	i = 1;
	while (i <= l)
	{
		tmp = f(params, i);
		ft_memcpy(out + (i - 1) * HLEN, tmp, (i == l ? r : HLEN));
		free(tmp);
		i++;
	}
	ft_memcpy(params->out, out, params->dklen);
	free(out);
	return (1);
}
