/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:57:09 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 17:57:10 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*str_ret(size_t numb, char *str, int i, char conv)
{
	while (numb)
	{
		if ((numb % 16) < 10)
			str[i--] = 48 + (numb % 16);
		else if (conv == 'x')
			str[i--] = 97 + ((numb % 16) - 10);
		else
			str[i--] = 65 + ((numb % 16) - 10);
		numb = numb / 16;
	}
	return (str);
}

char	*conv_x(va_list ap, char modifier, char conv)
{
	size_t		numb_unsigned;
	size_t		numb;
	char		*str;
	int			i;

	i = 0;
	numb_unsigned = casted_unsigned(modifier, ap);
	numb = numb_unsigned;
	while (numb_unsigned)
	{
		numb_unsigned = numb_unsigned / 16;
		i++;
	}
	if (numb == 0)
		return (ft_strdup("0"));
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	return (str_ret(numb, str, i, conv));
}
