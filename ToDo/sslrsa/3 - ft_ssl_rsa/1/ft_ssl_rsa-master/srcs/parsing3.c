/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:45:32 by jtranchi          #+#    #+#             */
/*   Updated: 2018/09/27 13:45:34 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

char		*padding_key(char *str)
{
	char *tmp;

	if (ft_strlen(str) > 16)
		str[16] = 0;
	else if (ft_strlen(str) < 16)
	{
		tmp = ft_strnew(16);
		ft_memcpy(tmp, "0000000000000000", 16);
		ft_memcpy(tmp, str, ft_strlen(str));
		return (tmp);
	}
	return (str);
}

void		push_arg_list(t_opt *opt, t_arg *arg)
{
	t_arg *tmp;

	arg->next = NULL;
	if (opt->arg == NULL)
		opt->arg = arg;
	else
	{
		tmp = opt->arg;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = arg;
	}
}
