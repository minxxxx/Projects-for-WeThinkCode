/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managemdtps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 10:07:36 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 10:07:37 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include "ft_ssl_sha256.h"
#include "ft_ssl_whirlpool.h"
#define SHH (uint32_t)ft_strlen((char*)data->str)

int			start_md5a(char *argv, t_md *data)
{
	size_t	size;

	if (data->pfl == 1)
	{
		data->str = input_read(&size);
		data->pfl = -1;
		data->needfree = 1;
	}
	else if (data->file == 0)
	{
		if (open(argv, O_RDONLY) < 0)
		{
			ft_printf("./ft_ssl: %s : No such file or directory\n", argv);
			return (1);
		}
		data->str = readoutfile(argv, &size);
		data->needfree = 1;
	}
	else
		data->str = (UC*)argv;
	return (0);
}

void		start_md5b(t_md *data, unsigned char *name, int md)
{
	if (data->rfl == 0 && (data->qfl == 0 || data->qfl == -1))
	{
		if (data->pfl == -1 || data->qfl == -1)
		{
			if (data->rfl == 0 && data->qfl == -1)
				data->pfl = -2;
			else
				ft_printf("%s", data->str);
			data->pfl = -2;
		}
		else if (data->qfl == -1)
		{
			data->qfl = 0;
			data->pfl = -2;
		}
		else
			print_md_str(data, name, md);
	}
	else if (data->rfl == 1 && data->pfl == -1 &&
		data->s == 0 && data->howuse == 0)
	{
		ft_printf("%s", data->str);
	}
}

void		start_md5(char *argv, t_md *data, int md)
{
	UC		*name;
	t_md5	md5data;
	UC		checksum[16];
	int		i;

	i = -1;
	if (start_md5a(argv, data))
		return ;
	name = (UC*)argv;
	md5init(&md5data);
	md5update(&md5data, data->str, ft_strlen((char*)data->str));
	md5final(checksum, &md5data);
	start_md5b(data, name, md);
	while (++i < 16)
		ft_printf("%02x", (unsigned int)checksum[i]);
	if (data->rfl == 1 && data->qfl == 0)
		print_md_str2(data, name);
	ft_printf("\n");
	data->howuse++;
	if (data->needfree)
	{
		free(data->str);
		data->str = NULL;
		data->needfree = 0;
	}
}

void		start_sha256(char *argv, t_md *data, int md)
{
	UC			*name;
	t_sha256	context;
	uint8_t		checksum[32];
	int			i;

	i = -1;
	if (start_md5a(argv, data))
		return ;
	name = (UC*)argv;
	sha256init(&context);
	sha256hash(&context, (uint8_t*)data->str, SHH);
	sha256done(&context, checksum, context.len[0] & 63, 0);
	start_md5b(data, name, md);
	while (++i < 32)
		ft_printf("%02x", checksum[i]);
	if (data->rfl == 1 && data->qfl == 0)
		print_md_str2(data, name);
	ft_printf("\n");
	data->howuse++;
	if (data->needfree)
	{
		free(data->str);
		data->str = NULL;
		data->needfree = 0;
	}
}

void		start_whirlpool(char *argv, t_md *data, int md)
{
	UC		*name;
	UC		checksum[64];
	int		i;
	t_wh	twh;

	i = -1;
	if (start_md5a(argv, data))
		return ;
	name = (UC*)argv;
	ft_bzero(&twh, sizeof(t_wh));
	whupdate(&twh, data->str, ft_strlen((char*)data->str));
	whfinal(&twh, (uint8_t*)checksum);
	start_md5b(data, name, md);
	while (++i < 64)
		ft_printf("%02x", checksum[i]);
	if (data->rfl == 1 && data->qfl == 0)
		print_md_str2(data, name);
	ft_printf("\n");
	data->howuse++;
	if (data->needfree)
	{
		free(data->str);
		data->str = NULL;
		data->needfree = 0;
	}
}
