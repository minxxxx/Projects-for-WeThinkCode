/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:00:56 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 17:00:57 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ret_str(size_t numb, char *str, int i)
{
	while (numb)
	{
		str[i--] = 48 + (numb % 8);
		numb = numb / 8;
	}
	return (str);
}

char	*conv_o(va_list ap, char modifier, char conv)
{
	size_t		numb_unsigned;
	size_t		numb;
	char		*str;
	int			i;

	i = 0;
	if (conv == 'o')
		numb_unsigned = casted_unsigned(modifier, ap);
	else
		numb_unsigned = casted_unsigned_lu(modifier, ap);
	numb = numb_unsigned;
	while (numb_unsigned)
	{
		numb_unsigned = numb_unsigned / 8;
		i++;
	}
	if (numb == 0)
		return (ft_strdup("0"));
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i--] = '\0';
	return (ret_str(numb, str, i));
}
