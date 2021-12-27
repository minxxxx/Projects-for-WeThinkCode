/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 00:47:58 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 11:04:17 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_s(va_list arg, t_flag **para, int *size)
{
	char	*str;
	char	*temp;

	str = va_arg(arg, char *);
	if ((*para)->prec != 0 && (*para)->prec_val < (int)ft_strlen(str))
		str = ft_strsub(str, 0, (*para)->prec_val);
	if ((*para)->wid != 0 && (*para)->wid > (int)ft_strlen(str))
	{
		temp = ft_strnew((*para)->wid - ft_strlen(str));
		if ((*para)->zero == 1 && (*para)->minus == 0)
			ft_memset(temp, '0', (*para)->wid - ft_strlen(str));
		else
			ft_memset(temp, ' ', (*para)->wid - ft_strlen(str));
		if ((*para)->minus == 1)
			str = ft_strjoin(str, temp);
		else
			str = ft_strjoin(temp, str);
	}
	ft_putstr(str);
	*size = *size + ft_strlen(str);
}
