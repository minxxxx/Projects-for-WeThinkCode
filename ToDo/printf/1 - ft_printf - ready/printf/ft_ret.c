/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retTOcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:15:04 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/25 16:56:28 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_retstr(va_list param, char *str)
{
	unsigned	int		num;
	char				*str1;

	if (str[0] == 'u' || str[0] == 'U' || str[0] == 'x' || str[0] == 'X')
		num = va_arg(param, unsigned int);
	if (str[0] == 'o' || str[0] == 'O' || str[0] == 'D')
		num = va_arg(param, unsigned int);
	if (str[0] == 's')
		str1 = va_arg(param, char *);
	if (str[0] == 'x')
		str1 = ft_uni_convert(num, 16);
	if (str[0] == 'X')
		str1 = ft_UNI_CONVERT(num, 16);
	if (str[0] == 'o')
		str1 = ft_uni_convert(num, 8);
	if (str[0] == 'O')
		str1 = ft_UNI_CONVERT(num, 8);
	if (str[0] == 'D' || str[0] == 'U')
		str1 = ft_UNI_CONVERT(num, 10);
	if (str[0] == 'u')
		str1 = ft_uni_convert(num, 10);
	return (str1);
}

int		ft_retint(va_list param)
{
	int		num;

	num = va_arg(param, int);
	return (num);
}
