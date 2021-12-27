/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:10:08 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 01:48:07 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		*ft_init_flags(void)
{
	t_flag	*param;

	if ((param = (t_flag *)malloc(sizeof(param))) == NULL)
		ft_error(1, "param");
	param->hash = 0;
	param->zero = 0;
	param->minus = 0;
	param->plus = 0;
	param->space = 0;
	param->hh = 0;
	param->h = 0;
	param->ll = 0;
	param->l = 0;
	param->j = 0;
	param->z = 0;
	param->wid = 0;
	param->prec = 0;
	param->prec_val = 0;
	param->len = 0;
	param->c = '\0';
	return (param);
}
