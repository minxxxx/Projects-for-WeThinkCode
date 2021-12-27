/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 09:07:27 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 09:07:28 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"
#include "ft_ssl_md5.h"
#include "ft_ssl_sha256.h"

void		print_md_str2(t_md *data, unsigned char *name)
{
	if (*name == 0)
		ft_printf("");
	else
	{
		if (data->file == 1)
			ft_printf(" \"%s\"", name);
		else
			ft_printf(" %s", name);
	}
}

void		print_md_str(t_md *data, unsigned char *name, int md)
{
	char s[10];

	ft_bzero(&s[0], sizeof(char) * 10);
	if (md)
	{
		if (md == 1)
			ft_memcpy(&s[0], "SHA256", ft_strlen("SHA256"));
		else
			ft_memcpy(&s[0], "whirlpool", ft_strlen("whirlpool"));
	}
	else
		ft_memcpy(&s[0], "MD5", ft_strlen("MD5"));
	if (data->file == 1)
	{
		ft_printf("%s (\"%s\") = ", s, data->str);
	}
	else
	{
		ft_printf("%s (%s) = ", s, name);
	}
}

void		sha256init(t_sha256 *data)
{
	data->len[0] = 0;
	data->len[1] = 0;
	data->hash[0] = 0x6a09e667;
	data->hash[1] = 0xbb67ae85;
	data->hash[2] = 0x3c6ef372;
	data->hash[3] = 0xa54ff53a;
	data->hash[4] = 0x510e527f;
	data->hash[5] = 0x9b05688c;
	data->hash[6] = 0x1f83d9ab;
	data->hash[7] = 0x5be0cd19;
}

void		start_md(int argc, char **argv, int md)
{
	t_md	data;

	argc -= 2;
	argv += 2;
	ft_bzero(&data, sizeof(t_md));
	data.file = 1;
	if (argc)
		check_md_flags(argc, argv, &data, md);
	else
	{
		data.qfl = -1;
		data.pfl = 1;
		before_start_md("", &data, md);
	}
}

int			main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("usage: %s command [command opts] [command args]\n", argv[0]);
		return (1);
	}
	flag_parser(argc, argv, -1, 0);
	return (0);
}
