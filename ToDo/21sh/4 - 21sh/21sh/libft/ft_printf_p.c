/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 13:39:43 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 15:14:10 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_ptr_precision(char **str, t_flag **para)
{
	char	*temp;

	if ((*para)->prec_val > (int)ft_strlen(*str))
	{
		temp = ft_strnew((*para)->prec_val - ft_strlen(*str));
		ft_memset(temp, '0', (*para)->prec_val - ft_strlen(*str));
		*str = ft_strjoin(temp, *str);
		ft_memdel((void **)&temp);
	}
}

void	ft_process_p(va_list arg, t_flag **para, int *size)
{
	void	*ptr;
	char	*str;
	char	*temp;

	ptr = va_arg(arg, void *);
	str = ft_strjoin("7fff", ft_itoa_base((unsigned int)&(*ptr), 16));
	if ((*para)->prec == 1 && (*para)->prec_val > (int)ft_strlen(str))
		ft_printf_ptr_precision(&str, &(*para));
	str = ft_strjoin("0x", str);
	if ((*para)->wid > (int)ft_strlen(str))
	{
		temp = ft_strnew((*para)->wid - ft_strlen(str));
		if ((*para)->zero == 1 && (*para)->minus == 0 && (*para)->prec == 0)
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
