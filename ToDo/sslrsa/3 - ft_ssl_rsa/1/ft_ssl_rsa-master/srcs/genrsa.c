/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genrsa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:38:31 by jtranchi          #+#    #+#             */
/*   Updated: 2018/10/10 15:38:32 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		genrsa(t_opt *opt)
{
	char buf[2048];

	t_mem *mem;

	mem = NULL;
	int fd = open("/dev/urandom", O_RDONLY);

	read(fd, buf, 2048);
	mem = (t_mem*)malloc(sizeof(t_mem));
	mem->data = (unsigned char*)ft_strnew(2048);
	mem->len = 2048;
	ft_memcpy(mem->data, buf, 2048);
	base64_encode(mem, opt);
	return (0);
}