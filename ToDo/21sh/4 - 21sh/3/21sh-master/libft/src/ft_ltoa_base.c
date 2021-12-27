/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 19:33:09 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/31 23:27:01 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_count(long nb, int base)
{
	int	c;

	c = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		c++;
	while (nb != 0)
	{
		nb = nb / base;
		c++;
	}
	return (c);
}

char		*ft_ltoa_base(long nb, int base)
{
	int		c;
	long	tmp;
	char	*ret;

	tmp = 0;
	c = ft_count(nb, base);
	if (!(ret = (char *)malloc(sizeof(*ret) * (c + 1))))
		return (NULL);
	ret[c] = 0;
	if (nb == 0)
		ret[0] = '0';
	else if (nb < 0)
		ret[0] = '-';
	while (nb != 0)
	{
		c--;
		if ((tmp = nb % base) < 0)
			tmp = -tmp;
		if (tmp < 10)
			ret[c] = tmp + 48;
		else
			ret[c] = tmp + 55;
		nb = nb / base;
	}
	return (ret);
}
