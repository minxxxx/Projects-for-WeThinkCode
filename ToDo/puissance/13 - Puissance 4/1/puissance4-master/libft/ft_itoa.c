/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:01:15 by telain            #+#    #+#             */
/*   Updated: 2015/12/17 17:59:05 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*new;
	int		values[3];

	values[0] = n;
	values[1] = 0;
	values[2] = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		values[1] = 1;
		values[0] = -values[0];
		values[2]++;
	}
	while (n /= 10)
		values[2]++;
	if ((new = ft_strnew(values[2])) == NULL)
		return (NULL);
	while (values[2] >= values[1])
	{
		new[values[2]--] = (values[0] % 10) + 48;
		values[0] /= 10;
	}
	new[0] = (values[1] == 1 ? '-' : new[0]);
	return (new);
}
