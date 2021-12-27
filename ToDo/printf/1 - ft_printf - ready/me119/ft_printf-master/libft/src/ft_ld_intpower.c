/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_intpower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:14:49 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/08 23:27:49 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_ld_intpower(long double nb, long double power)
{
	long double i;
	long double num;

	num = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	i = 1;
	while (i++ < power)
		num *= nb;
	return (num);
}
