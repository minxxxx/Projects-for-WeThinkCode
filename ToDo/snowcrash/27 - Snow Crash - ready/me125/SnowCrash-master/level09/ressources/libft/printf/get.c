/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 02:32:47 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/08 02:32:48 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int				get_precision(t_data *data, int *i)
{
	int		j;
	char	*tmp;

	*i += 1;
	j = *i;
	if (data->setting[*i] == '0' || ft_isdigit(data->setting[*i]) == 0)
	{
		data->precision_null = 1;
		return (0);
	}
	else
	{
		while (data->setting[*i] >= '0' && data->setting[*i] <= '9')
			(*i)++;
		(*i) -= 1;
		tmp = ft_strsub(data->setting, j, (*i - j) + 1);
		return (ft_atoi_del(&tmp));
	}
}

int						get_precision_len(t_data *data)
{
	char		*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = NULL;
	while (data->setting[i])
	{
		if (data->setting[i] == '.')
			data->precision = get_precision(data, &i);
		else if ((data->setting[i] >= '0' && data->setting[i] <= '9'))
		{
			j = i;
			while (data->setting[i] >= '0' && data->setting[i] <= '9')
				i++;
			tmp = ft_strsub(data->setting, j, (i - j));
			data->minimal_range = ft_atoi_del(&tmp);
			ft_memdel((void **)&tmp);
			i--;
		}
		i++;
	}
	return (0);
}
