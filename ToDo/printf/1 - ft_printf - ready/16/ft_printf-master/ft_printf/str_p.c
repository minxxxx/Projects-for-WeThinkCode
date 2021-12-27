/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:55:42 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/21 17:55:45 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*t_part(char *str, size_t numb, int acc, int i)
{
	str[i--] = '\0';
	while (numb)
	{
		if ((numb % 16) < 10)
			str[i--] = 48 + (numb % 16);
		else
			str[i--] = 97 + ((numb % 16) - 10);
		numb = numb / 16;
		acc--;
	}
	if (acc <= 0)
		str = ft_strjoin("0x", str);
	else
	{
		while (acc > 0)
		{
			str = ft_strjoin("0", str);
			acc--;
		}
		str = ft_strjoin("0x", str);
	}
	return (str);
}

char	*o_part(int acc)
{
	char		*str;

	str = ft_strdup("0x");
	while (acc > 0)
	{
		str = ft_strjoin(str, "0");
		acc--;
	}
	return (str);
}

char	*conv_p(va_list ap, int acc)
{
	size_t		numb;
	size_t		numb_unsigned;
	int			i;
	char		*str;
	char		*ptr;

	i = 0;
	numb = (unsigned long long int)va_arg(ap, void*);
	numb_unsigned = numb;
	while (numb_unsigned)
	{
		numb_unsigned = numb_unsigned / 16;
		i++;
	}
	if (numb == 0 && acc >= 0)
		return (o_part(acc));
	else if (numb == 0)
		return (ft_strdup("0x0"));
	str = (char*)malloc(sizeof(char) * (i + 1));
	ptr = str;
	if (!str)
		return (NULL);
	str = t_part(str, numb, acc, i);
	ft_strdel(&ptr);
	return (str);
}

char	*str_p(char **p, char *str, int acc, va_list ap)
{
	char	modifier;

	modifier = 0;
	modif(*p, &modifier);
	if (modifier == 2 || modifier == 8)
		(*p) += 2;
	else if (modifier != 0)
		(*p)++;
	if (**p == 'p')
		str = conv_p(ap, acc);
	else if (modifier == 2 || modifier == 8)
		(*p) -= 2;
	else if (modifier != 0)
		(*p)--;
	return (str);
}
