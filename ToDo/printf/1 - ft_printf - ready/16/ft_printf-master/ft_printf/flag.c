/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:19:59 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/28 15:20:02 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*flag_hash(char **p, char *str, int acc, char flg)
{
	char	*buff_ptr;

	buff_ptr = str;
	if (**p == 'x' && ((flg >> 3) & 1) && ft_strcmp("0", str) != 0 && acc != 0)
	{
		str = ft_strjoin("0x", str);
		ft_strdel(&buff_ptr);
	}
	else if (**p == 'X' && ((flg >> 3) & 1) && \
		ft_strcmp("0", str) != 0 && acc != 0)
	{
		str = ft_strjoin("0X", str);
		ft_strdel(&buff_ptr);
	}
	if ((**p == 'o' || **p == 'O') && ((flg >> 3) & 1) && str[0] != '0')
	{
		str = ft_strjoin("0", str);
		ft_strdel(&buff_ptr);
	}
	return (str);
}

char	*flag(char **p, char *str, int acc, char flg)
{
	char	*buff_ptr;

	if (str != NULL)
	{
		buff_ptr = str;
		str = flag_hash(p, str, acc, flg);
		if ((**p == 'd' || **p == 'i') && ((flg >> 1) & 1) && str[0] != '-')
		{
			str = ft_strjoin("+", str);
			ft_strdel(&buff_ptr);
		}
		else if ((**p == 'd' || **p == 'i') && \
			((flg >> 2) & 1) && str[0] != '-')
		{
			str = ft_strjoin(" ", str);
			ft_strdel(&buff_ptr);
		}
	}
	return (str);
}

char	*flag_ox(char **p, char *str, char flg)
{
	if (((flg >> 4) & 1) && **p == 'p')
		ft_swap_char(&str[1], ft_strchr(str, 'x'));
	if (((flg >> 4) & 1) && **p == 'x' && ((flg >> 3) & 1))
		ft_swap_char(&str[1], ft_strchr(str, 'x'));
	else if (((flg >> 4) & 1) && **p == 'X' && ((flg >> 3) & 1))
		ft_swap_char(&str[1], ft_strchr(str, 'X'));
	return (str);
}
