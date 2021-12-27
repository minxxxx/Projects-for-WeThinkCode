/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:34:02 by jtranchi          #+#    #+#             */
/*   Updated: 2018/09/06 11:34:02 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void		opt_init(t_opt *opt)
{
	opt->p = 0;
	opt->q = 0;
	opt->r = 0;
	opt->s = 0;
	opt->d = 0;
	opt->i = 0;
	opt->a = 0;
	opt->o = 0;
	opt->v = 0;
	opt->output = NULL;
	opt->stdin = 1;
	opt->arg = NULL;
	opt->fd = 1;
	opt->k = 0;
	opt->key = -2;
	opt->pass = 0;
	opt->salt = 0;
	opt->vector = 0;
}

void		init_mem(t_mem *mem)
{
	mem->h[0] = 0x6a09e667;
	mem->h[1] = 0xbb67ae85;
	mem->h[2] = 0x3c6ef372;
	mem->h[3] = 0xa54ff53a;
	mem->h[4] = 0x510e527f;
	mem->h[5] = 0x9b05688c;
	mem->h[6] = 0x1f83d9ab;
	mem->h[7] = 0x5be0cd19;
}

void		set_flags(t_opt *opt, char c)
{
	(c == 'p') ? (opt->p = 1) : 0;
	(c == 'a') ? (opt->a = 1) : 0;
	(c == 'q') ? (opt->q = 1) : 0;
	(c == 'r') ? (opt->r = 1) : 0;
	(c == 'd') ? (opt->d = 1) : 0;
	(c == 'i') ? (opt->i = 1) : 0;
	(c == 'o') ? (opt->o = 1) : 0;
	(c == 's') ? (opt->s = 1) : 0;
	(c == 'k') ? (opt->k = 1) : 0;
	(c == 'v') ? (opt->v = 1) : 0;
}

void		open_fd(t_opt *opt)
{
	if ((opt->fd = open(opt->output, O_WRONLY | O_CREAT | O_TRUNC, 0755)) == -1)
	{
		ft_putstr("ft_ssl: error opening file: ");
		ft_putendl(opt->output);
		exit(-1);
	}
}

int			get_hash_index(char *hash)
{
	int i;

	i = -1;
	while (HASH[++i])
	{
		if (ft_strequ(HASH[i], hash))
			return (i);
	}
	return (-1);
}
