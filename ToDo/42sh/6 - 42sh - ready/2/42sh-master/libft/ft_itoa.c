/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:13:05 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:13:08 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Turns interger values to ascii values.
*/

static int				ft_len(long int nbr)
{
	int		len;

	if (nbr <= 0)
		len = 1;
	else
		len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char					*ft_itoa(int nbr)
{
	int			len;
	int			sign;
	char		*c;

	if (nbr < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_len(nbr);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (NULL);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(nbr % 10);
		nbr = ft_abs(nbr / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
