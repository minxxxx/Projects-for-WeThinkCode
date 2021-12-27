/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:00:09 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/13 17:27:35 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*get_list(t_flag *a)
{
	if (!(a = (t_flag*)malloc(sizeof(t_flag))))
		return (NULL);
	a->plus = 0;
	a->meno = 0;
	a->zero = 0;
	a->space = 0;
	a->hash = 0;
	a->numb = 0;
	a->prec = 0;
	a->val_prec = 0;
	a->p = 0;
	a->conv = 0;
	a->val_conv = 0;
	a->size = 0;
	a->val_size = 1;
	return (a);
}
