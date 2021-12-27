/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:31:16 by jtranchi          #+#    #+#             */
/*   Updated: 2018/09/06 13:31:16 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int32_t g_des_pc2[56] = {
	14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
	23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
	41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
	44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
};

int32_t g_des_initial[64] = {
	58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7
};

int32_t g_des_final[64] = {
	40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25
};

int32_t g_des_permut[32] = {
	16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10,
	2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25
};

int32_t g_des_shift[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int32_t g_des_pc1[56] = {
	57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4
};

int32_t	g_des_expansion[56] = {
	32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9,
	8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1
};

long g_subkeys[17][3];

long	do_subkey(long right, int i)
{
	long	ret;

	ret = 0;
	ret = permute(right << 32, g_des_expansion, 48);
	ret = g_subkeys[i][2] ^ ret;
	ret = ft_function_s(ret);
	return (permute(ret << 32, g_des_permut, 32));
}

long	generate_subkeys(long message, t_opt *opt)
{
	long	ret;
	long	left;
	long	right;
	long	save_right;
	int		i;

	i = (!opt->d) ? (0) : (17);
	right = 0;
	left = 0;
	save_right = 0;
	create_subkeys(opt);
	ret = permute(message, g_des_initial, 64);
	left = (ret >> 32) & 0xFFFFFFFF;
	right = ret & 0xFFFFFFFF;
	while ((!opt->d) ? (++i <= 16) : (--i > 0))
	{
		save_right = right;
		ret = do_subkey(right, i);
		right = left ^ ret;
		left = save_right;
	}
	ret = ((right << 32) & 0xFFFFFFFF00000000) | (left & 0xFFFFFFFF);
	ret = permute(ret, g_des_final, 64);
	return (ret);
}

void	create_subkeys(t_opt *opt)
{
	int		i;
	long	ret;

	i = 0;
	(opt->key == -2) ? generate_key(opt) : 0;
	ret = permute(opt->key, g_des_pc1, 56);
	g_subkeys[i][0] = ret >> 28;
	g_subkeys[i][1] = ret & 0xFFFFFFF;
	while (++i <= 16)
	{
		g_subkeys[i][0] = ((g_subkeys[i - 1][0] << g_des_shift[i - 1]) |
		(g_subkeys[i - 1][0] >> (28 - g_des_shift[i - 1]))) & 0xFFFFFFF;
		g_subkeys[i][1] = ((g_subkeys[i - 1][1] << g_des_shift[i - 1]) |
		(g_subkeys[i - 1][1] >> (28 - g_des_shift[i - 1]))) & 0xFFFFFFF;
		g_subkeys[i][2] = permute(((g_subkeys[i][0] << 28) |
		g_subkeys[i][1]) << 8, g_des_pc2, 56) >> 8;
	}
}

t_mem	*des_encode(t_mem *mem, t_opt *opt)
{
	t_mem	*message;
	t_mem	*tmp;

	message = NULL;
	if (opt->hash == 4)
	{
		if (!opt->vector)
		{
			ft_putendl("iv missing");
			exit(-1);
		}
	}
	while (mem->len >= opt->d)
	{
		tmp = des_encode_boucle(opt, mem);
		message = ft_memjoin(message, tmp);
		mem->data += 8;
		mem->len -= 8;
	}
	return (message);
}

void	hash_des(t_mem *mem, t_opt *opt)
{
	int		size;

	size = 0;
	if (opt->d && opt->a)
		mem = base64_decode(mem);
	mem = des_encode(mem, opt);
	if (opt->a && !opt->d)
		hash_base64(mem, opt);
	else
	{
		size = mem->data[mem->len - 1];
		if (mem->data[mem->len - size] == size)
			mem->len -= size;
		write_fd(opt->fd, mem);
	}
}
