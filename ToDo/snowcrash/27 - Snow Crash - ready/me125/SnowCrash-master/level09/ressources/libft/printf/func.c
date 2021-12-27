/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:09:37 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/21 15:09:39 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			generic_range_handler(t_data *data, char **s1)
{
	char	*tmp;
	int		n;

	n = data->minimal_range - ft_strlen((*s1));
	if (n > 0)
	{
		tmp = ft_memset(ft_strnew(n), ' ', n);
		if (data->flag.minus)
			(*s1) = ft_strjoin_free(s1, &tmp, 1, 1);
		else
		{
			if (data->flag.zero)
				tmp = ft_memset(tmp, '0', n);
			(*s1) = ft_strjoin_free(&tmp, s1, 1, 1);
		}
	}
}

int				ft_is_flag(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '0' || c == '#')
		return (1);
	else
		return (0);
}
