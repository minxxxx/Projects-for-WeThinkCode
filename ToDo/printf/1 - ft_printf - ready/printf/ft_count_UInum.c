/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_UInum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 15:37:24 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/25 16:56:49 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_UInum(unsigned int num, int base)
{
	int		count;

	count = 0;
	if ((int)num < 0)
	{
		num = num * -1;
		count++;
	}
	while (num != 0)
	{
		num = num / base;
		count++;
	}
	return (count);
}
