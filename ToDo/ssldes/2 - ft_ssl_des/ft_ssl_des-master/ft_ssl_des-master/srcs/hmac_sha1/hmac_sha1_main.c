/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac_sha1_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:23 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:24 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

#define HASH_LEN 20
#define BLOCK_LEN 64

unsigned char	*fin_de_la_fonction(char *k_ipad, char *k_opad, int size,
	const void *str)
{
	uint32_t	*file;
	void		*tmp;

	file = malloc(BLOCK_LEN + size);
	ft_memcpy(file, k_ipad, BLOCK_LEN);
	ft_memcpy((void*)file + BLOCK_LEN, str, size);
	tmp = file;
	file = sha1_encode(file, BLOCK_LEN + size);
	free(tmp);
	tmp = file;
	file = malloc(BLOCK_LEN + HASH_LEN);
	ft_memcpy(file, k_opad, BLOCK_LEN);
	ft_memcpy((void*)file + BLOCK_LEN, tmp, HASH_LEN);
	free(tmp);
	tmp = file;
	file = sha1_encode(file, BLOCK_LEN + HASH_LEN);
	free(tmp);
	return ((void*)file);
}

unsigned char	*hmac_sha1_encode(const void *str, int size,
	const unsigned char *key, size_t keylen)
{
	char		k_ipad[BLOCK_LEN];
	char		k_opad[BLOCK_LEN];
	void		*tmp;

	tmp = NULL;
	if (keylen >= BLOCK_LEN)
	{
		tmp = sha1_encode(key, keylen);
		key = tmp;
		keylen = HASH_LEN;
	}
	fill_ipad_opad(keylen, k_ipad, k_opad, key);
	if (tmp)
		free(tmp);
	return (fin_de_la_fonction(k_ipad, k_opad, size, str));
}

static int		get_in_fd(t_opt *opt)
{
	int	ret;

	if (opt->flags & I_OPT)
	{
		if (!opt->i_option)
			return (-1);
		ret = open(opt->i_option, O_RDONLY);
	}
	else
		ret = 0;
	if (ret == -1)
		ft_putendl_fd("Error : Couldn't open input file or parse error", 2);
	return (ret);
}

static int		get_out_fd(t_opt *opt)
{
	int	ret;

	if (opt->flags & O_OPT)
	{
		if (!opt->o_option)
			ret = -1;
		ret = open(opt->o_option, O_RDONLY);
	}
	else
		ret = 1;
	if (ret == -1)
		ft_putendl_fd("Error : Couldn't open output file or parse error", 2);
	return (ret);
}

int				main_hmac_sha1(t_opt *opt)
{
	int				in_out_fd[2];
	char			*file;
	unsigned char	*hash;
	char			str[HASH_LEN * 2 + 1];
	int				r;

	if (!(opt->flags & K_OPT) || !opt->k_option)
	{
		ft_putendl_fd("Key needed", 2);
		return (0);
	}
	if ((in_out_fd[0] = get_in_fd(opt)) == -1)
		return (0);
	if ((in_out_fd[1] = get_out_fd(opt)) == -1)
		return (0);
	file = get_file(in_out_fd[0], &r);
	hash = hmac_sha1_encode(file, r, (void*)opt->k_option,
		ft_strlen(opt->k_option));
	bytes_to_char((void*)hash, str, HASH_LEN);
	ft_putendl_fd(str, in_out_fd[1]);
	free(file);
	free(hash);
	return (1);
}
