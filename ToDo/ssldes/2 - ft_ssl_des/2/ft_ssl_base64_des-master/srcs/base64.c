/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:03:08 by jtranchi          #+#    #+#             */
/*   Updated: 2018/09/04 11:03:13 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	base64_encode(t_mem *mem, t_opt *opt)
{
	int i;
	int tmp;

	i = 0;
	while (i < (mem->len - (mem->len % 3)))
	{
		tmp = 0;
		tmp = (mem->data[i] << 16) | (mem->data[i + 1] << 8) |
		(mem->data[i + 2]);
		print_base64_encode(opt, tmp, 0);
		i += 3;
	}
	tmp = 0;
	if (mem->len % 3 == 1)
	{
		tmp = mem->data[i] << 4;
		print_base64_encode(opt, tmp, 1);
	}
	if (mem->len % 3 == 2)
	{
		tmp = (mem->data[i] << 10) | (mem->data[i + 1] << 2);
		print_base64_encode(opt, tmp, 2);
	}
	ft_putchar_fd('\n', opt->fd);
}

t_mem	*clean_string(t_mem *mem)
{
	int		i;
	int		j;
	t_mem	*tmp;

	tmp = (t_mem*)malloc(sizeof(t_mem));
	tmp->data = (unsigned char*)ft_strnew(mem->len);
	tmp->len = 0;
	i = 0;
	j = 0;
	while (i < mem->len)
	{
		if (mem->data[i] != '\n' && mem->data[i] != ' ' &&
		mem->data[i] != '\t' && mem->data[i] != '=')
		{
			tmp->len++;
			tmp->data[j++] = mem->data[i];
		}
		i++;
	}
	ft_free_mem(mem);
	return (tmp);
}

t_mem	*base64_decode(t_mem *mem)
{
	int		i;
	int		len;
	t_mem	*tmp;

	tmp = NULL;
	i = 0;
	mem = clean_string(mem);
	len = mem->len - (mem->len % 4);
	if (mem->data[mem->len - 1] == '=')
		len -= 4;
	while (i < len)
	{
		tmp = ft_memjoin(tmp, print_base64_decode(mem, i, 0));
		i += 4;
	}
	if (mem->len % 4 == 2)
		tmp = ft_memjoin(tmp, print_base64_decode(mem, i, 2));
	else if (mem->len % 4 == 3)
		tmp = ft_memjoin(tmp, print_base64_decode(mem, i, 1));
	return (tmp);
}

void	hash_base64(t_mem *mem, t_opt *opt)
{
	t_mem *ret;

	ret = NULL;
	if (!opt->d)
		base64_encode(mem, opt);
	else
	{
		ret = base64_decode(mem);
		write_fd(opt->fd, ret);
	}
}
