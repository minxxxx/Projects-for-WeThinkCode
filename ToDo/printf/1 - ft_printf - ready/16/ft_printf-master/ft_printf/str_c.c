/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:34:06 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/13 18:34:11 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*str_c(char **p, va_list ap)
{
	char			modifier;
	char			*str;
	unsigned char	ch;

	modifier = 0;
	modif(*p, &modifier);
	str = NULL;
	if (modifier == 2 || modifier == 8)
		(*p) += 2;
	else if (modifier != 0)
		(*p)++;
	if (**p == 'c')
	{
		ch = (char)va_arg(ap, unsigned int);
		if (ch == 0)
			return (ft_strdup("\0"));
		str = (char*)malloc(sizeof(char) * 2);
		str[0] = ch;
		str[1] = '\0';
	}
	else if (modifier == 2 || modifier == 8)
		(*p) -= 2;
	else if (modifier != 0)
		(*p)--;
	return (str);
}

int		str_c_null(char flg, int width, char *str, char **p)
{
	int		numb;

	str = ft_width_c(str, flg, width);
	numb = ft_strlen(str) - 1;
	if (numb > 0)
		str[numb] = '\0';
	ft_putstr(str);
	write(1, "\0", 1);
	(*p)++;
	numb = (int)ft_strlen(str) + 1;
	ft_strdel(&str);
	return (numb);
}
