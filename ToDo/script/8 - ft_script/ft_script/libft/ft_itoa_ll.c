/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 11:13:59 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/04 11:14:35 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int	ft_nb_digit(long long n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa_ll(long long n)
{
	int		nb_digit;
	char	*str;

	nb_digit = ft_nb_digit(n);
	str = ft_strnew(nb_digit);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	nb_digit--;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (nb_digit >= 0)
	{
		if (str[nb_digit] == '-')
			return (str);
		str[nb_digit] = (n % 10) + 48;
		n = n / 10;
		nb_digit--;
	}
	return (str);
}
