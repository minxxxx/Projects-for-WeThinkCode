/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:27:52 by jcamhi            #+#    #+#             */
/*   Updated: 2016/02/01 10:00:36 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		find_fin(const char *str, int i, t_arg *arg)
{
	int	j;

	while (is_flag(str[i]))
		i++;
	i = after_width(str, i);
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit((int)str[i]))
			i++;
	}
	j = 0;
	while (is_lm(str[i]) && j < 2)
		ft_increase(&i, &j);
	if (str[i] == '\0')
	{
		arg->fin = i - 1;
		return (0);
	}
	arg->conv = str[i];
	arg->fin = i;
	return (1);
}

int		find_flag(const char *str, int i, t_arg *arg)
{
	int j;

	i++;
	arg->flag = ft_alloc_str_with_char('\0');
	if (is_flag(str[i]))
	{
		j = 0;
		while (is_flag(str[i + j]) && i + j < arg->fin)
		{
			arg->flag = ft_strjoinaf12(arg->flag,
					ft_alloc_str_with_char(str[i + j]));
			j++;
		}
		return (1);
	}
	arg->flag[0] = '\0';
	return (0);
}

int		find_width(const char *str, int i, t_arg *arg, va_list list)
{
	int j;

	j = i + 1;
	if (str[j] == '*')
	{
		arg->width = va_arg(list, int);
		if (arg->width < 0)
		{
			arg->width *= -1;
			arg->flag = ft_strjoinaf1(arg->flag, "-");
		}
		return (1);
	}
	while (i < arg->fin && str[i] != '.')
	{
		if (ft_isdigit(str[i]) && !(str[i] == '0' && j == i))
		{
			arg->width = ft_atoi(str + i);
			return (1);
		}
		i++;
	}
	arg->width = -1;
	return (0);
}

int		find_prec(const char *str, int i, t_arg *arg)
{
	while (i < arg->fin)
	{
		if (str[i] == '.')
		{
			arg->prec = ft_atoi(str + i + 1);
			return (1);
		}
		i++;
	}
	arg->prec = -1;
	return (0);
}

int		find_lm(const char *str, int i, t_arg *arg)
{
	int tmp;

	i = arg->fin - 1;
	tmp = i;
	while (is_lm(str[i]))
		i--;
	if (tmp == i)
	{
		arg->lm[0] = '\0';
		return (0);
	}
	i++;
	tmp = 0;
	while (is_lm(str[i]) && tmp < 2)
	{
		arg->lm[tmp] = str[i];
		tmp++;
		i++;
	}
	arg->lm[tmp] = '\0';
	return (1);
}
