/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:34:42 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 13:34:45 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*diu(va_list ap, char modifier, char conv)
{
	long long int	numb_signed;
	size_t			numb_unsigned;
	char			*str;

	if (conv == 'd' || conv == 'i')
	{
		numb_signed = casted_signed(modifier, ap);
		str = ft_itoa_long(numb_signed);
	}
	else if (conv == 'D')
	{
		numb_signed = casted_signed_ld(modifier, ap);
		str = ft_itoa_long(numb_signed);
	}
	else if (conv == 'U')
		numb_unsigned = casted_unsigned_lu(modifier, ap);
	else
		numb_unsigned = casted_unsigned(modifier, ap);
	if (conv == 'u' || conv == 'U')
		str = ft_itoa_size_t(numb_unsigned);
	return (str);
}
