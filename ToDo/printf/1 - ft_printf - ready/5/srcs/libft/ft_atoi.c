/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:28:52 by thendric          #+#    #+#             */
/*   Updated: 2016/11/11 15:18:18 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		ans;
	int		i;
	int		neg;

	ans = 0;
	i = 0;
	neg = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			neg = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		ans = (ans * 10) + (str[i] - '0');
		i++;
	}
	return (ans * neg);
}
