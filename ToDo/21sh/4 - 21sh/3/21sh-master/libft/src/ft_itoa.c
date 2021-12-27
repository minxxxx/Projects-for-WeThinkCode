/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:18:08 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/08 18:40:00 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char		*ft_itoa(int n)
{
	int		i;
	int		nsave;
	char	*s;

	i = 0;
	if (n <= 0)
		i++;
	nsave = n;
	while (n != 0 && ++i)
		n = n / 10;
	s = ft_strnew(i);
	if (!s)
		return (NULL);
	if (nsave == 0)
		s[i - 1] = '0';
	while (nsave != 0)
	{
		s[i - 1] = ft_abs_value(nsave % 10) + 48;
		nsave = nsave / 10;
		i--;
	}
	if (!s[0])
		s[0] = '-';
	return (s);
}
