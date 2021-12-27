/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:34:29 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/29 14:11:30 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	ft_free_mem(t_mem *mem)
{
	free(mem->data);
	free(mem);
}

t_mem	*ft_memjoin(t_mem *dest, t_mem *src)
{
	t_mem *ret;

	ret = (t_mem *)malloc(sizeof(t_mem));
	if (!dest)
	{
		ret->data = (unsigned char *)ft_strnew(src->len);
		ft_memcpy(ret->data, src->data, src->len);
		ret->len = src->len;
		return (ret);
	}
	ret->len = dest->len + src->len;
	ret->data = (unsigned char *)ft_strnew(ret->len);
	ft_memcpy((void*)ret->data, dest->data, dest->len);
	ft_memcpy((void*)&ret->data[dest->len], src->data, src->len);
	ft_free_mem(dest);
	return (ret);
}

t_mem	*read_fd(int fd)
{
	t_mem	*mem;
	t_mem	*buf;

	mem = NULL;
	buf = (t_mem *)malloc(sizeof(t_mem));
	buf->data = (unsigned char *)ft_strnew(BUFFER + 1);
	buf->len = 0;
	while ((buf->len = read(fd, buf->data, BUFFER)))
	{
		mem = ft_memjoin(mem, buf);
		ft_bzero(buf->data, buf->len);
		if (buf->len <= 0)
			break ;
		buf->len = 0;
	}
	if (!mem)
	{
		free(buf->data);
		buf->data = (unsigned char *)ft_strdup("\0");
		return (buf);
	}
	ft_free_mem(buf);
	return (mem);
}

void	write_fd(int fd, t_mem *mem)
{
	int i;

	i = -1;
	while (++i * BUFFER < mem->len)
	{
		if (mem->len - (i * BUFFER) < 1024)
			write(fd, &mem->data[i * BUFFER], mem->len - (i * BUFFER));
		else
			write(fd, &mem->data[i * BUFFER], BUFFER);
	}
}

int		print_usage(char *str)
{
	ft_putstr("usage: ");
	ft_putstr(str);
	ft_putendl(" [hash] [command options] [command arguments]");
	return (-1);
}
