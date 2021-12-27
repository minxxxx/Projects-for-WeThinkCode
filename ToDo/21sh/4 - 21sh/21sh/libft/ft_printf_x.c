/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:18:12 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 15:37:55 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_process_x(va_list arg, t_flag **para,  int *size)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(arg, unsigned int);
	str = ft_itoa_base(nbr, 16);
	if ((*para)->prec == 1)
		ft_printf_nbr_precision(&str, &(*para), 0);
	if ((*para)->hash == 1)
		str = ft_strjoin("0x", str);
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
