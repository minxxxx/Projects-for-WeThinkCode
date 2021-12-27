/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemiy <artemiy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:00:48 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/04 00:43:20 by artemiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char    *ft_make_pointer(t_specifier *spec, va_list *ap)
{
	char				*address;
	char    			*tmp;
	unsigned long int	p;
	int					len;

	(void)spec;
	if (spec->precition == 0)
	{
		address = ft_strjoin("0x", "\0");
		return (address);
	}
	p = (unsigned long int)va_arg(*ap, void *);
	tmp = ft_ullitoa_base(p, "0123456789abcdef", 16);
	if (!tmp)
		return (NULL);
	len = (int)ft_strlen(tmp);
	if (spec->precition > len)
		tmp = ft_manage_pw(tmp, spec->precition, len);
	address = ft_strjoin("0x", tmp);
	free(tmp);
	if (!address)
		return (NULL);
	return (address);
}
