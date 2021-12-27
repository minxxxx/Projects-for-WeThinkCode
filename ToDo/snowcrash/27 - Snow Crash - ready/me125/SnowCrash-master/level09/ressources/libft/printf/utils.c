/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 00:43:31 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/05 11:09:51 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			check_setting(char *str, int i)
{
	int	j;
	int	k;

	j = 0;
	k = i;
	while (i > 0)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ' ||
			str[i] == '.' || str[i] == '#' || str[i] || str[i] == '%' ||
					(str[i] >= '0' && str[i] <= '9'))
			j++;
		i--;
	}
	return ((j == k) ? 1 : 0);
}

void		add_plus(char **str, t_data *data)
{
	char *tmp;

	tmp = NULL;
	if (*str[0] && *str[0] != '-' && data->flag.plus)
	{
		tmp = ft_strnew(1);
		tmp = ft_memset(tmp, '+', 1);
		*str = ft_strjoin_free(&tmp, str, 1, 1);
	}
}

void		sign_replace(char **s1, char **s2)
{
	if (*s1[0] == '+')
	{
		*s1[0] = '0';
		*s2[0] = '+';
	}
	else if (*s1[0] == '-')
	{
		*s1[0] = '0';
		*s2[0] = '-';
	}
}

void		add_diez(char **arg, int zero_bool)
{
	char	*str;

	str = NULL;
	if (*arg && !zero_bool)
	{
		str = ft_memset(ft_strnew(2), 'x', 2);
		str[0] = '0';
		*arg = ft_strjoin_free(&str, arg, 1, 1);
	}
}

void		replace_diez(char **arg)
{
	int i;

	i = 1;
	(*arg)[i] = 'x';
	while ((*arg) && (*arg)[++i])
	{
		if ((*arg)[i] == 'x')
			(*arg)[i] = '0';
	}
}
