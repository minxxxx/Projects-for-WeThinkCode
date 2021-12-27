/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:12:56 by jcamhi            #+#    #+#             */
/*   Updated: 2016/01/18 22:49:48 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*handle_flag_2(t_arg *arg, char *ret)
{
	if (ft_strchr(arg->flag, '#') && (arg->conv == 'o' || arg->conv == 'O')
			&& !ft_strequ(ret, "0"))
		if ((int)ft_strlen(ret) + 1 > arg->prec)
			arg->prec = ft_strlen(ret) + 1;
	return (ret);
}

char	*handle_flag(t_arg *arg, char *ret)
{
	if (ft_strchr(arg->flag, '#'))
	{
		if (arg->conv == 'x' && !ft_strequ(ret, "0") &&
				!(arg->prec == 0 && ret[0] == '\0'))
			ret = ft_strjoinaf2("0x", ret);
		else if (arg->conv == 'X' && !ft_strequ(ret, "0") &&
				!(arg->prec == 0 && ret[0] == '\0'))
			ret = ft_strjoinaf2("0X", ret);
	}
	ret = handle_flag_2(arg, ret);
	if (ft_strchr(arg->flag, '+'))
	{
		if (arg->conv == 'd' || arg->conv == 'i' || arg->conv == 'D')
			if (ret[0] != '-')
				ret = ft_strjoinaf2("+", ret);
	}
	if (ft_strchr(arg->flag, ' ') && !ft_strchr(arg->flag, '+'))
	{
		if (arg->conv == 'd' || arg->conv == 'i' || arg->conv == 'D')
		{
			if (ret[0] != '-')
				ret = ft_strjoinaf2(" ", ret);
		}
	}
	return (ret);
}
