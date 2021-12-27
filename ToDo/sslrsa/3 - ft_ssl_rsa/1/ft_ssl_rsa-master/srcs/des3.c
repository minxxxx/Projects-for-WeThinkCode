/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:31:06 by jtranchi          #+#    #+#             */
/*   Updated: 2018/10/08 14:31:07 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

t_mem	*create_message(long ret)
{
	t_mem *tmp;

	tmp = (t_mem *)malloc(sizeof(t_mem));
	tmp->data = (unsigned char*)ft_strnew(8);
	tmp->data[0] = (ret >> 56) & 0xFF;
	tmp->data[1] = (ret >> 48) & 0xFF;
	tmp->data[2] = (ret >> 40) & 0xFF;
	tmp->data[3] = (ret >> 32) & 0xFF;
	tmp->data[4] = (ret >> 24) & 0xFF;
	tmp->data[5] = (ret >> 16) & 0xFF;
	tmp->data[6] = (ret >> 8) & 0xFF;
	tmp->data[7] = ret & 0xFF;
	tmp->len = 8;
	return (tmp);
}

long	permute(long to_permute, int32_t *tab, int length)
{
	int		i;
	long	tmp;
	long	save;

	tmp = 0;
	i = -1;
	while (++i < length)
	{
		save = 0;
		save |= ((to_permute >> (64 - tab[i])) & 0x1);
		tmp |= save << (63 - i);
	}
	tmp >>= 64 - length;
	if (length == 56)
		tmp &= 0xFFFFFFFFFFFFFF;
	if (length == 32)
		tmp &= 0xFFFFFFFF;
	return (tmp);
}

t_mem	*des_encode_boucle(t_opt *opt, t_mem *mem)
{
	long	save_message;
	long	ret;

	save_message = 0;
	ret = 0;
	save_message = ft_msg_to_long((char*)mem->data, mem->len);
	if (opt->hash == 4 && !opt->d)
		save_message ^= opt->vector;
	ret = generate_subkeys(save_message, opt);
	if (opt->hash == 4)
	{
		if (opt->d)
		{
			ret ^= opt->vector;
			opt->vector = save_message;
		}
		else
			opt->vector = ret;
	}
	return (create_message(ret));
}
