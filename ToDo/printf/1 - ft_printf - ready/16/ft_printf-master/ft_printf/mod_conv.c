/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:35:49 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 13:35:51 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_acc(char **p)
{
	int		acc;

	acc = 0;
	(*p)++;
	while (*(*p) >= '0' && *(*p) <= '9')
	{
		acc = acc * 10 + *(*p) - '0';
		(*p)++;
	}
	return (acc);
}

char	*str_check(char **p, int *acc, va_list ap, char *str)
{
	if (str == NULL)
		str = str_p(p, str, *acc, ap);
	if (str == NULL)
		str = str_s(p, *acc, ap);
	if (str == NULL)
		str = str_c(p, ap);
	if (str == NULL)
	{
		str = str_null(p);
		*acc = -5;
	}
	return (str);
}

char	*str_start(int *acc, char **p, char flg, va_list ap)
{
	char	*str;

	str = NULL;
	if (*(*p) == '.')
		*acc = ft_acc(p);
	str = str_diuox(p, str, *acc, ap);
	str = flag(p, str, *acc, flg);
	return (str);
}

int		str_end(char **p, char *str, char flg)
{
	int		numb;

	str = flag_ox(p, str, flg);
	numb = (int)ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	(*p)++;
	return (numb);
}

int		mod_conv(int width, char flg, char **p, va_list ap)
{
	int		acc;
	char	*str;
	int		numb;

	acc = -1;
	str = str_start(&acc, p, flg, ap);
	if (str == NULL && ((*(*p) == 'S') || (*(*p + 1) == 'S')\
	|| (*(*p + 2) == 'S') || ((*(*p) == 'l') && (*(*p + 1) == 's'))))
	{
		mod_ls(p);
		return (ret_unicode(ap, acc, width, flg));
	}
	numb = str_lc(p, flg, width, ap);
	if (numb != -1)
		return (numb);
	str = str_check(p, &acc, ap, str);
	if (*(*p) == 'c' && ft_strcmp("\0", str) == 0)
		return (str_c_null(flg, width, str, p));
	if (*(*p) != 'c' && str[0] != 0 && acc != -5)
		str = ft_width(str, flg, width, acc);
	else
		str = ft_width_c(str, flg, width);
	return (str_end(p, str, flg));
}
