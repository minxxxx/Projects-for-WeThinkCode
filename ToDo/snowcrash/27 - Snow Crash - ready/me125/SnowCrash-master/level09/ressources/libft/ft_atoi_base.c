/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 09:58:28 by dgalide           #+#    #+#             */
/*   Updated: 2016/10/05 10:49:13 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int				ft_atoi_base(char *str, int base)
{
	int nb;
	int j;
	int neg;
	int i;

	if (!str || base > 16 || base <= 0)
		return (-1);
	else
	{
		j = 0;
		neg = (str[0] == '-') ? 1 : 0;
		i = (int)ft_strlen(str);
		nb = 0;
	}
	while (--i >= neg)
	{
		nb += ((base > 10 && str[i] > 57) ? str[i] - 87 : str[i] - 48) *
			ft_power(base, j++);
	}
	return ((neg == 1) ? nb * -1 : nb * 1);
}
