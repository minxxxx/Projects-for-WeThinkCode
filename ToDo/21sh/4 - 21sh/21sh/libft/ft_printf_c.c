/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 12:52:53 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 13:52:29 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_c(va_list arg, t_flag **para, int *size)
{
	char	*str;
	char	*temp;
	int		c;

	c = va_arg(arg, int);
	str = ft_strdup((char *)&c);
	if ((*para)->wid > (int)ft_strlen(str))
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
		ft_memdel((void **)&temp);
	}
	ft_putstr(str);
	*size = *size + ft_strlen(str);
	ft_memdel((void **)&str);
}
