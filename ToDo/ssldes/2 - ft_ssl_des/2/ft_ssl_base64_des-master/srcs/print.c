/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 09:54:09 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/28 17:33:57 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

char g_base64[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
	'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
	'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
	'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5',
	'6', '7', '8', '9', '+', '/'};

void	print_output_md5(t_mem *mem, t_opt *opt)
{
	uint8_t			*p;
	int				i;
	int				y;
	char			*tmp;

	i = -1;
	(!opt->stdin && !opt->r && !opt->q) ? (write_prefix(opt, opt->arg)) : 0;
	while (++i < 4)
	{
		y = -1;
		p = (uint8_t *)&mem->h[i];
		while (++y < 4)
		{
			tmp = ft_itoa_base((int)p[y], 16);
			if (ft_strlen(tmp) == 1)
				ft_putchar('0');
			ft_putstr(tmp);
			ft_strdel(&tmp);
		}
	}
	(!opt->stdin && opt->r && !opt->q) ? (write_suffix(opt->arg)) : 0;
	ft_putchar('\n');
}

void	print_output_sha256(t_mem *mem, t_opt *opt)
{
	unsigned int	*p;
	int				i;
	int				y;
	char			*tmp;

	(!opt->stdin && !opt->r && !opt->q) ? (write_prefix(opt, opt->arg)) : 0;
	i = -1;
	while (++i < 8)
	{
		p = (unsigned int *)&mem->h[i];
		tmp = ft_itoa_base((uintmax_t)mem->h[i], 16);
		y = ft_strlen(tmp);
		while (y++ < 8)
			ft_putchar('0');
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}
	(!opt->stdin && opt->r && !opt->q) ? (write_suffix(opt->arg)) : 0;
	ft_putchar('\n');
}

void	print_base64_encode(t_opt *opt, int value, int which)
{
	if (which == 0)
	{
		ft_putchar_fd(g_base64[(value >> 18) & 0x3F], opt->fd);
		ft_putchar_fd(g_base64[(value >> 12) & 0x3F], opt->fd);
		ft_putchar_fd(g_base64[(value >> 6) & 0x3F], opt->fd);
		ft_putchar_fd(g_base64[value & 0x3F], opt->fd);
	}
	if (which == 1)
	{
		ft_putchar_fd(g_base64[(value >> 6) & 0x3F], opt->fd);
		ft_putchar_fd(g_base64[value & 0x3F], opt->fd);
		ft_putchar_fd('=', opt->fd);
		ft_putchar_fd('=', opt->fd);
	}
	if (which == 2)
	{
		ft_putchar_fd(g_base64[(value >> 12) & 0x3F], opt->fd);
		ft_putchar_fd(g_base64[(value >> 6) & 0x3F], opt->fd);
		ft_putchar_fd(g_base64[value & 0x3F], opt->fd);
		ft_putchar_fd('=', opt->fd);
	}
}

int		get_value(char c)
{
	int i;

	i = -1;
	while (++i < 64)
	{
		if (g_base64[i] == c)
			return (i);
	}
	return (-1);
}

t_mem	*print_base64_decode(t_mem *mem, int i, int which)
{
	t_mem *tmp;

	tmp = (t_mem *)malloc(sizeof(t_mem));
	tmp->data = (unsigned char*)ft_strnew(3);
	tmp->data[0] = (get_value(mem->data[i]) << 2) |
	(get_value(mem->data[i + 1]) >> 4);
	tmp->len = 3 - which;
	if (which == 0)
	{
		tmp->data[1] = (get_value(mem->data[i + 1]) << 4) |
		(get_value(mem->data[i + 2]) >> 2);
		tmp->data[2] = (get_value(mem->data[i + 2]) << 6) |
		(get_value(mem->data[i + 3]));
	}
	if (which == 2)
		tmp->data[1] = (get_value(mem->data[i + 1]) & 0xF);
	if (which == 1)
	{
		tmp->data[0] = (get_value(mem->data[i]) << 2) |
		(get_value(mem->data[i + 1]) >> 4);
		tmp->data[1] = (get_value(mem->data[i + 1]) << 4) |
		(get_value(mem->data[i + 2]) >> 2);
		tmp->data[2] = (get_value(mem->data[i + 2]) << 6);
	}
	return (tmp);
}
