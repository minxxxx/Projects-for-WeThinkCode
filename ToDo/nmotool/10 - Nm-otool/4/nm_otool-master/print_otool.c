/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_otool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 02:54:43 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:21:42 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	print_otool_sec_head(t_otool_flags *flags)
{
	if (flags->text_sec || (!flags->text_sec && flags->data_sec))
	{
		ft_putstr(flags->file_name);
		ft_putendl(":");
	}
}
