/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:37:57 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 12:45:08 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_nbr_precision(char **str, t_flag **para, int check)
{
	int		size;
	char	*temp;

	size = (*para)->prec_val - ft_strlen(*str);
	if ((*str)[0] == '-')
		check = 1;
	if (check == 1)
		size++;
	if ((*para)->prec_val > (int)ft_strlen(*str))
	{
		temp = ft_strnew(size);
		ft_memset(temp, '0', size);
		if (check == 1)
			*str = ft_strjoin(temp, &(*str)[1]);
		else
			*str= ft_strjoin(temp, *str);
		if (check == 1)
			*str = ft_strjoin("-", *str);
		ft_memdel((void **)&temp);
	}
}

void	ft_process_d(va_list arg, t_flag **para, int *size)
{
	int		nbr;
	char	*str;

	nbr = va_arg(arg, int);
	str = ft_itoa_base(nbr, 10);
	if ((*para)->prec != 0)
		ft_printf_nbr_precision(&str, &(*para), 0);
	if ((*para)->plus == 1 && nbr >= 0)
		str = ft_strjoin("+", str);
	if ((*para)->space == 1 && (*para)->plus == 0 && nbr >= 0)
		str = ft_strjoin(" ", str);
	if ((*para)->zero == 1 && (*para)->prec == 0 && (*para)->minus == 0)
		ft_printf_nbr_zero(&str, &(*para));
	else if ((*para)->minus == 1)
		ft_printf_nbr_minus(&str, &(*para));
	else if ((*para)->wid > 0)
		ft_printf_nbr_wid(&str, &(*para));
	ft_putstr(str);
	*size = *size + ft_strlen(str);
	ft_memdel((void **)&str);
}
