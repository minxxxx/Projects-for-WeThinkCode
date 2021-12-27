/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:17:01 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/24 16:17:10 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_checklen(int nbr)
{
	int		len;

	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	if (nbr >= 0 && nbr <= 9)
		len++;
	return (len);
}

char		*ft_fill_array(int nbr, char *ret, int len, int s)
{
	int		i;
	int		tmp;

	if (s)
	{
		ret[0] = '-';
		nbr *= -1;
	}
	ret[len] = '\0';
	i = len - 1;
	while (i >= 0 + s)
	{
		if (nbr >= 10)
		{
			tmp = nbr % 10;
			ret[i] = tmp + '0';
			nbr /= 10;
		}
		else
			ret[i] = nbr + '0';
		i--;
	}
	return (ret);
}

char		*ft_intmax(void)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * (11 + 1))))
		return (NULL);
	ret = "-2147483648";
	return (ret);
}

char		*ft_itoa(int nbr)
{
	char	*ret;
	int		len;
	int		s;

	if (nbr == -2147483648)
		return ((ret = ft_intmax()));
	len = ft_checklen(nbr);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	s = 0;
	nbr < 0 ? (s = 1) : s;
	return ((ret = ft_fill_array(nbr, ret, len, s)));
}
